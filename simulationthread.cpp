#include "simulationthread.h"

void SimulationThread::run(){
    exec();
}

int SimulationThread::exec(){
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
        msleep(100);
    }
}

void SimulationThread::activeAlgorithmChanged(Algorithm * algorithm){
    currentAlgorithm = algorithm;
}

void SimulationThread::setProcessTable(QList<Process> * list){
    processTable = new QList<Process>();
    processTable->clear();
    for(Process p: *list){
        processTable->append(p);
    }
}

SimulationThread::~SimulationThread(){
    delete processTable;
    delete currentAlgorithm;
}
