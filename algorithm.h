#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "process.h"
#include <QString>
#include <QList>

class Algorithm
{

public:
    Algorithm(int id, QString name);

    typedef QList<Process> (*func)(QList<Process> list);

    int getId();
    QString getName();
    void setFunction(QList<Process> (*func) (QList<Process>));
    QList<Process> execute(QList<Process> *);
    void setWorkTime(qint64 elapsedTime);
    qint64 getWorkTime();
    long getSize();

private:
    int ID;
    QString name;
    func function_;
    qint64 workTime;
    long size;
};

#endif // ALGORITHM_H
