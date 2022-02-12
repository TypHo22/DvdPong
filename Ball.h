#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball();
    void update(float timeStep);


    float x() const;
    void setX(float newX);

    float y() const;
    void setY(float newY);

private:
    float ax_;
    float ay_;
    float vx_;
    float vy_;
    float x_;
    float y_;
};

#endif // BALL_H
