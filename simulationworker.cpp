#include "simulationworker.h"
#include <QtDebug>

void SimulationWorker::doWork(){
    while(true){
        if(currentAlgorithm != nullptr){
            sortedProcessTable = currentAlgorithm->execute(this->processTable);
            emit resultReady(&sortedProcessTable);
            //emit pushActiveAlgorithm(currentAlgorithm);
        }
        _sleep(10);
    }
}

void SimulationWorker::activeAlgorithmChanged(Algorithm * algorithm){
    currentAlgorithm = algorithm;
}

void SimulationWorker::setProcessTable(QList<Process> * list){
    processTable = list;
}

SimulationWorker::~SimulationWorker(){
    delete currentAlgorithm;
    delete processTable;
}
