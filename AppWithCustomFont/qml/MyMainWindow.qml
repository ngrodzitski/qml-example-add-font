import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls

Window {
    width: 600
    height: 400
    visible: true
    color: "whitesmoke"

    ColumnLayout{
        anchors.fill: parent
        Text {
            Layout.alignment: Qt.AlignHCenter

            text: "0123456789";

            font.pixelSize: 40
        }
        Text {
            Layout.alignment: Qt.AlignHCenter

            text: "abcdefg ... xyz";

            font.pixelSize: 40
        }
        Text {
            Layout.alignment: Qt.AlignHCenter

            text: "ABCDEFG ... XYZ";

            font.pixelSize: 40
        }
    }
}
