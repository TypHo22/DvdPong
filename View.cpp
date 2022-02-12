#include <View.h>
#include <iostream>
#include <thread>

float View::simulationCycleSeconds_ = 0.005;
View::View(QObject *parent)
{

}

void View::aquireBoundaries(float bStartX, float bStartY, float windowHeight, float windowWidth)
{
    int d = 3;
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

            if(boundarie_.checkInsideOfBoundarie(x,y))  //ball must get reflected, and play sound
            {

            }

            emit updateBallPosition(x,y);
            std::this_thread::sleep_for(std::chrono::milliseconds(5));//must match with simulationCycleSeconds
        }
    }};
}

