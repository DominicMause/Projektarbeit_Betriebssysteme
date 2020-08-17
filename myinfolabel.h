#ifndef MYINFOLABEL_H
#define MYINFOLABEL_H

#include <QWidget>
#include "QHBoxLayout"
#include "QLabel"

namespace Ui {
class MyInfoLabel;
}

class MyInfoLabel : public QHBoxLayout
{
    Q_OBJECT

public:
     MyInfoLabel(QString ,QString );
     MyInfoLabel(QString);
    ~MyInfoLabel();
    void setValue(QString);
    void setValue(int);
private:
     QLabel*valueName, *value;

};

#endif // MYINFOLABEL_H
