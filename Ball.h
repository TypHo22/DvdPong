#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball();
    void update(float timeStep);
    void deflect();

    //getters
    float x() const;
    float y() const;
    //setters
    void setX(float newX);
    void setY(float newY);
    void setAx(float newAx);
    void setAy(float newAy);
    void setVx(float newVx);
    void setVy(float newVy);
private:
    void deflectOnTop();
    void deflectOnBottom();
    void deflectOnRight();
    void deflectOnLeft();
private:
    float ax_;
    float ay_;
    float vx_;
    float vy_;
    float x_;
    float y_;
    float vectorX_;
    float vectorY_;

};

#endif // BALL_H
