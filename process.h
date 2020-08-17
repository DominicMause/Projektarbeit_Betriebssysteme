#ifndef PROCESS_H
#define PROCESS_H

#include <QString>

class Process
{

public:
    Process(int id, QString name, int size);

    int getId();
    QString getName();
    void setProcessSize(int size);
    int getProcessSize();

private:
    int ID;
    QString name;
    int processSize;

};

#endif // PROCESS_H
