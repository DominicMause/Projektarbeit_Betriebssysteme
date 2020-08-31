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
    /**
     * @brief
     *
     * @param QList<Process>
     * @return QList<Process>
     */
    static QList<Process> firstComeFirstServed(QList<Process>);
    /**
     * @brief
     *
     * @param QList<Process>
     * @return QList<Process>
     */
    static QList<Process> lastComeFirstServed(QList<Process>);
    /**
     * @brief
     *
     * @param QList<Process>
     * @return QList<Process>
     */
    static QList<Process> shortestJobFirst(QList<Process>);

    static QList<Process> roundRobin(QList<Process>);

    static QList<Process> roundRobinWithPrio(QList<Process>);

    static const int processingTime = 5;
};

#endif // HELPER_H
