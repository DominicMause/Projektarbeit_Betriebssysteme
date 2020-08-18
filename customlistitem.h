#ifndef CUSTOMLISTITEM_H
#define CUSTOMLISTITEM_H

#include <QObject>
#include <QWidget>

class CustomListItem : public QWidget
{
    Q_OBJECT
public:
    explicit CustomListItem(QWidget *parent = nullptr);

signals:

};

#endif // CUSTOMLISTITEM_H
