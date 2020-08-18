#include "simulationcontroller.h"
#include "helper.h"
#include "QtDebug"
#include "QRandomGenerator"
#include "process.h"

SimulationController::SimulationController()
{
    thread = new SimulationThread();
    Algorithm * a = new Algorithm(0,"FirstComeFirstServed");
    a->setFunction(Helper::firstComeFirstServed);
    algorithms.append(a);

    processTable = new QList<Process>();
    for(int i = 0; i < 50000; i++){
        processTable->append(Process(i,"TestProcess ",QRandomGenerator::global()->generate()));
    }

    thread->setProcessTable(processTable);
    thread->start();
}

void SimulationController::setWindow(MainWindow * mainWindow){
    this->mainWindow = mainWindow;
    connect(thread,&SimulationThread::resultReady,mainWindow,&MainWindow::processListUpdate);
    connect(mainWindow,&MainWindow::algorithmusBoxChanged,this,&SimulationController::setAlgorithm);
}

void SimulationController::setAlgorithm(QString name){
    for(Algorithm * a: algorithms){
        if(a->getName().compare(name) == 0){
            this->activeAlgorithm = a;
            thread->activeAlgorithmChanged(a);
            break;
        }
    }
}

SimulationController::~SimulationController(){
    delete mainWindow;
    delete activeAlgorithm;
    delete processTable;
    for(Algorithm * a : algorithms){
        delete a;
    }

    thread->quit();
    thread->wait();
    delete thread;
}
