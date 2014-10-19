import bb.cascades 1.0

TabbedPane {
    id: tabPane
    showTabsOnActionBar: false

    Tab {
        title: "Lookup"
        imageSource: "asset:///ic_search.png"
        
        Page {
            //Enables keyboard popup on launch
            property variant appScene: Application.scene

            //Overall Container
            Container {
                layout: StackLayout {orientation: LayoutOrientation.TopToBottom}
                background: Color.create("#262626");

                //Header Container
                Container {
                    id: headerContainer
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    horizontalAlignment: HorizontalAlignment.Fill
                    verticalAlignment: VerticalAlignment.Top
                    background: Color.create("#191919")
                    leftPadding: 30
                    rightPadding: 30

                    //Welcome Text Container
                    Container {
                        id: welcomeTextContainer
                        topPadding: 15
                        bottomPadding: 20
                        leftPadding: 20

                        opacity: 0.93
                        Label {
                            text: "NexTransit Vancouver"

                            textStyle.color: Color.White
                            textStyle.fontSize: FontSize.XLarge
                            textStyle.fontWeight: FontWeight.W500
                            textStyle.fontSizeValue: 4.0
                        }
                    }
                }

                //Text/Button Container
                Container {
                    background: Color.create("#262626")
                    leftPadding: 50.0
                    rightPadding: 50.0
                    topPadding: 20
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }

                    // A standard TextField for the RSS url
                    TextField {
                        id: stopNumber
                        verticalAlignment: VerticalAlignment.Center
                        inputMode: TextFieldInputMode.Pin
                        hintText: "Stop Number"
                        input.submitKeyFocusBehavior: SubmitKeyFocusBehavior.Lose
                        textStyle.fontSize: FontSize.Medium
                        focusPolicy: FocusPolicy.KeyAndTouch
                        text: ""

                        input {
                            submitKey: SubmitKey.Search
                            onSubmitted: {
                                _rssListing.url = "http://api.translink.ca/rttiapi/v1/stops/" + stopNumber.text + "/estimates?count=3&timeframe=300&apikey=27uPH7Ummwe5W0s5CRrn";
                                _rssListing.fetch()
                            }
                        }
                    }

                    // Button to offer alternative way to search
                    Button {
                        horizontalAlignment: HorizontalAlignment.Center
                        verticalAlignment: VerticalAlignment.Center
                        leftMargin: 10
                        maxWidth: 10
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: -1
                        }
                        //Probably not necessary
                        enabled: ! _rssListing.active
                        imageSource: "Search.png"

                        // Fetch news items on click
                        onClicked: {
                            _rssListing.url = "http://api.translink.ca/rttiapi/v1/stops/" + stopNumber.text + "/estimates?count=3&timeframe=300&apikey=27uPH7Ummwe5W0s5CRrn";
                            _rssListing.fetch();
                        }
                    }
                }

				//Result Output Container
				Container {
				    id: resultContainer
				    horizontalAlignment: HorizontalAlignment.Fill
				    verticalAlignment: VerticalAlignment.Fill
				    
				    leftPadding: 50.0
				    rightPadding: 30.0
				    
				    // A standard TextArea for displaying items
				    TextArea {
				        editable: false
				        
				        text: _rssListing.feeds
//				        textStyle.fontSize: FontSize.Large
				        textStyle {
                            base: SystemDefaults.TextStyles.BodyText
                            color: Color.White
				        }
				    }
				}
            }

            //Detects QML loading and shows keyboard on launch
            onAppSceneChanged: {
                stopNumber.requestFocus()
                _rssListing.showVirtualKeyboard();
            }
        }
    }
    
