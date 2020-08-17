#include "simulationworker.h"
#include <QtDebug>

namespace Simulation {

int counter = 0;

void SimulationWorker::doWork(const QString &parameter){
    QString result = parameter;
    while(true){
        counter++;
        qDebug() << counter;
        emit resultReady(QString::number(counter));
        _sleep(10);
    }
}

}
