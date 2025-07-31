import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls

Window {
    width: 600
    height: 400
    visible: true
    color: "whitesmoke"

    FontLoader {
        id: blocks3x3Font
        source: "qrc:/AppWithCustomFont/fonts/blocks-3x3-monospaced.ttf"
        onStatusChanged: {
            if (status == FontLoader.Ready) {
                console.log("blocks-3x3-monospaced loaded successfully");
            } else if (status == FontLoader.Error) {
                console.log("Error loading blocks-3x3-monospaced font");
            }
        }
    }

    ColumnLayout{
        anchors.fill: parent
        Text {
            Layout.alignment: Qt.AlignHCenter

            text: "0123456789";

            // Using cystom font:
            font.family: blocks3x3Font.name
            font.pixelSize: 40
        }
        Text {
            Layout.alignment: Qt.AlignHCenter

            text: "abcdefg ... xyz";

            // Using cystom font:
            font.family: blocks3x3Font.name
            font.pixelSize: 40
        }
        Text {
            Layout.alignment: Qt.AlignHCenter

            text: "ABCDEFG ... XYZ";

            // Using cystom font:
            font.family: blocks3x3Font.name
            font.pixelSize: 40
        }
    }
}
