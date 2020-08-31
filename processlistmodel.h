#ifndef PROCESSLISTMODEL_H
#define PROCESSLISTMODEL_H
#include "QAbstractListModel"
#include "process.h"
#include "algorithm.h"

/**
 * @brief This class inhertis from QAbstractItemListModel to function as a model for the processList. Its function is to providing the information for the processList that will be displayed.
 *
 */
class ProcessListModel : public QAbstractListModel
{
    Q_OBJECT

public:

    explicit ProcessListModel(QObject *parent = nullptr);

    ~ProcessListModel();

    // Basic functionality:
    /**
     * @brief This function provieds the processList with the number of rows to be displayed.
     *
     * @return int The number of rows.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief This function provied the process list with the data for the row entrys.
     *
     * @param index The index of wich the informations get returned.
     * @param role The role of the data that gets requested.
     * @return QVariant The data that gets displayed. In this case a String.
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


signals:
     /**
      * @brief this signal is call to output the progress of the UI while loading the Process list.
      *
      * @param int index of the current data set(not precentage).
      */
     void setProgress(int) const;

private:
        QList<Process> *processList = nullptr; /**< TODO: describe */
        bool listSet = false; /**< TODO: describe */
        int counter = 0; /**< TODO: describe */
public slots:
        /**
         * @brief This slot updates the model internal data.
         *
         * @param processes the new processes that will be istplayed if hasChanged ist true.
         * @param algorithm not used in this case.
         * @param hasChanged signals that the data of processes is different to the previous version.
         */
        void updateProcessList(QList<Process> * processes, Algorithm *algorithm, bool hasChanged);


};

#endif // PROCESSLISTMODEL_H
