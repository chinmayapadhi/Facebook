import Qt 4.7
import "../subviews"

Item {
    id: photosection;
    x:800; y:0
    width: 800; height: 425
    z: 2

    Item {
        id: dirview;

        TopMenu {
            id: phototopmenu;
            topic: "Photo albums"
            back: "Main Menu"
            submenu: false;
            z: 9000
        }

        states: [
        State {
            name: "dir"
            PropertyChanges { target: photoview; x: 800 }
            PropertyChanges { target: dirview; x: 0 }
        },
        State {
            name: "photos"
            PropertyChanges { target: dirview; x: -800 }
            PropertyChanges { target: photoview; x: 0 }
        }
        ]

        transitions: Transition {
            ParallelAnimation {
                NumberAnimation { properties: "x"; easing.type: Easing.InQuad; duration: 500 }
            }
        }

        Component {
            id: photodiritem

            Item {
                width: 800; height: 100
                id: photodirlist

                Text {
                    y: 20; x: 150
                    anchors.verticalCenter: parent.verticalCenter;
                    text: name; font.pointSize: 22; color: "green"
                }

                Rectangle {
                    x: 20
                    y: 100
                    width: 730
                    height: 2
                    color: "grey"
                    opacity: 0.5
                }

                MouseArea {
                    anchors.fill: parent;
                    onClicked: {
                        dirview.state = "photos"
                        connect.getPhotos(aid);
                    }
                }
            }
        }

        ListView {
            z: 101
            anchors.top: phototopmenu.bottom
            width: 800; height: 375
            orientation: "Vertical"
            anchors.topMargin: 60
            anchors.bottomMargin: 20
            keyNavigationWraps : true
            model: albumDirModel;
            delegate: photodiritem;
            highlight: highlight
            focus: true
        }
    }

    Item {
        id : photoview;
        x: 800; y:0

        TopMenu {
            id: subphototopmenu;
            topic: "Photos"
            back: "Albums"
            submenu: true;
            z: 10000000
        }

        GridView {
            x:146; y:50
            height : 375; width: 800
            cellWidth: 252; cellHeight: 182
            model: photosModel;
            focus: true
            delegate: Item {
                id: menuitem

                Image {
                    id: myIcon;
                    anchors.horizontalCenter: parent.horizontalCenter;
                    anchors.top: parent.bottom;
                    anchors.topMargin: 14
                    source: src_small;
                    fillMode: Image.PreserveAspectCrop;
                    clip: true
                    width: 250
                    height: 180

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            waittext.text = "Wait...";
                            fullscreen_img.source = src;
                            fullscreen.opacity = 1;
                            captionline.text = caption;
                            console.log(caption);
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: fullscreen;
        x: 0; y: 0; z: 100000
        width: 800; height: 425;
        opacity: 0;
        color: "black"

        Behavior on opacity {
            NumberAnimation { duration: 350; easing.type: Easing.Linear }
        }

        Text {
            id: waittext;
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignVCenter;
            width: parent.width
            height: parent.height
            text: "Wait..."
            color: "white"
            font.pointSize: 14
        }

        Image {
            id: fullscreen_img;
            anchors.fill: parent;
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    waittext.text = "";
                    fullscreen.opacity = 0;
                    fullscreen_img.source = "";
                }
            }
        }


        Text {
            id: captionline;
            horizontalAlignment: Text.AlignHCenter;
            verticalAlignment: Text.AlignBottom;
            width: parent.width
            height: { parent.height - 20 }
            color: "#eeeeee"
            font.pointSize: 12
        }
    }
}
