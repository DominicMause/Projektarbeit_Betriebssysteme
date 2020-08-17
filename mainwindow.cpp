#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QListWidget"
#include "QTextEdit"
#include "QLabel"
#include "QComboBox"

QTextEdit *logBox;
QComboBox *algoSelectComboBox;
QListWidget *processList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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
    processList = new QListWidget();
    logBox = new QTextEdit();
    QLabel *algoSelectLabel = new QLabel("Algorithmus");
    algoSelectComboBox = new QComboBox();
    algoSelectComboBox->setPlaceholderText("empty");
    connect(algoSelectComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(algorithmusBoxChanged(int)));

    mainBox->addLayout(topLayout);
    mainBox->addWidget(logBox);
    topLayout->addLayout(topChildLayout);
    topChildLayout->addLayout(infoLayout);
    topChildLayout->addWidget(processList);

    infoLayout->addLayout(algorithmusSelector);
    algorithmusSelector->addWidget(algoSelectLabel);
    algorithmusSelector->addWidget(algoSelectComboBox);
    centralWidget()->setLayout(mainBox);

    //slot Tests

    logUpdate("Test 123");

}


void MainWindow::logClear()
{
    logBox->clear();
}

void MainWindow::logUpdate(QString string)
{
    logBox->append(string);
}

void MainWindow::processListUpdate()
{
    //Update the Process list
}

void MainWindow::algorithmusBoxUpdate()
{
    //Update the content of the algorithm Drop-Down
}





MainWindow::~MainWindow()
{
    delete ui;
}

