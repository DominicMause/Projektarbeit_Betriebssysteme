#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QString>
#include "simulationthread.h"
#include "mainwindow.h"
#include "process.h"
#include "algorithm.h"

class SimulationController : public QObject
{
    Q_OBJECT
public:
    QString output;

    QList<Process> * processTable;
    QList<Algorithm*> algorithms;
    Algorithm * activeAlgorithm = nullptr;

    SimulationController();
    ~SimulationController();

    void setWindow();
    void addAlgorithm(Algorithm *);
    void addExampleAlgorithms();
    void pushAlgorithmList();

private:
    SimulationThread * thread;
    MainWindow * mainWindow;


public slots:
    void setActiveAlgorithm(QString);

signals:
    void updateLog(QString);
    void getActiveAlgorithm(Algorithm *);
    void getAlgorithms(QList<QString>);
};

#endif // SIMULATIONCONTROLLER_H
