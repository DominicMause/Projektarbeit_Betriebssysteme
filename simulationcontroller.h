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
    MainWindow mainWindow;
    QThread thread;
    QString output;

    SimulationController();
    ~SimulationController();

//public slots:
//    void handleResults(const QString &par);
//
//signals:
//    void operate(const QString &par);

};

}

#endif // SIMULATIONCONTROLLER_H
