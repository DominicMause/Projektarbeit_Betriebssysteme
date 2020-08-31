#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QString>
#include "simulationthread.h"
#include "mainwindow.h"
#include "process.h"
#include "algorithm.h"

/**
 * @brief
 *
 */
class SimulationController : public QObject
{
    Q_OBJECT
public:
    QString output; /**< TODO: describe */

    QList<Process> * processTable; /**< TODO: describe */
    QList<Algorithm*> algorithms; /**< TODO: describe */
    Algorithm * activeAlgorithm = nullptr; /**< TODO: describe */
    MainWindow * mainWindow; /**< TODO: describe */

    /**
     * @brief
     *
     */
    SimulationController();
    /**
     * @brief
     *
     */
    ~SimulationController();

    /**
     * @brief
     *
     * @param
     */
    void setWindow(MainWindow *);
    /**
     * @brief
     *
     * @param
     */
    void addAlgorithm(Algorithm *);

    /**
     * @brief
     *
     * @param
     */
    void addProcess(Process);

    /**
     * @brief
     *
     * @param
     */
    void addProcesses(QList<Process>);
    /**
     * @brief
     *
     */
    void addExampleAlgorithms();
    /**
     * @brief
     *
     */
    void pushAlgorithmList();

private:
    SimulationThread * thread; /**< TODO: describe */



public slots:
    /**
     * @brief
     *
     * @param QString
     */
    void setActiveAlgorithm(QString);

signals:
    /**
     * @brief
     *
     * @param QString
     */
    void updateLog(QString);
    /**
     * @brief
     *
     * @param
     */
    void getActiveAlgorithm(Algorithm *);
    /**
     * @brief
     *
     * @param QList<QString>
     */
    void getAlgorithms(QList<QString>);
};

#endif // SIMULATIONCONTROLLER_H
