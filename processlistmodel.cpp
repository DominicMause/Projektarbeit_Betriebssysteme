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

QVariant ProcessListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("ID");
        case 1:
            return QString("Name");
        case 2:
            return QString("Priority");
        case 3:
            return QString("Size");
        }
    }
    return QVariant();
}

int ProcessListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    if(processList != nullptr || listSet){
        //return processList->count();
        return processList->length()+1;
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
            if(index.row() == 0){
                QString s = QString("ID\tName\tPriority\tSize");
                return s;
            }
            else{
            Process tmpProcess = processList->at(index.row()-1);
            QString s = QString::number(tmpProcess.getId()) + "\t" + tmpProcess.getName() + "\t" + QString::number(tmpProcess.getPriority()) + "\t" + QString::number(tmpProcess.getProcessSize());
            return s;
        }
    }

    return QVariant();
}
bool x = true;
void ProcessListModel::updateProcessList(QList<Process> *p, Algorithm *, bool hasChanged)
{


    if(hasChanged){
        processList = p;
        listSet = true;
        this->dataChanged(createIndex(0,0),createIndex(p->length(),0));
    }

}
