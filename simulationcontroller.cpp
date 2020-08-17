#include "simulationcontroller.h"
#include "helper.h"
#include "QtDebug"

SimulationController::SimulationController()
{
    worker = new SimulationWorker;
    worker->moveToThread(&thread);

    connect(&thread,&QThread::finished,worker,&QObject::deleteLater);
    connect(this,&SimulationController::operate,worker,&SimulationWorker::doWork);

    Algorithm * a = new Algorithm(0,"FirstComeFirstServed");
    a->setFunction(Helper::firstComeFirstServed);
    algorithms.append(a);

    setAlgorithm("FirstComeFirstServed");

    thread.start();
}

void SimulationController::setWindow(MainWindow * mainWindow){
    this->mainWindow = mainWindow;
    connect(worker,&SimulationWorker::resultReady,mainWindow,&MainWindow::logUpdate);
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
}
