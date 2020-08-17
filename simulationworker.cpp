#include "simulationworker.h"
#include <QtDebug>

namespace Simulation {

int counter = 0;

void SimulationWorker::doWork(){
    while(true){
        counter++;
        emit resultReady(QString::number(counter));
        _sleep(10);
    }
}

}
