#include "algorithm.h"

namespace Model {

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

}
