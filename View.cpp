#include <View.h>
#include <iostream>
#include <thread>
#include <random>
#include <chrono>
float View::simulationCycleSeconds_ = 0.005;
View::View(QObject *parent)
{

}

void View::aquireBoundaries(float bStartX, float bStartY, float windowHeight, float windowWidth)
{
    boundarie_.setBoundarie(windowWidth,windowHeight);
    ball_.setX(bStartX);
    ball_.setY(bStartY);
}

void View::startSimulation()
{
    t_ = std::thread{[&]()
    {
        while(true)
        {
          //  std::cout<<"Running Simulation Loop"<<std::endl;
            ball_.update(simulationCycleSeconds_);
            const float x = ball_.x();
            const float y = ball_.y();

            if(!boundarie_.checkInsideOfBoundarie(x,y))  //ball must get reflected, and play sound
            {
                ball_.deflect();
                emit changeColor (((double) rand() / (RAND_MAX)),((double) rand() / (RAND_MAX)),((double) rand() / (RAND_MAX)));
            }

            emit updateBallPosition(x,y);
            std::this_thread::sleep_for(std::chrono::milliseconds(5));//must match with simulationCycleSeconds
        }
    }};
}

