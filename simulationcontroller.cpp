#include "simulationcontroller.h"

namespace Simulation {

SimulationController::SimulationController()
{
    mainWindow.show();
    mainWindow.setFixedSize(800,800);

    SimulationWorker *worker = new SimulationWorker;
    worker->moveToThread(&thread);
    //connect(&thread,&QThread::finished,worker,&QObject::deleteLater);
    //connect(this,SIGNAL(operate()),worker,SLOT(doWork()));
    //connect(worker,SIGNAL(resultReady()),&mainWindow,SLOT(updateLabel()));

    thread.start();
}

SimulationController::~SimulationController(){
    thread.quit();
    thread.wait();
}

}
