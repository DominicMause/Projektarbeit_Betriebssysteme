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
 * @brief A controller that runs the simulation in a separate thread
 *
 */
class SimulationController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief table with all processes, which should be ordered and executed
     */
    QList<Process> * processTable;

    /**
     * @brief table with algorithms, which are used for sorting
     */
    QList<Algorithm*> algorithms;

    /**
     * @brief the active sort algorithm
     */
    Algorithm * activeAlgorithm = nullptr;

    /**
     * @brief the UI that represents the simulation
     */
    MainWindow * mainWindow;

    SimulationController();
    ~SimulationController();

    /**
     * @brief Assigns a ui to the controller
     *
     * @param MainWindow
     */
    void setWindow(MainWindow *);

    /**
     * @brief adds an algorithm to the list
     *
     * @param Algorithm
     */
    void addAlgorithm(Algorithm *);

    /**
     * @brief adds a process to the list
     *
     * @param Process
     */
    void addProcess(Process);

    /**
     * @brief adds a list of processes to the list
     *
     * @param QList<Process>
     */

    void addProcesses(QList<Process>);

    /**
     * @brief provides a series of sample algorithms
     *
     */
    void addExampleAlgorithms();

    /**
     * @brief provides the ui with the current list of algorithms
     *
     */
    void pushAlgorithmList();

private:
    /**
     * @brief the simulation thread, which sorts and executes the processes in the background
     */
    SimulationThread * thread;



public slots:
    /**
     * @brief sets the active algorithm
     *
     * @param QString
     */
    void setActiveAlgorithm(QString);

signals:
    /**
     * @brief writes a QString to the log
     *
     * @param QString
     */
    void updateLog(QString);

    /**
     * @brief gives the ui a list of algorithms in strings
     *
     * @param QList<QString>
     */
    void getAlgorithms(QList<QString>);
};

#endif // SIMULATIONCONTROLLER_H
