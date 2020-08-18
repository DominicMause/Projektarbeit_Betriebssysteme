#include "algorithm.h"

Algorithm::Algorithm(QString name)
{
    this->name = name;
}

int Algorithm::getId(){
    return ID;
}

QString Algorithm::getName(){
    return name;
}

void Algorithm::setId(int id){
    ID = id;
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
