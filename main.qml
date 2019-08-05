import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    Console
    {
        id : console_
    }

    Map
    {
        id : map_main
        x:400
        y:0
    }

    Map
    {
        id : map_debug
        x:400
        y:240
    }

    title: qsTr("Bytes")
}
