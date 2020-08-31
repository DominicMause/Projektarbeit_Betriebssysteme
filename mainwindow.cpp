#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"
#include "QElapsedTimer"





MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,800);
    this->setWindowTitle("Scheduling Simulator");
    topLayout = new QHBoxLayout;
    bottomLayout = new QHBoxLayout;
    mainBox = new QVBoxLayout;
    topChildLayout = new QHBoxLayout;
    infoLayout = new QVBoxLayout;
    algorithmusSelector = new QHBoxLayout;
    model = new ProcessListModel;
    logBox = new QTextEdit();
    logBox->setReadOnly(true);
    logBox2 = new QTextEdit();
    logBox2->setReadOnly(true);
    algoSelectLabel = new QLabel("Algorithm");
    algoSelectComboBox = new QComboBox();
    algoSelectComboBox->setPlaceholderText("empty");
    connect(algoSelectComboBox, SIGNAL(activated(int)), this,SLOT(boxChanged(int)));
    algoSelectComboBox->setMinimumWidth(150);
    algoID = new MyInfoLabel("ID");
    algoName = new MyInfoLabel("Name ");
    algoWorktime = new MyInfoLabel("Worktime ");
    algoSize = new MyInfoLabel("Size ");
    processCount = new MyInfoLabel("Process Count ");
    idHeader = new QLabel("ID");
    QWidget *w = new QWidget;
    nameHeader = new QLabel("Name");
    prioHeader = new QLabel("Priority");
    sizeHeader = new QLabel("Size");
    headerLayout = new QHBoxLayout(w);
    w->setFixedHeight(30);
    bar = new QProgressBar;


    processListHeaderLayout = new QVBoxLayout;



    processList = new QListView;
    mainBox->addLayout(topLayout);
    mainBox->addLayout(bottomLayout);
    bottomLayout->addWidget(logBox);
    bottomLayout->addWidget(logBox2);
    topLayout->addLayout(topChildLayout,2);
    topChildLayout->addItem(new QSpacerItem(50, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    topChildLayout->addLayout(infoLayout);
    topChildLayout->addItem(new QSpacerItem(137, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    topChildLayout->addLayout(processListHeaderLayout);
    processListHeaderLayout->addWidget(w);
    headerLayout->addWidget(idHeader);
    headerLayout->addWidget(nameHeader);
    headerLayout->addWidget(prioHeader);
    headerLayout->addWidget(sizeHeader);
    headerLayout->addItem(new QSpacerItem(20,10,QSizePolicy::Minimum, QSizePolicy::Expanding));
    processListHeaderLayout->addWidget(processList);
    processList->setModel(model);
    processList->uniformItemSizes();
    processList->setBatchSize(100);
    processList->setLayoutMode(QListView::Batched);
    infoLayout->addLayout(algorithmusSelector);
    infoLayout->addLayout(algoID);
    infoLayout->addLayout(algoName);
    infoLayout->addLayout(algoWorktime);
    infoLayout->addLayout(algoSize);
    infoLayout->addLayout(processCount);
    algorithmusSelector->addWidget(algoSelectLabel);
    algorithmusSelector->addWidget(algoSelectComboBox);
    centralWidget()->setLayout(mainBox);
    this->statusBar()->addWidget(bar);
    processList->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded );
    connect(model,&ProcessListModel::setProgress,this,&MainWindow::updateProgressBar);
    connect(bar,&QProgressBar::valueChanged,this,&MainWindow::barChanged);

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


void MainWindow::log2Clear()
{
    logBox2->clear();
}


void MainWindow::log2Update(QString string)
{
    //Updating the Log Text Box's content
    logBox2->append(string);

}


void MainWindow::processListUpdate(QList<Process> * inputProcessList, Algorithm * a,bool hasChanged)
{
    if(currentAlgorythm == nullptr || a->getId()!= currentAlgorythm->getId()){
        currentAlgorythm = a;
    }

    if(hasChanged){
        bar->setRange(0,inputProcessList->length());
        bar->reset();
        bar->show();
    }
    // Active Algorithm data Updated
    algoID->setValue(currentAlgorythm->getId());
    algoName->setValue(currentAlgorythm->getName());
    algoWorktime->setValue(QString::number(currentAlgorythm->getWorkTime()) + " ms");
    algoSize->setValue(QString::number(currentAlgorythm->getSize()) + " bytes");

    processCount->setValue(inputProcessList->count());
}


void MainWindow::algorithmusBoxUpdate(QList<QString> inputAlgoList)
{
    //Update the content of the algorithm Drop-Down
    algoSelectComboBox->clear();
    foreach(QString s,inputAlgoList){        
        algoSelectComboBox->addItem(s);
    }
}

void MainWindow::updateProgressBar(int progress)
{
    if( progress <= model->rowCount()){
        bar->setValue(progress);
    }
    if(progress >= model->rowCount()-1){
        bar->hide();
    }
}

void MainWindow::boxChanged(int)
{
    QString selectedName = algoSelectComboBox->currentText();
    emit algorithmusBoxChanged(selectedName);
}

void MainWindow::barChanged(int value)
{
    if(value >= model->rowCount()){
        hasChanged=false;
        bar->setDisabled(true);
        bar->hide();
    }
}

MainWindow::~MainWindow()
{
    if(currentAlgorythm != nullptr){
        delete currentAlgorythm;
    }
    delete algoID;
    delete algoName;
    delete algoWorktime;
    delete algoSize;
    delete processCount;
    delete processList;
    delete algoSelectComboBox;
    delete logBox;
    delete algoSelectLabel;
    delete algorithmusSelector;
    delete infoLayout;
    delete topChildLayout;
    delete topLayout;
    delete mainBox;
    delete ui;

}

