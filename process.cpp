#include "process.h"

Process::Process(int id, QString name, int size, Priority priority)
{
    ID = id;
    this->name = name;
    processSize = size;
    this->priority = priority;
}

int Process::getId(){
    return ID;
}

QString Process::getName(){
    return name;
}

int Process::getProcessSize(){
    return processSize;
}

int Process::getPriority(){
    return priority;
}

void Process::setProcessSize(int size){
    processSize = size;
}

void Process::setPriotity(Priority priority){
    this->priority = priority;
}
