#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <QObject>
#include <QThread>
#include <simulationworker.h>
#include "mainwindow.h"

namespace Simulation {

class SimulationController : public QObject
{
    Q_OBJECT
public:
    QThread thread;
    QString output;

    SimulationController();
    ~SimulationController();

    void setWindow(MainWindow * mainWindow);

private:
    MainWindow * mainWindow;
    SimulationWorker * worker;

signals:
    void operate();

};

}

#endif // SIMULATIONCONTROLLER_H
