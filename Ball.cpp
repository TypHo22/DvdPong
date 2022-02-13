#include "Ball.h"
#include <QSoundEffect>

Ball::Ball() : ax_(20),ay_(200),vx_(500),vy_(400),x_(250),y_(250) //x,y positions taken from qml center of window
{

}

void Ball::update(float timeStep) //timeStep in seconds
{
    const float xOld = x_;
    const float yOld = y_;
    vx_ += ax_ * timeStep;
    vy_ += ay_ * timeStep;
    x_ += vx_ * timeStep;
    y_ += vy_ * timeStep;

    vectorX_ = x_ - xOld;
    vectorY_ = y_ - yOld;
}

void Ball::deflect()
{
    if(x_ <= 0.0)
        deflectOnLeft();
    else if(x_ >= 500.0)
        deflectOnRight();

    if(y_ <= 0.0)
        deflectOnTop();
    else if(y_ >= 500.0)
        deflectOnBottom();

    QSoundEffect effect;




}

float Ball::x() const
{
    return x_;
}

void Ball::setX(float newX)
{
    x_ = newX;
}

float Ball::y() const
{
    return y_;
}

void Ball::setY(float newY)
{
    y_ = newY;
}

void Ball::setAx(float newAx)
{
    ax_ = newAx;
}

void Ball::setAy(float newAy)
{
    ay_ = newAy;
}

void Ball::setVx(float newVx)
{
    vx_ = newVx;
}

void Ball::setVy(float newVy)
{
    vy_ = newVy;
}

void Ball::deflectOnTop()
{
    // from left to right
    if(vy_ <= 0.0 && vx_ >= 0.0 &&
       ay_ <= 0.0 && ax_ >= 0.0)
    {
        ay_ *= -1;
        vy_ *= -1;
    }
    else if(vy_ <= 0.0 && vx_ <= 0.0 && //from right to left
            ay_ <= 0.0 && ax_ <= 0.0)
    {
        ay_ *= -1;
        vy_ *= -1;
    }
}

void Ball::deflectOnBottom()
{
    // from left to right
    if(vy_ >= 0.0 && vx_ >= 0.0 &&
       ay_ >= 0.0 && ax_ >= 0.0)
    {
        ay_ *= -1;
        vy_ *= -1;
    }
    else if(vy_ >= 0.0 && vx_ <= 0.0 && //from right to left
            ay_ >= 0.0 && ax_ <= 0.0)
    {
        ay_ *= -1;
        vy_ *= -1;
    }
}

void Ball::deflectOnRight()
{
    // from bottom to top
    if(vy_ <= 0.0 && vx_ >= 0.0 &&
       ay_ <= 0.0 && ax_ >= 0.0)
    {
        ax_ *= -1;
        vx_ *= -1;
    }
    else if(vy_ >= 0.0 && vx_ >= 0.0 && //from top to bottom
            ay_ >= 0.0 && ax_ >= 0.0)
    {
        ax_ *= -1;
        vx_ *= -1;
    }
}

void Ball::deflectOnLeft()
{
    // from bottom to top
    if(vy_ <= 0.0 && vx_ <= 0.0 &&
       ay_ <= 0.0 && ax_ <= 0.0)
    {
        ax_ *= -1;
        vx_ *= -1;
    }
    else if(vy_ >= 0.0 && vx_ <= 0.0 && //from top to bottom
            ay_ >= 0.0 && ax_ <= 0.0)
    {
        ax_ *= -1;
        vx_ *= -1;
    }
}


