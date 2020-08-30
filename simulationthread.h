#ifndef SIMULATIONTHREAD_H
#define SIMULATIONTHREAD_H
#include <QThread>
#include <QtDebug>
#include <QList>
#include "algorithm.h"
#include "process.h"

/**
 * @brief
 *
 */
class SimulationThread : public QThread
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     */
    ~SimulationThread();

    /**
     * @brief
     *
     * @param
     */
    void activeAlgorithmChanged(Algorithm *);
    /**
     * @brief
     *
     * @param
     */
    void setProcessTable(QList<Process> *);
    /**
     * @brief
     *
     */
    void doWork();

    bool isRunning = true; /**< TODO: describe */

private:
    /**
     * @brief
     *
     */
    void run() override;
    /**
     * @brief
     *
     * @return int
     */
    int exec();

    Algorithm * currentAlgorithm = nullptr; /**< TODO: describe */
    QList<Process> * processTable = nullptr; /**< TODO: describe */
    QList<Process> sortedProcessTable; /**< TODO: describe */

signals:
    /**
     * @brief
     *
     * @param
     * @param
     * @param bool
     */
    void resultReady(QList<Process> *,Algorithm *,bool);
    /**
     * @brief
     *
     * @param QString
     */
    void updateLog(QString);
};

#endif // SIMULATIONTHREAD_H
