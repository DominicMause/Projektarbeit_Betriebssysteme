#include "myinfolabel.h"
#include "ui_myinfolabel.h"

MyInfoLabel::MyInfoLabel(QString _valueName,QString _value)
{
    valueName = new QLabel(_valueName);
    value = new QLabel(_value);
    this->addWidget(valueName);
    this->addWidget(value);
}

MyInfoLabel::MyInfoLabel(QString _valueName)
{
    valueName = new QLabel(_valueName);
    value = new QLabel("-----");
    this->addWidget(valueName);
    this->addWidget(value);
}

MyInfoLabel::~MyInfoLabel()
{
    delete valueName;
    delete value;
}


void MyInfoLabel::setValue(QString s)
{
    value->setText(s);
}

void MyInfoLabel::setValue(int s)
{
    value->setText(QString::number(s));
}
