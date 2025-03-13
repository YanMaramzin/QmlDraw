import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import MyPainter 1.0

Window {
    width: 800
    height: 600
    visible: true

    SplitView {
        anchors.fill: parent

        Pane {
            Layout.fillWidth: true
            Layout.fillHeight: true
            background: Rectangle {
                color: "gray"
            }

            contentItem: ColumnLayout {

                ColumnLayout {
                    Label {
                        text: "Фигуры:"
                        font.bold: true
                        padding: 10
                    }

                    ListView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        clip: true
                        model: canvas.shapesModel

                        delegate: Rectangle {
                            width: ListView.view.width
                            height: 40
                            color: selected ? "#e0e0ff" : "white"

                            property bool selected: model.shapePtr === canvas.selectedShape

                            Row {
                                spacing: 10
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.left: parent.left
                                anchors.leftMargin: 10

                                Rectangle {
                                    width: 20
                                    height: 20
                                    radius: 3
                                    color: model.color
                                    border.color: "#999"
                                }

                                Label {
                                    text: {
                                        switch(model.type) {
                                        case CanvasItem.Rectangle:
                                            return "Прямоугольник";
                                        case CanvasItem.Line:
                                            return "Линия";
                                        default:
                                            return "Фигура";
                                        }
                                    }
                                    verticalAlignment: Text.AlignVCenter
                                }
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    canvas.selectedShape = model.shapePtr
                                }
                            }
                        }
                    }

                    PropertyShapePanel {

                    }

                    Button {
                        text: "Rectangle"
                        onClicked: canvas.drawingType = CanvasItem.Rectangle
                    }

                    Button {
                        text: "Line"
                        onClicked: canvas.drawingType = CanvasItem.Line
                    }

                    // ColorPicker {
                    //     onColorSelected: canvas.drawingColor = color
                    // }

                    Button {
                        text: "Clear"
                        onClicked: canvas.clear()
                    }

                    Button {
                        text: "Remove selected"
                        onClicked: canvas.deleteSelected()
                    }

                    Button {
                        text: "Режим рисования"
                        onClicked: canvas.editMode = false
                    }

                    Button {
                        text: "Режим редактирования"
                        onClicked: {
                            canvas.editMode = true
                            canvas.drawingType = CanvasItem.None
                        }
                    }
                }
            }
        }

        CanvasItem {
            id: canvas
            Layout.fillWidth: true
            Layout.fillHeight: true
            SplitView.minimumWidth: 600
            drawingColor: "#2196F3"
            drawingType: CanvasItem.Rectangle
        }
    }
}
