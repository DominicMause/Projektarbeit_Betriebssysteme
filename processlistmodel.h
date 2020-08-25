#ifndef PROCESSLISTMODEL_H
#define PROCESSLISTMODEL_H
#include "QAbstractListModel"
#include "process.h"
#include "algorithm.h"

class ProcessListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ProcessListModel(QObject *parent = nullptr);
    ~ProcessListModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
        QList<Process> *processList = nullptr;
        bool listSet = false;
        int counter = 0;
public slots:
        void updateProcessList(QList<Process> *, Algorithm *, bool hasChanged);


};

#endif // PROCESSLISTMODEL_H
