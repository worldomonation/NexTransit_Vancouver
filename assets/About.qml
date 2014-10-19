import bb.cascades 1.0

Page {
    Container {
        background: Color.create("#262626")

		//Header Container
        Container {
            id: headerContainer
            layout: StackLayout {orientation: LayoutOrientation.LeftToRight}
            background: Color.create("#191919")
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Top
            leftPadding: 30
            rightPadding: 30

            //About Text Container
            Container {
                layout: StackLayout {orientation: LayoutOrientation.LeftToRight}
                topPadding: 20
                bottomPadding: 20
                leftPadding: 20
                rightPadding: 20
//                background: Color.create("#111111")
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Fill

                Label {
                    textStyle.color: Color.White
                    textStyle.fontSize: FontSize.XLarge
                    textStyle.fontWeight: FontWeight.W500
                    textStyle.fontSizeValue: 4.0
                    text: "About"
                }
            }
            //Version Text Container
            Container {
                layout: StackLayout {orientation: LayoutOrientation.LeftToRight}
                topPadding: 20
                bottomPadding: 26
                leftPadding: 20
//                background: Color.create("#242424")
                horizontalAlignment: HorizontalAlignment.Right
                verticalAlignment: VerticalAlignment.Bottom
                
                Label {
                    textStyle.color: Color.White
                    textStyle.fontSize: FontSize.Small
                    textStyle.fontWeight: FontWeight.W500
                    textStyle.fontSizeValue: 4.0
                    text: "v1.0.0.0"
                    verticalAlignment: VerticalAlignment.Center
                }
            }
        }
        
        Container {
            
        }
    }
}
