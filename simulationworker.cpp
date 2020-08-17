#include "simulationworker.h"
#include <QtDebug>

void SimulationWorker::doWork(){

    while(true){
        if(currentAlgorithm != nullptr){
            sortedProcessTable.clear();
            for(Process p : currentAlgorithm->execute(processTable)){
                sortedProcessTable.append(p);
            }
            emit resultReady(&sortedProcessTable);
            emit pushActiveAlgorithm(currentAlgorithm);
        }
        _sleep(10);
    }
}

void SimulationWorker::activeAlgorithmChanged(Algorithm * algorithm){
    currentAlgorithm = algorithm;
}

void SimulationWorker::setProcessTable(QList<Process> * list){
    processTable = new QList<Process>();
    processTable->clear();
    for(Process p: *list){
        processTable->append(p);
    }
    qDebug() << processTable->count();
}

SimulationWorker::~SimulationWorker(){
    delete currentAlgorithm;
    delete processTable;
}
