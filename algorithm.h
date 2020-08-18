#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "process.h"
#include <QString>
#include <QList>

class Algorithm
{

public:
    Algorithm(QString name);

    typedef QList<Process> (*func)(QList<Process>);

    void setId(int);
    void setFunction(func);
    void setWorkTime(qint64);

    int getId();
    QString getName();
    qint64 getWorkTime();
    long getSize();

    QList<Process> execute(QList<Process> *);

private:
    int ID;
    QString name;
    func function_;
    qint64 workTime;
    long size;
};

#endif // ALGORITHM_H
