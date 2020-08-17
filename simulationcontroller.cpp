#include "simulationcontroller.h"

namespace Simulation {

SimulationController::SimulationController()
{
    worker = new SimulationWorker;

    worker->moveToThread(&thread);
    connect(&thread,&QThread::finished,worker,&QObject::deleteLater);
    connect(this,&SimulationController::operate,worker,&SimulationWorker::doWork);

    thread.start();
}

void SimulationController::setWindow(MainWindow * mainWindow){
    this->mainWindow = mainWindow;
    connect(worker,&SimulationWorker::resultReady,mainWindow,&MainWindow::logUpdate);
}

SimulationController::~SimulationController(){
    thread.quit();
    thread.wait();
}

}
