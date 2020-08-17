#include "simulationcontroller.h"
#include "helper.h"
#include "QtDebug"
#include "QRandomGenerator"
#include "process.h"

SimulationController::SimulationController()
{
    worker = new SimulationWorker;
    worker->moveToThread(&thread);

    connect(&thread,&QThread::finished,worker,&QObject::deleteLater);
    connect(this,&SimulationController::operate,worker,&SimulationWorker::doWork);

    Algorithm * a = new Algorithm(0,"FirstComeFirstServed");
    a->setFunction(Helper::firstComeFirstServed);
    algorithms.append(a);

    processTable = new QList<Process>();
    for(int i = 0; i < 10000; i++){
        processTable->append(Process(i,"Ululu",QRandomGenerator::global()->generate()));
    }

    worker->setProcessTable(processTable);

    thread.start();
}

void SimulationController::setWindow(MainWindow * mainWindow){
    this->mainWindow = mainWindow;
    connect(worker,&SimulationWorker::resultReady,mainWindow,&MainWindow::processListUpdate);
}

void SimulationController::setAlgorithm(QString name){
    for(Algorithm * a: algorithms){
        if(a->getName().compare(name) == 0){
            this->activeAlgorithm = a;
            worker->activeAlgorithmChanged(a);
            break;
        }
    }
}

SimulationController::~SimulationController(){
    delete worker;
    delete mainWindow;
    delete activeAlgorithm;
    delete processTable;
    for(Algorithm * a : algorithms){
        delete a;
    }

    thread.quit();
    thread.wait();
}
