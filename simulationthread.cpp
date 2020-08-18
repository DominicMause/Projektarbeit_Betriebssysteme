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
            if(counter%100==0){
                qDebug() << ms << " ms";
                emit updateLog(QString::number(ms) + " ms for the last 100 cycles of " + QString::number(sortedProcessTable.count()) + " processes");
                currentAlgorithm->setWorkTime(ms/100);
                emit resultReady(&sortedProcessTable, currentAlgorithm);
                ms = 0;
            }
        }
        msleep(1);
        counter++;
    }
}

void SimulationThread::activeAlgorithmChanged(Algorithm * algorithm){
    currentAlgorithm = algorithm;

    emit updateLog("\n----------------------------------------------------------------------------------------------\n");
    emit updateLog("Active algorithm changed to " + algorithm->getName());
    emit updateLog("\n----------------------------------------------------------------------------------------------\n");
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
