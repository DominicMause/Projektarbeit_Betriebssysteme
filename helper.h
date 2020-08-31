#ifndef HELPER_H
#define HELPER_H
#include "process.h"
#include "algorithm.h"
#include <QFile>
#include <QList>

/**
 * @brief
 *
 */
class Helper
{
public:

    static QList<Process> firstComeFirstServed(QList<Process>);

    static QList<Process> lastComeFirstServed(QList<Process>);

    static QList<Process> shortestJobFirst(QList<Process>);

    static QList<Process> roundRobin(QList<Process>);

    static QList<Process> roundRobinWithPrio(QList<Process>);

    static const int processingTime = 5;
};

#endif // HELPER_H
