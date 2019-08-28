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
        Connections
        {
            target: gui
            onAppend_string :
            {
                console_.append_text(string)
            }
            onClean_terminal:
            {
                console_.clear_terminal()
            }
        }
    }

    Map
    {
        id : map_main
        x:400
        y:0
        Connections
        {
            target: gui
            onChange_cell_content :
            {
                map_main.change_cell_content(my_color, id)

            }
        }
        Rectangle
        {
            anchors.bottom: parent.bottom

        }
    }

    Map
    {
        id : map_debug
        x:400
        y:240
        Connections
        {
            target: gui
            onChange_cell_content_d :
            {
                map_debug.change_cell_content(my_color, id)
            }
        }
    }

    title: qsTr("Bytes")
}
