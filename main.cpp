#include <QApplication>
#include <simulationworker.h>
#include <simulationcontroller.h>
using namespace Simulation;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SimulationController * controller = new SimulationController();

    a.exec();
    return 0;
}
