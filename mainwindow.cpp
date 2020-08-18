#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"
#include "processlistdatagnereration.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,800);
    this->setWindowTitle("Scheduling Simulator");
    topLayout = new QHBoxLayout;
    mainBox = new QVBoxLayout;
    topChildLayout = new QHBoxLayout;
    infoLayout = new QVBoxLayout;
    algorithmusSelector = new QHBoxLayout;
    processList = new QListWidget(this);
    logBox = new QTextEdit();
    logBox->setReadOnly(true);
    algoSelectLabel = new QLabel("Algorithm");
    algoSelectComboBox = new QComboBox();
    algoSelectComboBox->setPlaceholderText("empty");
    connect(algoSelectComboBox, SIGNAL(activated(int)), this,SLOT(boxChanged(int)));
    algoSelectComboBox->setMinimumWidth(150);
    algoID = new MyInfoLabel("ID ");
    algoName = new MyInfoLabel("Name ");
    algoWorktime = new MyInfoLabel("Worktime ");
    algoSize = new MyInfoLabel("Size ");
    processCount = new MyInfoLabel("Process Count ");

    mainBox->addLayout(topLayout);
    mainBox->addWidget(logBox);
    topLayout->addLayout(topChildLayout,2);
    topChildLayout->addItem(new QSpacerItem(50, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    topChildLayout->addLayout(infoLayout);
    topChildLayout->addItem(new QSpacerItem(100, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    topChildLayout->addWidget(processList);

    infoLayout->addLayout(algorithmusSelector);
    infoLayout->addLayout(algoID);
    infoLayout->addLayout(algoName);
    infoLayout->addLayout(algoWorktime);
    infoLayout->addLayout(algoSize);
    infoLayout->addLayout(processCount);
    algorithmusSelector->addWidget(algoSelectLabel);
    algorithmusSelector->addWidget(algoSelectComboBox);
    centralWidget()->setLayout(mainBox);


    //Tests
    if(isTesting){
    QList<QString> list = QList<QString>();
    QList<Process> list2 = QList<Process>();
        for (int i = 0;i<6;i++) {
            QString s =  QString("Test " + QString::number(i));
            Process p =  Process(i,s);
            list2.append(p);
            list.append(s);

        }
    algorithmusBoxUpdate(list);

    }
    //Tests end
}

void MainWindow::logClear()
{
    logBox->clear();
}

void MainWindow::logUpdate(QString string)
{
    //Updating the Log Text Box's content
    logBox->append(string);

}

void MainWindow::processListUpdate(QList<Process> * inputProcessList, Algorithm * a,bool hasChanged)
{
    //Update the Process list
    //Start thread

    workerThread = new processListDataGnereration();
    workerThread->input = *inputProcessList;
    connect(workerThread, SIGNAL(processListOut(QList<QString> *)), this, SLOT(setProcessList(QList<QString> *)));
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    workerThread->start();


    if(currentAlgorythm == nullptr || a->getId()!= currentAlgorythm->getId()){
        currentAlgorythm = a;
    }

    // Active Algorithm data Updated
    algoID->setValue(currentAlgorythm->getId());
    algoName->setValue(currentAlgorythm->getName());
    algoWorktime->setValue(QString::number(currentAlgorythm->getWorkTime()) + " ms");
    algoSize->setValue(QString::number(currentAlgorythm->getSize()) + " bytes");

    processCount->setValue(inputProcessList->count());


}

void MainWindow::setProcessList(QList<QString> *s)
{
    processList->clear();
    processList->addItems(*s);
    workerThread->quit();
}

void MainWindow::algorithmusBoxUpdate(QList<QString> inputAlgoList)
{
    //Update the content of the algorithm Drop-Down
    foreach(QString s,inputAlgoList){
        algoSelectComboBox->addItem(s);
    }
}


void MainWindow::boxChanged(int)
{
    QString selectedName = algoSelectComboBox->currentText();
    qDebug() << selectedName;
    emit algorithmusBoxChanged(selectedName);
}

void MainWindow::debugSlot(int s)
{
    qDebug() << s;
}

void MainWindow::debugSlot(QString s)
{
    qDebug() << s;
}

MainWindow::~MainWindow()
{
    delete currentAlgorythm;
    delete algoID;
    delete algoName;
    delete algoWorktime;
    delete algoSize;
    delete processList;
    delete algoSelectComboBox;
    delete logBox;
    delete algoSelectLabel;
    delete algorithmusSelector;
    delete infoLayout;
    delete topChildLayout;
    delete mainBox;
    delete topLayout;
    delete processCount;
    delete workerThread;
    delete ui;
}

