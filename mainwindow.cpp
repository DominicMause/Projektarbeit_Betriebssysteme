#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,800);
    this->setWindowTitle("Scheduling Simulator");
    QHBoxLayout *topLayout = new QHBoxLayout;
    QVBoxLayout *mainBox = new QVBoxLayout;
    QHBoxLayout *topChildLayout = new QHBoxLayout;
    QVBoxLayout *infoLayout = new QVBoxLayout;
    QHBoxLayout *algorithmusSelector = new QHBoxLayout;
    processList = new QListWidget(this);
    logBox = new QTextEdit();
    logBox->setReadOnly(true);
    QLabel *algoSelectLabel = new QLabel("Algorithmus");
    algoSelectComboBox = new QComboBox();
    algoSelectComboBox->setPlaceholderText("empty");
    connect(algoSelectComboBox, SIGNAL(activated(int)), this,SLOT(boxChanged(int)));

     algoID = new MyInfoLabel("ID ");
     algoName = new MyInfoLabel("Name ");
     algoWorktime = new MyInfoLabel("Worktime ");
     algoSize = new MyInfoLabel("Size ");


    mainBox->addLayout(topLayout);
    mainBox->addWidget(logBox);
    topLayout->addLayout(topChildLayout);
    topChildLayout->addLayout(infoLayout);
    topChildLayout->addWidget(processList);

    infoLayout->addLayout(algorithmusSelector);
    infoLayout->addLayout(algoID);
    infoLayout->addLayout(algoName);
    infoLayout->addLayout(algoWorktime);
    infoLayout->addLayout(algoSize);
    algorithmusSelector->addWidget(algoSelectLabel);
    algorithmusSelector->addWidget(algoSelectComboBox);
    centralWidget()->setLayout(mainBox);


    //Tests
    if(isTesting){
    QList<QString> list = *new QList<QString>;
    QList<Process> list2 = *new QList<Process>;
        for (int i = 0;i<6;i++) {
            QString s = QString("Test " + QString::number(i));
            Process p = Process(i,s);
            list2.append(p);
            list.append(s);
        }
    algorithmusBoxUpdate(list);
    processListUpdate(&list2);

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

void MainWindow::processListUpdate(QList<Process> * inputProcessList)
{
    //Update the Process list
    processList->clear();
    for(Process v : *inputProcessList){
        QListWidgetItem *tmpItem = new QListWidgetItem;
        tmpItem->setText(QString::number(v.getId()) + "; " + v.getName());
        processList->addItem(tmpItem);
    }
    processList->update();
}

void MainWindow::algorithmusBoxUpdate(QList<QString> inputAlgoList)
{
    //Update the content of the algorithm Drop-Down
    foreach(QString s,inputAlgoList){
        algoSelectComboBox->addItem(s);
    }
}

void MainWindow::activeAlgorithmData(Algorithm * a)
{
    if(a != nullptr){
        qDebug() << a->getName();
        if(a->getId()!=currentAlgorythm->getId()){
            currentAlgorythm = a;
        }
        // Active Algorithm data Updated
        algoID->setValue(currentAlgorythm->getId());
        algoName->setValue(currentAlgorythm->getName());
        algoWorktime->setValue("sec");
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
    delete ui;
}

