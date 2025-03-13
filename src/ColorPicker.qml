import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Item {
    id: root
    property color selectedColor: "black"
    signal colorSelected(color color)

    implicitWidth: colorGrid.width
    implicitHeight: colorGrid.height + customColorButton.height + 10

    Column {
        spacing: 5

        Grid {
            id: colorGrid
            columns: 5
            spacing: 2

            Repeater {
                model: [
                    "#FF0000", "#00FF00", "#0000FF",
                    "#FFFF00", "#FF00FF", "#00FFFF",
                    "#000000", "#666666", "#999999",
                    "#FFFFFF", "#FFA500", "#800080"
                ]

                Rectangle {
                    width: 30
                    height: 30
                    radius: 3
                    color: modelData
                    border.color: Qt.darker(color, 1.2)

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            root.selectedColor = color
                            root.colorSelected(color)
                        }
                    }
                }
            }
        }

        Button {
            id: customColorButton
            text: "Другой цвет"
            onClicked: colorDialog.open()

            ColorDialog {
                id: colorDialog
                title: "Выберите цвет"
                onAccepted: {
                    root.selectedColor = color
                    root.colorSelected(color)
                }
            }
        }
    }

    // Индикатор выбранного цвета
    Rectangle {
        anchors {
            top: parent.top
            right: parent.right
            margins: 5
        }
        width: 20
        height: 20
        color: root.selectedColor
        border.color: Qt.darker(color, 1.2)
        radius: 3
    }
}
