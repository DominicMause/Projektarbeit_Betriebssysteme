#ifndef SIMULATIONWORKER_H
#define SIMULATIONWORKER_H

#include <QObject>

namespace Simulation {

class SimulationWorker : public QObject
{
    Q_OBJECT

public slots:
    void doWork();

signals:
    void resultReady(const QString &par);
};

}

#endif // SIMULATIONWORKER_H
