import Qt 4.7
import "views"
import "subviews"

Item {
    id: root

    width: 800
    height: 425

    property string comingfrom: "na" //not so nice, used for photos menu handling

    NewsfeedView {
        id: newspage
    }

    FriendView {
        id: friendspage
    }

    PhotoView {
        id: photospage
    }

    Image {
        id: image_bg
        source: "qrc:/images/fb_background_main_screen.PNG"
        x:0; y:0;
        width: 800; height: 668
    }

    Item {
        id: menu
        x:0; y:0;
        width: 800; height: 320

        ListModel {
            id: appModel
            ListElement { name: "News Feed"; icon: "qrc:/menu_icons/fb_menu_news.PNG"; active: true }
            ListElement { name: "Profile"; icon: "qrc:/menu_icons/fb_menu_profile.PNG"; active: false }
            ListElement { name: "Friends"; icon: "qrc:/menu_icons/fb_menu_friends.PNG"; active: true }
            ListElement { name: "Inbox"; icon: "qrc:/menu_icons/fb_menu_inbox.PNG"; active: false }
            ListElement { name: "Chat"; icon: "qrc:/menu_icons/fb_menu_chat.PNG"; active: false }
            ListElement { name: "Requests"; icon: "qrc:/menu_icons/fb_menu_requests.PNG"; active: false }
            ListElement { name: "Events"; icon: "qrc:/menu_icons/fb_menu_events.PNG"; active: false }
            ListElement { name: "Photos"; icon: "qrc:/menu_icons/fb_menu_photos.PNG"; active: true }
            ListElement { name: "Notes"; icon: "qrc:/menu_icons/fb_menu_notes.PNG"; active: false }
            ListElement { name: "Log Out"; icon: "qrc:/menu_icons/fb_menu_profile.PNG"; active: true }
        }

        TextInput {
            id: status_input;
            x:22; y: 57; z: 2
            text: "What's on your mind? (ascii characters only)"
            font.pointSize: 13
        }

        MouseArea {
           x: 500
           y: 40
           width: 300
           height: 100

           onClicked: {
               connect.updateStatus(status_input.text);
               status_input.text = "Status update sent! Clear this and write the next one.";
           }
        }

        Component {
            id: appDelegate
            Item {
                id: menuitem
                width: 160; height: 190


                states: [
                State {
                    name: "clicked"
                    PropertyChanges {
                        target: myIcon
                        opacity: 1
                    }
                    PropertyChanges {
                        target: myText
                        color: "steelblue"
                    }
                },
                State {
                    name: "normal"
                    PropertyChanges {
                        target: myIcon
                        opacity: 0.4
                    }
                    PropertyChanges {
                        target: myText
                        color: "steelblue";
                    }
                }
                ]

                Image {
                    id: myIcon;
                    anchors.horizontalCenter: parent.horizontalCenter;
                    source: icon;
                    opacity: { if (active == true) {1} else {0.2} }
                    scale: 1.4
                }

                Text {
                    id: myText
                    y: 90; anchors.horizontalCenter: parent.horizontalCenter;
                    text: name; font.pointSize: 18; font.weight: Font.DemiBold
                    color: { if (active == true) { "#009966" } else { "steelblue" } }
                    opacity: { if (active == true) {1} else {0.2} }
                }

                MouseArea {
                    anchors.fill: parent
                    onReleased: {
                        if (active == true)
                        {
                            menuitem.state = 'normal'
                        }
                    }

                    onClicked: {
                        if (active == true)
                        {
                            menuitem.state = 'clicked'
                        }

                        if (myText.text == "News Feed")
                        {
                            menu.state = "news";
                        }
                        else if (myText.text == "Friends")
                        {
                            menu.state = "friends";
                        }
                        else if (myText.text == 'Photos')
                        {
                            connect.getOwnAlbums();
                            root.comingfrom = "main";
                            menu.state = "photos";

                        }
                        else if (myText.text == 'Log Out')
                        {
                            connect.logout();
                        }
                    }
                }
            }
        }

        GridView {
            y: 130; x: 80
            height : 300; width: 700
            cellWidth: 160; cellHeight: 190
            anchors.bottomMargin: 20
            model: appModel; delegate: appDelegate
            focus: true
        }

        states : [
        State {
            name: "main"
            PropertyChanges { target: menu; x: 0 }
        } ,
        State {
            name: "news"
            PropertyChanges { target: menu; x: -800 }
            PropertyChanges { target: newspage; x: 0 }
        },
        State {
            name: "friends"
            PropertyChanges { target: menu; x: -800 }
            PropertyChanges { target: photospage; x: 800 }
            PropertyChanges { target: friendspage; x: 0 }
        },
        State {
            name: "photos"
            PropertyChanges { target: menu; x: -800 }
            PropertyChanges { target: photospage; x: 0 }
        },
        State {
            name: "friendphotos"
            PropertyChanges { target: friendspage; x: -800 }
            PropertyChanges { target: menu; x: -800 }
            PropertyChanges { target: photospage; x: 0 }
        }
        ]

        transitions: Transition {
            ParallelAnimation {
                NumberAnimation { properties: "x"; easing.type: Easing.InQuad; duration: 500 }
            }
        }

        Image {
            id: image_ribbon
            source: "images/fb_ribbon.PNG"
            x:0
            y:0
        }

        Image {
            id: image_search
            source: "images/fb_search.PNG"
            x:0
            y:46
            z: 0
        }

        Image {
            id: image_footer
            source: "images/fb_footer.PNG"
            x:0
            y:390
        }
    }
}




