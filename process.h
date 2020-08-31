#ifndef PROCESS_H
#define PROCESS_H

#include <QString>

/**
 * @brief
 *
 */
class Process
{

public:
    typedef void (*func)();

    /**
     * @brief the priority of the process
     *
     */
    enum Priority { low, middle, high };

    /**
     * @brief
     *
     * @param int
     * @param QString
     * @param int
     * @param Priority
     */
    Process(int, QString, /*func,*/ Priority = middle);

    /**
     * @brief returns the ID of the process
     *
     * @return int
     */
    int getId();

    /**
     * @brief returns the name of the process
     *
     * @return QString
     */
    QString getName();

    /**
     * @brief returns the process size in byte
     *
     * @return int
     */
    int getProcessSize();

    /**
     * @brief returns the priority in int
     *
     * @return int
     */
    int getPriority();

    /**
     * @brief warining against use.
     *
     * @param int
     */
    void setProcessSize(int);

    /**
     * @brief set the priority with the Priority enum
     *
     * @param Priority
     */
    void setPriotity(Priority);

    /**
     * @brief sets the function that the process executes
     */
    void setFunction(func);

private:
    int ID; /**< TODO: describe */
    QString name; /**< TODO: describe */
    int processSize; /**< TODO: describe */
    Priority priority; /**< TODO: describe */
    func function;

};

#endif // PROCESS_H
