#include "process.h"

Process::Process(int id, QString name, int size)
{
    this->ID = id;
    this->name = name;
    this->processSize = size;
}

int Process::getId(){
    return this->ID;
}

QString Process::getName(){
    return this->name;
}

void Process::setProcessSize(int size){
    this->processSize = size;
}

int Process::getProcessSize(){
    return this->processSize;
}
