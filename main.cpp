#include <QApplication>
#include <simulationworker.h>
#include <simulationcontroller.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    SimulationController * controller = new SimulationController();
    controller->setWindow(&mainWindow);
    controller->operate();

    controller->setAlgorithm("FirstComeFirstServed");

    return a.exec();
}
