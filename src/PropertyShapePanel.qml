import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MyPainter 1.0

Pane {
    property var canvas

    contentItem: ColumnLayout {
        GridLayout {
            columns: 2

            Label { text: "Цвет:" }
            ColorPicker {
                selectedColor: canvas.selectedShape ? canvas.selectedShape.color : "transparent"
                onColorSelected: if (canvas.selectedShape) canvas.selectedShape.color = color
            }
        }
    }
    // Динамическая часть для разных фигур
    Loader {
        sourceComponent: {
            if (!canvas.selectedShape)
                return undefined

            switch(canvas.drawingType) {
            case CanvasItem.Rectangle: {
                console.log("CanvasItem.Rectangle")
                return rectEditor
            }
            case CanvasItem.Line: {
                console.log("CanvasItem.Line")
                return lineEditor
            }
            }
            return undefined
        }
    }

    Component {
        id: rectEditor

        GridLayout {
            columns: 2

            Label { text: "X:" }
            SpinBox {
                value: canvas.selectedShape.x
                onValueModified: canvas.selectedShape.x = value
                from: 0
                to: canvas.width
            }

            Label { text: "Y:" }
            SpinBox {
                value: canvas.selectedShape.y
                onValueModified: canvas.selectedShape.y = value
                from: 0
                to: canvas.height
            }

            Label { text: "Ширина:" }
            SpinBox {
                value: canvas.selectedShape.width
                onValueModified: canvas.selectedShape.width = value
                from: 1
                to: 1000
            }

            Label { text: "Высота:" }
            SpinBox {
                value: canvas.selectedShape.height
                onValueModified: canvas.selectedShape.height = value
                from: 1
                to: 1000
            }
        }
    }

    Component {
        id: lineEditor

        GridLayout {
            columns: 2

            Label { text: "X1:" }
            SpinBox {
                value: canvas.selectedShape.x
                onValueModified: canvas.selectedShape.x = value
                from: 0
                to: canvas.width
            }

            Label { text: "Y1:" }
            SpinBox {
                value: canvas.selectedShape.y
                onValueModified: canvas.selectedShape.y = value
                from: 0
                to: canvas.height
            }

            Label { text: "X2:" }
            SpinBox {
                value: canvas.selectedShape.x2
                onValueModified: canvas.selectedShape.x2 = value
                from: 0
                to: canvas.width
            }

            Label { text: "Y2:" }
            SpinBox {
                value: canvas.selectedShape.y2
                onValueModified: canvas.selectedShape.y2 = value
                from: 0
                to: canvas.height
            }
        }
    }
}
