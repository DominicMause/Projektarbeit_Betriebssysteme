#include "processlistdatagnereration.h"


void processListDataGnereration::run()
{

    tmpItem.clear();
    tmpItem = QList<QString>();
    foreach(Process v, input){

        QString s = QString::number(v.getId()) + "; " + v.getName();
        tmpItem.append(s);
    }
    emit processListOut(&tmpItem);
}
