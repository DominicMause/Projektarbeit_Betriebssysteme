#ifndef SIMULATIONTHREAD_H
#define SIMULATIONTHREAD_H
#include <QThread>
#include <QtDebug>
#include <QList>
#include "algorithm.h"
#include "process.h"

/**
 * @brief thread used for sorting and executing algorithms and processes
 *
 */
class SimulationThread : public QThread
{
    Q_OBJECT

public:

    ~SimulationThread();

    /**
     * @brief resets the sorting algorithm
     *
     * @param Algorithm
     */
    void activeAlgorithmChanged(Algorithm *);

    /**
     * @brief resets the process table
     *
     * @param QList<Process>
     */
    void setProcessTable(QList<Process> *);

    /**
     * @brief tells if the thread should run
     */
    bool isRunning = true;

private:

    /**
     * @brief is called during initialization
     */
    void run() override;

    /**
     * @brief command to execute the thread
     *
     * @return int
     */
    int exec();

    Algorithm * currentAlgorithm = nullptr; /**< TODO: describe */
    QList<Process> * processTable = nullptr; /**< TODO: describe */
    QList<Process> sortedProcessTable; /**< TODO: describe */

signals:
    /**
     * @brief is used when the algorithm is through to transfer data to the ui
     *
     * @param List of Processes
     * @param Algorithm Data
     * @param Changed flag
     */
    void resultReady(QList<Process> *,Algorithm *,bool);

    /**
     * @brief writes a QString to the log
     *
     * @param QString
     */
    void updateLog(QString);
};

#endif // SIMULATIONTHREAD_H
