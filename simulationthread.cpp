#include "simulationthread.h"

void SimulationThread::run(){
    exec();
}

int SimulationThread::exec(){
    uint counter = 0;
    qint64 ms = 0;
    bool changed = false;

    int cycles = 10;

    while(true){
        if(currentAlgorithm != nullptr){
            QElapsedTimer timer;
            timer.start();
            QList<Process> tmpList = currentAlgorithm->execute(processTable);
            ms += timer.elapsed();
            currentAlgorithm->setWorkTime(timer.elapsed());

            if(sortedProcessTable.count()>0){
                for(int i = 0; i < tmpList.count(); i++){
                    if(tmpList[i].getId() != sortedProcessTable[i].getId()){
                        changed = true;
                        break;
                    }
                }
            }else{
                changed = true;
            }
            if(changed){
                sortedProcessTable.clear();
                sortedProcessTable.append(tmpList);
            }
            if(counter%cycles==0){
                emit resultReady(&sortedProcessTable, currentAlgorithm,changed);
                emit updateLog(QString::number(ms) + " ms for the last " + QString::number(cycles) + " cycles of " + QString::number(sortedProcessTable.count()) + " processes");
                ms = 0;
                changed = false;
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
