import QtQuick 2.0

Item {
    Rectangle
    {
        width: 240
        height: 240
        color: "black"

    }

    Rectangle
    {
        x:20
        y:20
        width: 200
        height: 200
        color: "transparent"
        Grid{
            anchors.fill: parent
            rows: 8; columns: 8;
            Repeater {
                    model: 64
                    Rectangle {
                        width: 23; height: 23
                        border.width: 1
                        color: "white"
                    }
                }
            }
    }
}
