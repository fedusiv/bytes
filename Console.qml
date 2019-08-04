import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Item {
    Rectangle
    {
        width: 400
        height: 480
        color: "grey"

        TextArea
        {
                style: TextAreaStyle {
                    textColor: "#333"
                    selectionColor: "steelblue"
                    selectedTextColor: "#eee"
                    backgroundColor: "black"
                }

            width: 380
            height: 430
            x: 10
            y: 10
            readOnly: true
        }

        TextField {
            style: TextFieldStyle {
                    textColor: "green"
                    background: Rectangle {
                        radius: 2
                        implicitWidth: 100
                        implicitHeight: 24
                        border.color: "#333"
                        border.width: 1
                        color: "black"

                    }
                }
            width: 380
            height: 25
            x : 10
            y : 447
        }

    }
}
