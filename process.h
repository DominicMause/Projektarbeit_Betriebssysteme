#ifndef PROCESS_H
#define PROCESS_H
#include <QString>

namespace Model {

class Process
{

public:
    Process(int id, QString name);

    int getId();
    QString getName();

private:
    int ID;
    QString name;

};

}

#endif // PROCESS_H
