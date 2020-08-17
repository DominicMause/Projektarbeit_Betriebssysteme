#ifndef SIMULATIONWORKER_H
#define SIMULATIONWORKER_H

#include <QObject>
#include "algorithm.h"

class SimulationWorker : public QObject
{
    Q_OBJECT

public:
    void activeAlgorithmChanged(Algorithm * algorithm);
    void setProcessTable(QList<Process> * list);

    ~SimulationWorker();

private:
    Algorithm * currentAlgorithm = nullptr;
    QList<Process> * processTable = nullptr;
    QList<Process> sortedProcessTable;

public slots:
    void doWork();

signals:
    void resultReady(QList<Process> * processes,Algorithm * algorithmus);
};

#endif // SIMULATIONWORKER_H
