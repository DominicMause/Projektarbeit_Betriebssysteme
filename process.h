#ifndef PROCESS_H
#define PROCESS_H

#include <QString>

class Process
{

public:
    enum Priority { low, middle, high };

    Process(int, QString, int = 0, Priority = middle);

    int getId();
    QString getName();
    int getProcessSize();
    int getPriority();

    ///
    /// \brief setProcessSize
    ///
    void setProcessSize(int);
    void setPriotity(Priority);

private:
    int ID;
    QString name;
    int processSize;
    Priority priority;

};

#endif // PROCESS_H
