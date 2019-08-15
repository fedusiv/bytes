import QtQuick 2.0

Item {
    Rectangle
    {
        width: 240
        height: 240
        color: "black"

    }

    function change_cell_content(my_color, id)
    {
        grid_repeater.itemAt(id).change_color(my_color)
    }
    function change_cell(my_color, id)
    {
        grid_repeater.itemAt(id).color = my_color
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
                    id: grid_repeater
                    model: 64
                    Rectangle {
                        width: 23; height: width
                        border.width: 1
                        color: "white"
                        function change_color(new_color)
                        {
                            element.color = new_color
                        }
                        Rectangle {
                            id: element
                            anchors.centerIn: parent
                            width: parent.width*0.75
                            height: width
                            color: "transparent"
                        }
                    }
                }
            }
    }
}
