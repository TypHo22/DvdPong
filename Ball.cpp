#include "Ball.h"

Ball::Ball() : ax_(-15),ay_(15),vx_(0),vy_(0),x_(250),y_(250) //x,y positions taken from qml center of window
{

}

void Ball::update(float timeStep) //timeStep in seconds
{
    vx_ += ax_ * timeStep;
    vy_ += ay_ * timeStep;
    x_ += vx_ * timeStep;
    y_ += vy_ * timeStep;
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


