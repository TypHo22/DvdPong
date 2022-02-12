import QtQuick 2.0
import QtQuick.Window 2.2
import QtQml 2.15
Window
{
    id: displayWindow
    visible: true
    width: 500
    height: 500
    maximumHeight: 500
    maximumWidth: 500
    minimumHeight: 500
    minimumWidth: 500

    color: "white"


    Rectangle
    {
        id: ball
        x: displayWindow.width / 2
        y: displayWindow.height / 2
        width: 10
        height: 10
        color: "red"
        border.color: "black"
        border.width: 5
        radius: 10

        Component.onCompleted: view_.startSimulation();
    }

    Connections
    {
        target: view_

        onRandomSig:
        {
            console.log("received");
        }

        onUpdateBallPosition:
        {
            console.log("x:" + x)
            console.log("y:" + y)
            ball.x = x;
            ball.y = y;
        }
    }

    Component.onCompleted: view_.aquireBoundaries(ball.x,ball.y,displayWindow.width,displayWindow.height);
}