//    Tab {
//        title: "Favorites"
//        
//        Page {
//            Container {
//                background: Color.create("#262626")
//                layout: StackLayout {
//                    orientation: LayoutOrientation.TopToBottom
//                }
//
//                Container {
//                    layout: StackLayout {
//                        orientation: LayoutOrientation.LeftToRight
//                    }
//                    horizontalAlignment: HorizontalAlignment.Fill
//                    verticalAlignment: VerticalAlignment.Top
//                    background: Color.create("#191919")
//                    leftPadding: 30
//                    rightPadding: 30
//
//                    //Welcome Text Container
//                    Container {
//                        topPadding: 15
//                        bottomPadding: 20
//                        leftPadding: 20
//
//                        opacity: 0.93
//                        Label {
//                            text: "Favorites"
//
//                            textStyle.color: Color.White
//                            textStyle.fontSize: FontSize.XLarge
//                            textStyle.fontWeight: FontWeight.W500
//                            textStyle.fontSizeValue: 4.0
//                        }
//                    }
//                }
//
//                Container {
//                    topPadding: 25
//                    leftPadding: 50
//                    rightPadding: 50
//                    TextField {
//                        id: favoriteStopNumber
//                        verticalAlignment: VerticalAlignment.Center
//                        inputMode: TextFieldInputMode.Pin
//                        hintText: "Stop Number"
//                        input.submitKeyFocusBehavior: SubmitKeyFocusBehavior.Next
//                        textStyle.fontSize: FontSize.Medium
//                        focusPolicy: FocusPolicy.KeyAndTouch
//                        text: ""
//
//                        input {
//                            submitKey: SubmitKey.Next
//                        }
//                    }
//                }
//                
//                Container {
//                    topPadding: 10
//                    leftPadding: 50
//                    rightPadding: 50
//                    TextField {
//                        id: favoriteDescription
//                        verticalAlignment: VerticalAlignment.Center
//                        inputMode: TextFieldInputMode.Pin
//                        hintText: "Optional: Description"
//                        input.submitKeyFocusBehavior: SubmitKeyFocusBehavior.Lose
//                        textStyle.fontSize: FontSize.Medium
//                        focusPolicy: FocusPolicy.KeyAndTouch
//                        text: ""
//
//                        input {
//                            submitKey: SubmitKey.Done
//                            
//                            onSubmitted: {
//                                function addFavorite() {
//                                    
//                                }
//                            }
//                        }
//                    }
//                }
//
//				Container {
//				    topPadding: 20
//                    leftPadding: 50
//                    rightPadding: 50
//                    DropDown {
//                        id: favorites
//                        title: "Saved Stops"
//                        enabled: true
//
//                        Option {
//
//                        }
//
//                    }
//                }
//            }
//        }
//    }
    
    Tab {
        title: "About"
        imageSource: "asset:///ic_info.png"
        
        Page {
            Container {
                background: Color.create("#262626")

                //Header Container
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    background: Color.create("#191919")
                    horizontalAlignment: HorizontalAlignment.Fill
                    verticalAlignment: VerticalAlignment.Top
                    leftPadding: 30
                    rightPadding: 30

                    //About Text Container
                    Container {
                        topPadding: 15
                        bottomPadding: 20
                        leftPadding: 20

                        opacity: 0.93
                        Label {
                            text: "About"

                            textStyle.color: Color.White
                            textStyle.fontSize: FontSize.XLarge
                            textStyle.fontWeight: FontWeight.W500
                            textStyle.fontSizeValue: 4.0
                        }
                    }
                }

                Container {
                    leftPadding: 50.0
                    rightPadding: 50.0
                    topPadding: 15
                    horizontalAlignment: HorizontalAlignment.Center
                    Label {
                        textStyle.color:Color.White
                	    textStyle.fontSize: FontSize.XLarge
                        textStyle {
                            base: SystemDefaults.TextStyles.BigText
                        }
                        text: "NexTransit Vancouver"
                	}
                }
                Container {
                    leftPadding: 50.0
                    rightPadding: 50.0
                    bottomPadding: 50
                    horizontalAlignment: HorizontalAlignment.Center
                    Label {
                        textStyle.color: Color.White
                        textStyle.fontSize: FontSize.Medium
                        horizontalAlignment: HorizontalAlignment.Center
                        text: "Version 1.0.1.003"
                    }
                }
                Container {
                    leftPadding: 50.0
                    rightPadding: 50.0
                    horizontalAlignment: HorizontalAlignment.Center
                    Label {
                        textStyle.color: Color.White
                        textStyle.fontSize: FontSize.Medium
                        horizontalAlignment: HorizontalAlignment.Center
                        text: "Copyright © 2013 Edwin Gao\nAll Rights Reserved"
                        multiline: true
                    }
                }
                Container {
                    leftPadding: 50.0
                    rightPadding: 50.0
                    topPadding: 50
                    horizontalAlignment: HorizontalAlignment.Center
                    Label {
                        textStyle.color: Color.White
                        textStyle.fontSize: FontSize.Medium
                        horizontalAlignment: HorizontalAlignment.Center
                        text: "Build date: 2013-07-07 00:04"
                    }
                }
            }
        }
    }
    onCreationCompleted: {
        
    }
}

