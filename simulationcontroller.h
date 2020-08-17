#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <QObject>
#include <QThread>
#include "simulationworker.h"
#include "mainwindow.h"
#include "process.h"
#include "algorithm.h"

class SimulationController : public QObject
{
    Q_OBJECT
public:
    QThread thread;
    QString output;

    QList<Process> * processTable;
    QList<Algorithm*> algorithms;
    Algorithm * activeAlgorithm = nullptr;

    SimulationController();
    ~SimulationController();

    void setWindow(MainWindow * mainWindow);

private:
    MainWindow * mainWindow;
    SimulationWorker * worker;

public slots:
    void setAlgorithm(QString name);

signals:
    void operate();
    void getActiveAlgorithm(Algorithm * activeAlgorithm);
    void getAlgorithms(QList<QString> algorithms);
};

#endif // SIMULATIONCONTROLLER_H
