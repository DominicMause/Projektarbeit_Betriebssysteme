#ifndef HELPER_H
#define HELPER_H
#include "process.h"
#include "algorithm.h"
#include <QFile>
#include <QList>

class Helper
{
public:
    static QList<Process> firstComeFirstServed(QList<Process>);
    static QList<Process> shortestJobFirst(QList<Process>);
};

#endif // HELPER_H
