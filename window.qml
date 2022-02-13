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
        color.r: 0
        color.g: 0
        color.b: 1
        //border.color: "black"
        //border.width: 5
        //radius: 10

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

        onChangeColor:
        {
            ball.color.r = r;
            ball.color.g = g;
            ball.color.b = b;
        }
    }

    Component.onCompleted:
    {
        view_.aquireBoundaries(ball.x,ball.y,displayWindow.width,displayWindow.height);
        view_.startSimulation();
    }
}


