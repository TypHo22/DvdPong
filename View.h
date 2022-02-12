#include <QObject>
#include <thread>
class View : public QObject
{
    Q_OBJECT
public:
    explicit View(QObject *parent = nullptr);
    void startSimulation();

signals:
    void updateBallPosition(float x, float y);
    void randomSig();


private:
    std::thread t;

};
