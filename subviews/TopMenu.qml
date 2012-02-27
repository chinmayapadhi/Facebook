import Qt 4.7

Item {
    id: topmenu
    z: 100000
    property string topic: "Default"
    property string back: "Back"
    property bool submenu: false

    Rectangle {
        color : "#324F89"
        x: 0; y: 0;
        width: 800
        height: 75

        Text {
            x: 20;
            id: topmenutext;
            text: topmenu.topic
            color: "white"
            font.pointSize: 28
            verticalAlignment: Text.AlignVCenter;
            height: parent.height
        }

        Rectangle {
            color : "#223F79"
            x: 640; y: 10
            width: 150
            height: parent.height - 20;

            Rectangle {
                color : "#526FA9"
                x: 3; y: 3;
                width: parent.width - 3;
                height: parent.height - 3;

                Text {
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                    width: parent.width
                    height: parent.height
                    text: topmenu.back
                    font.pointSize: 18
                }
            }

            MouseArea {
                x: 0; y: 0; width: 800; height: 50; z: 20000000000000000
                onClicked: {

                    //TODO: Fix the mess!

                    if (topmenu.topic == "Photo albums")
                    {
                        console.log("coming:" + root.comingfrom);
                        if (root.comingfrom == "friends")
                        {
                            menu.state = "friends";
                        }
                        else
                        {
                            menu.state = "main";
                        }
                    }
                    else if (!topmenu.submenu)
                    {
                        menu.state = "main";
                    }
                    else
                    {
                        if (topmenu.topic == "Comments")
                        {
                            newsview.state = "news";
                        }
                        else
                        {
                            //doesn't scale
                            dirview.state = "dir";
                        }
                    }
                }
            }
        }
    }
}

