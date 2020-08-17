#include "simulationcontroller.h"

namespace Simulation {

SimulationController::SimulationController()
{
    mainWindow.show();
    mainWindow.setFixedSize(800,800);

    SimulationWorker *worker = new SimulationWorker;
    worker->moveToThread(&thread);
    connect(&thread,&QThread::finished,worker,&QObject::deleteLater);
    connect(this,&SimulationController::operate,worker,&SimulationWorker::doWork);
    connect(worker,&SimulationWorker::resultReady,&mainWindow,&MainWindow::logUpdate);

    thread.start();
    this->operate("");
}

SimulationController::~SimulationController(){
    thread.quit();
    thread.wait();
}

}
