#include "processlistmodel.h"
#include "QDebug"
#include "QApplication"

ProcessListModel::ProcessListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

ProcessListModel::~ProcessListModel()
{
    if(processList != nullptr){
    delete processList;
    }
}

int ProcessListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    if(processList != nullptr || listSet){
        return processList->length();
    }
    return 0;
}

QVariant ProcessListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole){
            Process tmpProcess = processList->at(index.row());
            QString s = QString::number(tmpProcess.getId()) + "\t" + tmpProcess.getName() + "\t" + QString::number(tmpProcess.getPriority()) + "\t" + QString::number(tmpProcess.getProcessSize());
            emit setProgress(index.row());
            return s;
    }

    return QVariant();
}

void ProcessListModel::updateProcessList(QList<Process> *p, Algorithm *, bool hasChanged)
{


    if(hasChanged){
        processList = p;
        listSet = true;
        this->dataChanged(createIndex(0,0),createIndex(p->length(),0));
    }

}
