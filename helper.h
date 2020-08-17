#ifndef HELPER_H
#define HELPER_H
#include "process.h"
#include "algorithm.h"
#include <QList>

class Helper
{
public:
    Helper();

    static Algorithm getAlgorithmByName(QString name);
    static Algorithm getAlgorithmByID(int ID);
    static QList<Process> firstComeFirstServed(QList<Process> list);
};

#endif // HELPER_H
