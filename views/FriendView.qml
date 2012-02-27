import Qt 4.7
import "../subviews"

Item {
    id: friendfeed
    x:800; y:0
    width: 800; height: 425
    z: 1000

    TopMenu {
        id: friendtopmenu;
        topic: "Friends"
        back: "Main Menu"
    }

    Component {
        id: frienditem
        Item {
            width: 800; height: 100
            id: menuitem2

            Image {
                y: 30; x:30
                scale: 1.3
                source: pic
            }

            Text {
                y: 20; x: 150
                text: name; font.pointSize: 22; color: "green"
            }

            Text {
                x: 600
                anchors.verticalCenter: parent.verticalCenter
                text: "Photos >"; font.pointSize: 22; color: "steelblue"
            }

            Rectangle {
                x: 20
                width: 730
                height: 2
                color: "grey"
                opacity: 0.5
            }

            MouseArea {
                anchors.fill: parent;
                onClicked : {
                    connect.getAlbums(uid);
                    root.comingfrom = "friends";
                    menu.state = "friendphotos";
                }
            }
        }
    }

    ListView {
        z: 101        
        anchors.top: friendtopmenu.bottom
        width: 800; height: 350
        orientation: "Vertical"
        anchors.topMargin: 65
        anchors.bottomMargin: 20
        keyNavigationWraps : true
        model: friendModel;
        delegate: frienditem
        highlight: highlight
        focus: true
    }
}
