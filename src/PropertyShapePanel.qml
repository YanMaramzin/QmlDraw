import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane {
    contentItem: ColumnLayout {
        GridLayout {
                columns: 2

                Label { text: "Цвет:" }
                // ColorPicker {
                //     selectedColor: canvas.selectedShape ? canvas.selectedShape.color : "transparent"
                //     onColorSelected: if (canvas.selectedShape) canvas.selectedShape.color = color
                // }
            }
    }
}
