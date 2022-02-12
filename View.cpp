#include <View.h>
#include <iostream>


View::View(QObject *parent)
{
 Q_EMIT randomSig();
}

void View::startSimulation()
{
    while(true)
    {
      //  std::cout<<"Running Simulation Loop"<<std::endl;

    }
}
