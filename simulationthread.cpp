#include "simulationthread.h"

void SimulationThread::run(){
    exec();
}

int SimulationThread::exec(){
    uint counter = 0;
    qint64 ms = 0;
    while(true){
        if(currentAlgorithm != nullptr){
            sortedProcessTable.clear();
            QElapsedTimer timer;
            timer.start();
            QList<Process> tmpList = currentAlgorithm->execute(processTable);
            ms += timer.elapsed();
            for(Process p : tmpList){
                sortedProcessTable.append(p);
            }
            qDebug() << counter%1000;
            if(counter%1000==0){
                currentAlgorithm->setWorkTime(ms/1000);
                emit resultReady(&sortedProcessTable, currentAlgorithm);
                ms=0;
            }
        }
        msleep(1);
        counter++;
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
