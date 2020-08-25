#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QListWidget"
#include "QTextEdit"
#include "QLabel"
#include "QComboBox"
#include "QHBoxLayout"
#include "qlistview.h"
#include "process.h"
#include "QListWidgetItem"
#include "algorithm.h"
#include "myinfolabel.h"
#include "QThread"
#include "QMetaType"
#include "QSpacerItem"
#include <QMutex>
#include <QTableWidget>
#include "QTableWidgetItem"
#include "processlistmodel.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ProcessListModel *model;
    QThread *worker;
public slots:
    void logUpdate(QString);
    void logClear();
    void log2Update(QString);
    void log2Clear();
    void processListUpdate(QList<Process> *, Algorithm *, bool hasChanged);
    void algorithmusBoxUpdate(QList<QString>);
signals:
    void algorithmusBoxChanged(QString);

private slots:
    void boxChanged(int);

private:
    Ui::MainWindow *ui;
    bool isTesting = false;
    QTextEdit *logBox;
    QTextEdit *logBox2;
    QComboBox *algoSelectComboBox;
    QListView *processList;
    MyInfoLabel *algoID, *algoName, *algoWorktime, *algoSize;
    Algorithm *currentAlgorythm = nullptr;
    QList<QString> tmpItem;
    QLabel *algoSelectLabel;
    QHBoxLayout *algorithmusSelector;
    QVBoxLayout *infoLayout;
    QHBoxLayout *topChildLayout;
    QVBoxLayout *mainBox;
    QHBoxLayout *topLayout;
    QHBoxLayout *bottomLayout;
    MyInfoLabel *processCount;
    QLabel *idHeader;
    QLabel *nameHeader;
    QLabel *prioHeader;
    QLabel *sizeHeader;
    QHBoxLayout *headerLayout;
    QVBoxLayout *processListHeaderLayout;
    QListView *view;



};
#endif // MAINWINDOW_H
