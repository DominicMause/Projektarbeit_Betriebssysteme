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

    ///
    /// \brief warning against use.
    /// id is set automatically
    ///
    void setId(int);

    ///
    /// \brief sets the function that describes the algorithm.
    /// the function must be set up in this way:
    /// QList<Process> (*func)(QList<Process>)
    ///
    void setFunction(func);

    ///
    /// \brief warning against use.
    /// worktime is overwritten with every task
    ///
    void setWorkTime(qint64);

    ///
    /// \brief returns the automatically set id
    /// \return
    ///
    int getId();

    ///
    /// \brief returns the set name
    /// \return
    ///
    QString getName();

    ///
    /// \brief returns the time it took the algorithm to complete the last task
    /// \return qint64
    ///
    qint64 getWorkTime();

    ///
    /// \brief returns the size of the algorithm in byte
    /// \return long
    ///
    long getSize();

    ///
    /// \brief executes the function of the algorithm.
    /// function can be set by calling setFunction(func)
    /// \return
    ///
    QList<Process> execute(QList<Process> *);

private:
    int ID;
    QString name;
    func function_;
    qint64 workTime;
    long size;
};

#endif // ALGORITHM_H
