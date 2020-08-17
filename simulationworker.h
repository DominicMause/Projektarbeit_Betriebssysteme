#ifndef SIMULATIONWORKER_H
#define SIMULATIONWORKER_H

#include <QObject>
#include "algorithm.h"

class SimulationWorker : public QObject
{
    Q_OBJECT

public:
    void activeAlgorithmChanged(Algorithm * algorithm);

private:
    Algorithm * currentAlgorithm = nullptr;

public slots:
    void doWork();

signals:
    void resultReady(const QString &par);
};

#endif // SIMULATIONWORKER_H
