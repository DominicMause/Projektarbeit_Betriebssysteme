#include "process.h"

namespace Model {

Process::Process(int id, QString name)
{
    this->ID = id;
    this->name = name;
}

int Process::getId(){
    return this->ID;
}

QString Process::getName(){
    return this->name;
}

}

