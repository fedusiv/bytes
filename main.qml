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

    }

    Map
    {
        x:400
        y:0
    }

    title: qsTr("Bytes")
}
