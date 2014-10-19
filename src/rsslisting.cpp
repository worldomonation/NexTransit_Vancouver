/*
 * rsslisting.cpp
 *
 *  Created on: 2013/06/24
 *      Author: Edwin
 */

#include "rsslisting.hpp"
#include <bps/virtualkeyboard.h>
#include <QDir>
#include <bb/cascades/GroupDataModel>

/*
     Constructs an RSSListing object and connects the needed signals.
 */
RSSListing::RSSListing(QObject *parent)
: QObject(parent)
, m_url()
, m_active(false)
, m_currentReply(0)
{
	// Invoke the finished() method whenever the download job has been finished
	connect(&m_manager, SIGNAL(finished(QNetworkReply*)),
			this, SLOT(finished(QNetworkReply*)));
}

void RSSListing::showVirtualKeyboard() {
	virtualkeyboard_show();
}

/*
     Starts the network request and connects the needed signals
 */
void RSSListing::get(const QUrl &url)
{
	QNetworkRequest request(url);
	if (m_currentReply) {
		m_currentReply->disconnect(this);
		m_currentReply->deleteLater();
	}

	m_currentReply = m_manager.get(request);
	connect(m_currentReply, SIGNAL(readyRead()), this, SLOT(readyRead()));
	connect(m_currentReply, SIGNAL(metaDataChanged()), this, SLOT(metaDataChanged()));
	connect(m_currentReply, SIGNAL(error(QNetworkReply::NetworkError)),
			this, SLOT(error(QNetworkReply::NetworkError)));
}

/*
     Starts fetching data from a news source specified in m_url.

     The UI is made read only to prevent the user from modifying its
     contents during the fetch; this is only for cosmetic purposes.

     A URL is created with the raw contents of m_url and
     a get is initiated.
 */

void RSSListing::fetch()
{
	m_active = true;
	emit activeChanged();

	m_xml.clear();

	const QUrl url(m_url);
	get(url);
}

/*
     If we got a redirect response from the server, trigger a new download
     with the redirect URL.
 */
void RSSListing::metaDataChanged()
{
	const QUrl redirectionTarget = m_currentReply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
	if (redirectionTarget.isValid()) {
		get(redirectionTarget);
	}
}

/*
     Reads data received from the RDF source.

     We read all the available data, and pass it to the XML
     stream reader.
 */

void RSSListing::readyRead()
{
	const int statusCode = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	if (statusCode >= 200 && statusCode < 300) {
		const QByteArray data = m_currentReply->readAll();
		m_xml.addData(data);
	}
}

/*
     Finishes processing an HTTP request.

     If an error has occurred, the user interface is made available
     to the user for further input, allowing a new fetch to be
     started.

     If the HTTP get request has finished, we make the
     user interface available to the user for further input.
 */

void RSSListing::finished(QNetworkReply *reply)
{
	Q_UNUSED(reply);

	parseXml();

	m_active = false;
	emit activeChanged();
}

void RSSListing::setUrl(const QString &url)
{
	if (m_url == url)
		return;

	m_url = url;
	emit urlChanged();
}

QString RSSListing::url() const
{
	return m_url;
}

QString RSSListing::feeds() const
{
	return m_feeds;
}

bool RSSListing::active() const
{
	return m_active;
}

/*
     Parses the XML data and fill feeds string accordingly.
 */
void RSSListing::parseXml()
{
	m_feeds.clear();

	QString currentTag;
	QString leaveTime;
	QString destination;
	QString routeNumber;

	while (!m_xml.atEnd()) {
		m_xml.readNext();
		if (m_xml.isStartElement()) {
			currentTag = m_xml.name().toString();
		}
		else if (m_xml.isEndElement()) {
			if (m_xml.name() == "Schedule") {
				m_feeds.append(QString::fromLatin1("%1\n      %2\n\n").arg(routeNumber + " " + destination, leaveTime));
				destination.clear();
				leaveTime.clear();
			}
		}
		else if (m_xml.isCharacters() && !m_xml.isWhitespace()) {
			if (currentTag == "Destination") {
				destination += m_xml.text().toString();
			}
			else if (currentTag == "RouteNo") {
				routeNumber = m_xml.text().toString();
			}
			else if (currentTag == "ExpectedLeaveTime") {
				QString temp;
				temp = m_xml.text().toString();
				int index = temp.indexOf("m");
				if (index > 0) {
					temp.resize(index+1);
				}
				leaveTime += temp;
			}
		}
		else if (m_xml.hasError()) {
			m_feeds.append("There are no buses serving this stop for the next 5 hours." + m_xml.name().toString());
		}
	}
	emit feedsChanged();
}

void RSSListing::error(QNetworkReply::NetworkError)
{
	m_feeds = QLatin1String("error retrieving RSS feed");
	emit feedsChanged();

	m_currentReply->disconnect(this);
	m_currentReply->deleteLater();
	m_currentReply = 0;
}
