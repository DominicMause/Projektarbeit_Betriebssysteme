#include "simulationworker.h"
#include <QtDebug>

void SimulationWorker::doWork(){
    while(true){

        if(this->currentAlgorithm != nullptr){
            //this->currentAlgorithm->execute()
            //emit resultReady();
            qDebug() << currentAlgorithm->getName();
        }
        _sleep(10);
    }
}

void SimulationWorker::activeAlgorithmChanged(Algorithm *algorithm){
    this->currentAlgorithm = algorithm;
}
