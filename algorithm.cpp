#include "algorithm.h"

Algorithm::Algorithm(int id, QString name)
{
    this->ID = id;
    this->name = name;
}

int Algorithm::getId(){
    return ID;
}

QString Algorithm::getName(){
    return name;
}

void Algorithm::setFunction(func func){
    function_ = func;
    size = sizeof (func);
}

QList<Process> Algorithm::execute(QList<Process> * list){
    return function_(*list);
}

void Algorithm::setWorkTime(qint64 elapsedTime){
    workTime = elapsedTime;
}

qint64 Algorithm::getWorkTime(){
    return workTime;
}

long Algorithm::getSize(){
    return size;
}
