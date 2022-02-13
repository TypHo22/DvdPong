#include <QObject>
#include <thread>
#include <Ball.h>
#include <Boundarie.h>
class View : public QObject
{
    Q_OBJECT
public:
    explicit View(QObject *parent = nullptr);


signals:
    void updateBallPosition(float x, float y);
    void changeColor(float r, float g, float b);
    void randomSig();

public slots:
    void aquireBoundaries(float bStartX, float bStartY, float windowHeight, float windowWidth);
    void startSimulation();

private:
    std::thread t_;
    static float simulationCycleSeconds_;
    Ball ball_;
    Boundarie boundarie_;
};
