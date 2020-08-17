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

    for(int i = 0; i < 100; i++){
        processTable.append(Process(i,"Ululu",QRandomGenerator::global()->generate()));
    }

    worker->setProcessTable(&processTable);

    thread.start();
}

void SimulationController::setWindow(MainWindow * mainWindow){
    this->mainWindow = mainWindow;
    connect(worker,&SimulationWorker::resultReady,mainWindow,&MainWindow::processListUpdate);
    //connect(worker,&SimulationWorker::pushActiveAlgorithm,mainWindow,&MainWindow::activeAlgorithmData);
}

void SimulationController::setAlgorithm(QString name){
    for(Algorithm * a: this->algorithms){
        if(a->getName().compare(name) == 0){
            this->activeAlgorithm = a;
            worker->activeAlgorithmChanged(a);
            break;
        }
    }
}

SimulationController::~SimulationController(){
    thread.quit();
    thread.wait();

    delete worker;
    delete mainWindow;
    delete activeAlgorithm;
    for(Algorithm * a : algorithms){
        delete a;
    }
}
