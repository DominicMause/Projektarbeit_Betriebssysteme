#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QListWidget"
#include "QTextEdit"
#include "QLabel"
#include "QComboBox"
#include "QHBoxLayout"
#include "QList"
#include "process.h"
#include "QListWidgetItem"
#include "algorithm.h"
#include "myinfolabel.h"
#include "QThread"
#include "processlistdatagnereration.h"
#include "QMetaType"
#include "QSpacerItem"
#include <QTableWidget>
#include "QTableWidgetItem"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QThread thread;
public slots:
    void logUpdate(QString);
    void logClear();
    void processListUpdate(QList<Process> *, Algorithm *, bool hasChanged);
    void setProcessList(QList<QString> *);
    void algorithmusBoxUpdate(QList<QString>);
signals:
    void algorithmusBoxChanged(QString);

private slots:
    void boxChanged(int);
    void debugSlot(int);
     void debugSlot(QString);

private:
    Ui::MainWindow *ui;
    bool isTesting = false;
    QTextEdit *logBox;
    QComboBox *algoSelectComboBox;
    QListWidget *processList;
    MyInfoLabel *algoID, *algoName, *algoWorktime, *algoSize;
    Algorithm *currentAlgorythm = nullptr;
    QList<QString> tmpItem;
    QLabel *algoSelectLabel;
    QHBoxLayout *algorithmusSelector;
    QVBoxLayout *infoLayout;
    QHBoxLayout *topChildLayout;
    QVBoxLayout *mainBox;
    QHBoxLayout *topLayout;
    MyInfoLabel *processCount;
    processListDataGnereration *worker;
    processListDataGnereration *workerThread;

};
#endif // MAINWINDOW_H
