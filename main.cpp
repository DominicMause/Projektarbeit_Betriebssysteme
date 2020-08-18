#include <QApplication>
#include <simulationcontroller.h>
#include <simulationthread.h>
#include "mainwindow.h"
#include "helper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    SimulationController controller;
    controller.setWindow(&mainWindow);
    controller.addExampleAlgorithms();
    controller.setActiveAlgorithm("FirstComeFirstServed");

    return a.exec();
}
