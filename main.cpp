#include <QApplication>
#include <simulationworker.h>
#include <simulationcontroller.h>
#include "mainwindow.h"

using namespace Simulation;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    mainWindow.setFixedSize(800,800);

    SimulationController * controller = new SimulationController();
    controller->setWindow(&mainWindow);
    controller->operate();

    return a.exec();
}
