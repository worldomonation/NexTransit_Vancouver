#include <bb/cascades/Application>
#include <bb/cascades/Control>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Page>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/DropDown>

#include "rsslisting.hpp"
#include "applicationui.hpp"

using namespace ::bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
	Application app(argc, argv);

	RSSListing rssListing;

    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(&app);
    qml->setContextProperty("_rssListing", &rssListing);
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    Application::instance() -> setScene(root);

    return Application::exec();
}

//Q_DECL_EXPORT int main(int argc, char **argv)
//{
//	Application app(argc, argv);
//
//	// Create the business logic object
//	RSSListing rssListing;
//
//	QmlDocument *qml = QmlDocument::create("asset:///main.qml");
//		// Make the RSSListing object available to the UI as context property
//		qml->setContextProperty("_rssListing", &rssListing);
//		Page *appPage = qml->createRootObject<Page>();
//		if (appPage) {
//			Application::instance()->setScene(appPage);
//		}
//
//	return Application::exec();
//}
