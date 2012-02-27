import Qt 4.7
import "../subviews"

Item {
    id: newsfeed
    x:800; y:0
    width: 800; height: 425
    z: 2
    property string commentid: "na"

    Item {
        id: newsview;

        states: [
        State {
            name: "news"
            PropertyChanges { target: commentview; x: 800 }
            PropertyChanges { target: newsview; x: 0 }
        },
        State {
            name: "comments"
            PropertyChanges { target: newsview; x: -800 }
            PropertyChanges { target: commentview; x: 0 }
        }
        ]

        transitions: Transition {
            ParallelAnimation {
                NumberAnimation { properties: "x"; easing.type: Easing.InQuad; duration: 500 }
            }
        }

        TopMenu {
            id: newsfeedtopmenu;
            topic: "News Feed"
            back: "Main Menu"
        }

        Component {
            id: feeditem
            Item {
                width: 800;
                height: { if (statustext.height < 55) { 120 } else { statustext.height + 65 } }
                id: menuitem

                Image {
                    id: myIcon; y: 40; x:50
                    source: pic
                    opacity: 1
                    scale: 1.3
                }

                Text {
                    visible: { if (name == "") { false } else {true} }
                    y: 20; x: 150
                    text: {name + ":";} font.pointSize: 15; color: "green"
                }

                Text {
                    y: 20; x: 650
                    anchors.right: parent.right
                    anchors.rightMargin: 60
                    text: {time} font.pointSize: 14; color: "brown"
                }

                Rectangle {
                    visible: { if (name == "" || comments == 0) { false } else {true} }

                    color: "steelblue";
                    y: 20;
                    height: 24
                    smooth: true;
                    width: 130
                    anchors.right: parent.right
                    anchors.rightMargin: 260
                    radius: 12

                    Text {
                        color: "white"
                        anchors.fill: parent;
                        horizontalAlignment: Text.AlignHCenter;
                        verticalAlignment: Text.AlignVCenter;
                        text: {if (comments == 1) { "1 comment" } else { comments + " comments"} }
                        font.pointSize: 13;
                    }
                }

                Text {
                    x: 725;
                    visible: { if (name == "") { false } else {true} }
                    verticalAlignment: Text.AlignVCenter;
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.topMargin: 40
                    text: ">"; font.pointSize: 22; color: "steelblue"
                }

                Text {
                    id: statustext;
                    y: 50; x: 170
                    width: 550
                    text: status; font.pointSize: 18;
                    wrapMode: Text.WordWrap
                }

//                Text {
//                    y: 125; x: 150; color: "blue"
//                    text: when; font.pointSize: 10
//                }

                Rectangle {
                    x: 20
                    anchors.top: menuitem.bottom;
                    anchors.topMargin: 4;
                    width: 730
                    height: 2
                    color: "grey"
                    opacity: 0.5
                }

                MouseArea {
                    anchors.fill: parent;
                    onClicked : {
                        connect.getComments(post_id);
                        newsfeed.commentid = post_id;
                        newsview.state = "comments"
                    }
                }
            }
        }

        ListView {
            z: 101
            anchors.top: newsfeedtopmenu.bottom
            width: 800; height: 340
            orientation: "Vertical"
            anchors.topMargin: 65
            keyNavigationWraps : true
            model: newsModel;
            delegate: feeditem
            highlight: highlight
            focus: true
        }
    }

    Item {
        id: commentview
        x: 800

        TopMenu {
            id: commentopmenu;
            topic: "Comments"
            back: "News Feed"
            submenu: true;
        }

        Component {
            id: commentcomponent
            Item {
                width: 800;
                height: { if (commenttext.height < 55) { 120 } else { commenttext.height + 65 } }
                id: commentitem

                Component.onCompleted: {
                    if (last)
                    {
                        commentbox.visible = true;
                    }
                }

                Image {
                    id: myIcon; y: 40; x:50
                    source: pic
                    opacity: 1
                    scale: 1.3
                }

                Text {
                    y: 20; x: 150
                    text: full_name;
                    font.pointSize: 12; color: "green"
                }

                Text {
                    id: commenttext;
                    y: 50; x: 170
                    width: 550
                    text: comment; font.pointSize: 18;
                    wrapMode: Text.WordWrap
                }

                Rectangle {
                    x: 20
                    anchors.top: commentitem.bottom;
                    anchors.topMargin: 4;
                    width: 730
                    height: 2
                    color: "grey"
                    opacity: 0.5
                }

                Item {
                    id: commentbox
                    visible: false;

                    Image {
                        y: 40; x:50
                        source: pic
                        opacity: 1
                        scale: 1.3
                    }

                    Text {
                        y: 20; x: 150
                        text: "You:"
                        font.pointSize: 12; color: "green"
                    }

                    Rectangle {
                        x: 170; y: 70
                        width: 400; height: 40;
                        color: "#660033"

                        Rectangle
                        {
                            anchors.fill: parent;
                            anchors.margins: 4;
                            color: "white";

                            TextInput {
                                id: newcomment;
                                anchors.fill: parent;
                                anchors.topMargin: 5
                                anchors.leftMargin: 8
                                font.pointSize: 14;
                            }
                        }
                    }

                    Rectangle {
                        x: 600; y: 70
                        width: 165; height: 40;
                        color: "#660033"

                        Rectangle
                        {
                            anchors.fill: parent;
                            anchors.margins: 4;
                            color: "#CC6699";

                            Text {
                                horizontalAlignment: Text.AlignHCenter;
                                verticalAlignment: Text.AlignVCenter;
                                width: parent.width
                                height: parent.height
                                text: "Send Comment"
                                font.pointSize: 14
                            }
                        }

                        MouseArea {
                            anchors.fill: parent;

                            onClicked: {
                                connect.sendComment(newsfeed.commentid, newcomment.text);
                                newcomment.text = "Status update sent!";
                            }
                        }
                    }
                }
            }
        }

        ListView {
            z: 101; x: 0; y: 75
            width: 800; height: 350
            anchors.bottomMargin: 30
            clip: true;
            orientation: "Vertical"
            anchors.topMargin: 50
            keyNavigationWraps : true
            model: commentModel;
            delegate: commentcomponent
            highlight: highlight
            focus: true
        }
    }
}
