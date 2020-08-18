#ifndef PROCESS_H
#define PROCESS_H

#include <QString>

class Process
{

public:
    Process(int id, QString name, int size = 0);

    int getId();
    QString getName();
    void setProcessSize(int);
    int getProcessSize();

private:
    int ID;
    QString name;
    int processSize;

};

#endif // PROCESS_H
