#ifndef PROCESSLISTDATAGNERERATION_H
#define PROCESSLISTDATAGNERERATION_H
#include "QThread"
#include "process.h"
#include "algorithm.h"
#include "QMetaType"

#include <QTableWidget>

class processListDataGnereration : public QThread
{
    Q_OBJECT

public:
    QList<Process> input;
    void run();
signals:
    void processListOut(QList<QString> *);
private:
    QList<QString> tmpItem;
};

#endif // PROCESSLISTDATAGNERERATION_H
