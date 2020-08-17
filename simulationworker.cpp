#include "simulationworker.h"
#include <QElapsedTimer>

void SimulationWorker::doWork(){

    while(true){
        if(currentAlgorithm != nullptr){
            sortedProcessTable.clear();
            QElapsedTimer timer;
            timer.start();
            QList<Process> tmpList = currentAlgorithm->execute(processTable);
            currentAlgorithm->setWorkTime(timer.elapsed());
            for(Process p : tmpList){
                sortedProcessTable.append(p);
            }
            emit resultReady(&sortedProcessTable, currentAlgorithm);
        }
        _sleep(100);
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
}

SimulationWorker::~SimulationWorker(){
    delete currentAlgorithm;
    delete processTable;
}
