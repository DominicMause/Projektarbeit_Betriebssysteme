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
#include "QStatusBar"
#include "QProgressBar"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief This class is responsible for the UI.
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Creates a UI to display Algorythm and process Data.
     *
     */
    MainWindow(QWidget *parent = nullptr);

    ProcessListModel *model; /**< The Model that provieds the information for the processList. */

    /**
     * @brief
     *
     */
    ~MainWindow();
public slots:
    /**
     * @brief This Slot recives a string that gets appended to the left Log.
     *
     * @param string String that gets appended.
     */
    void logUpdate(QString string);
    /**
     * @brief  This Slot clears the left Log in the UI.
     *
     */
    void logClear();
    /**
     * @brief This Slot recives a string that gets appended to the right Log.
     *
     * @param string string String that gets appended.
     */
    void log2Update(QString string);
    /**
     * @brief This Slot clears the right Log in the UI.
     *
     */
    void log2Clear();
    /**
     * @brief Calling this Slot Updates the processList and Algorithm Information based on the Parameters
     *
     * @param inputProcessList Recieves a list of type Process that gets Displayed in the processList dependend on the hasChanged Parameter.
     * @param a overrides the Selected Algorithm.
     * @param hasChanged Marks if the contents of inputProcessList differ from the previous version to reduce performance of the UI due to unnecessary reloads of the UI.
     */
    void processListUpdate(QList<Process> *inputProcessList, Algorithm *a, bool hasChanged);
    /**
     * @brief This Slot is for stetting the items of the Algorithm Select combobox.
     *
     * @param inputAlgoList Recieves a list of Strings to be displayed in the Algorithm select Combobox menu.
     */
    void algorithmusBoxUpdate(QList<QString> inputAlgoList);

    void updateProgressBar(int);
signals:
    /**
     * @brief This Signal gets emited when the user selects a new Algorithm.
     *
     * @param algorithm Name of the selected algorithm.
     */
    void algorithmusBoxChanged(QString algorithm);

private slots:
    /**
     * @brief This Signal gets emited if another Algorithm in the Algorithm Select Combobox gets selected.
     */
    void boxChanged(int);
    void barChanged(int);


private:
    Ui::MainWindow *ui; /**< The UI Object of this Window. */
    QTextEdit *logBox; /**< Left log box. */
    QTextEdit *logBox2; /**< Right log box. */
    QComboBox *algoSelectComboBox; /**< Combobox to select the algorithm. */
    MyInfoLabel *algoID, *algoName, *algoWorktime, *algoSize; /**< Displayed algorithm infos. */
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
    QListView *processList;
    QProgressBar *bar;
    bool hasChanged = false;



};
#endif // MAINWINDOW_H
