#include "algorithm.h"

Algorithm::Algorithm(int id, QString name)
{
    this->ID = id;
    this->name = name;
}

int Algorithm::getId(){
    return this->ID;
}

QString Algorithm::getName(){
    return this->name;
}

void Algorithm::setFunction(func func){
    this->function_ = func;
}

QList<Process> Algorithm::execute(QList<Process> * list){
    return this->function_(*list);
}

void Algorithm::setWorkTime(qint64 elapsedTime){
    workTime = elapsedTime;
}

qint64 Algorithm::getWorkTime(){
    return workTime;
}
