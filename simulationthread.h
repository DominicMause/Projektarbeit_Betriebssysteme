#ifndef SIMULATIONTHREAD_H
#define SIMULATIONTHREAD_H
#include <QThread>
#include <QtDebug>
#include <QList>
#include "algorithm.h"
#include "process.h"

class SimulationThread : public QThread
{
    Q_OBJECT

public:
    ~SimulationThread();

    void activeAlgorithmChanged(Algorithm * algorithm);
    void setProcessTable(QList<Process> * list);
    void doWork();

private:
    void run() override;
    int exec();

    Algorithm * currentAlgorithm = nullptr;
    QList<Process> * processTable = nullptr;
    QList<Process> sortedProcessTable;

signals:
    void resultReady(QList<Process> * processes,Algorithm * algorithmus);
};

#endif // SIMULATIONTHREAD_H
