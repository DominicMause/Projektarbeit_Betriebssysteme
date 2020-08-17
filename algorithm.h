#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QString>

namespace Model {

class Algorithm
{

public:
    Algorithm(int id, QString name);

    int getId();
    QString getName();

private:
    int ID;
    QString name;

};

}

#endif // ALGORITHM_H
