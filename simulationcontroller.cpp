#include "simulationcontroller.h"
#include "helper.h"
#include "QtDebug"
#include "QRandomGenerator"
#include "process.h"

SimulationController::SimulationController()
{
    thread = new SimulationThread();

    processTable = new QList<Process>();
    for(int i = 0; i < 50000; i++){
        processTable->append(Process(i,"TestProcess ",QRandomGenerator::global()->generate()));
    }

    thread->setProcessTable(processTable);
    thread->start();
}

void SimulationController::pushAlgorithmList(){
    QList<QString> list;
    for(Algorithm * a : algorithms){
        list.append(a->getName());
    }
    emit getAlgorithms(list);
}

void SimulationController::setWindow(MainWindow * mainWindow){
    this->mainWindow = mainWindow;
    connect(thread,&SimulationThread::resultReady,mainWindow,&MainWindow::processListUpdate);
    connect(thread,&SimulationThread::resultReady,mainWindow->model,&ProcessListModel::updateProcessList);
    connect(mainWindow,&MainWindow::algorithmusBoxChanged,this,&SimulationController::setActiveAlgorithm);
    connect(this,&SimulationController::getAlgorithms,mainWindow,&MainWindow::algorithmusBoxUpdate);
    connect(mainWindow,&MainWindow::algorithmusBoxChanged,this,&SimulationController::setActiveAlgorithm);
    connect(this,&SimulationController::updateLog,mainWindow,&MainWindow::logUpdate);
    connect(thread,&SimulationThread::updateLog,mainWindow,&MainWindow::logUpdate);

    addExampleAlgorithms();
}

void SimulationController::addExampleAlgorithms(){

    emit updateLog("------------------------------------------------------------------------------------------\n");
    emit updateLog("Adding example algorithms to list\n");

    Algorithm * firstCome = new Algorithm("First Come First Served");
    firstCome->setFunction(Helper::firstComeFirstServed);
    addAlgorithm(firstCome);

    Algorithm * lastCome = new Algorithm("Last Come First Served");
    lastCome->setFunction(Helper::lastComeFirstServed);
    addAlgorithm(lastCome);

    Algorithm * shortestJob = new Algorithm("Shortest Job First");
    shortestJob->setFunction(Helper::shortestJobFirst);
    addAlgorithm(shortestJob);

    pushAlgorithmList();
}

void SimulationController::addAlgorithm(Algorithm *algorithm){
    if(algorithms.count() > 0){
        for(Algorithm * a : algorithms){
            if(a->getName().compare(algorithm->getName()) == 0){
                return;
            }
        }
        algorithm->setId(algorithms.last()->getId()+1);
    }else{
        algorithm->setId(0);
    }
    emit updateLog(algorithm->getName() + " added to algorithm list");
    algorithms.append(algorithm);
}

void SimulationController::setActiveAlgorithm(QString name){
    for(Algorithm * a: algorithms){
        if(a->getName().compare(name) == 0){
            if(activeAlgorithm == nullptr || activeAlgorithm->getId()!=a->getId()){
                activeAlgorithm = a;
                thread->activeAlgorithmChanged(a);
            }
            break;
        }
    }
}

SimulationController::~SimulationController(){

    thread->isRunning = false;
    thread->quit();
    thread->wait();
    delete thread;

    delete mainWindow;
    delete activeAlgorithm;
    delete processTable;

    for(Algorithm * a : algorithms){
        delete a;
    }


}
