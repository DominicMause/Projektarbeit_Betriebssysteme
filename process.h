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
    /**
     * @brief
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
    Process(int, QString, int = 0, Priority = middle);

    /**
     * @brief
     *
     * @return int
     */
    int getId();
    /**
     * @brief
     *
     * @return QString
     */
    QString getName();
    /**
     * @brief
     *
     * @return int
     */
    int getProcessSize();
    /**
     * @brief
     *
     * @return int
     */
    int getPriority();

    /**
     * @brief
     *
     * @param int
     */
    void setProcessSize(int);
    /**
     * @brief
     *
     * @param Priority
     */
    void setPriotity(Priority);

private:
    int ID; /**< TODO: describe */
    QString name; /**< TODO: describe */
    int processSize; /**< TODO: describe */
    Priority priority; /**< TODO: describe */

};

#endif // PROCESS_H
