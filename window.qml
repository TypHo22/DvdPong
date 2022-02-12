import QtQuick 2.0
import QtQuick.Window 2.2
import QtQml 2.15
Window
{
    id: displayWindow
    visible: true
    width: 500
    height: 500
    color: "white"

    Rectangle
    {
        x: displayWindow.width / 2
        y: displayWindow.height / 2
        width: 10
        height: 10
        color: "red"
        border.color: "black"
        border.width: 5
        radius: 10
    }

    Connections:
    {
//        target: view
//            onRandomSig:
//            {
//                console.log("Received new ball position")
//            }
    }
}

