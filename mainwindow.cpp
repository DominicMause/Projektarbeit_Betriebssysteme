#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"
#include "QElapsedTimer"




/**
 * @brief This class is responsible for the UI.
 *
 * @param parent not used
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setFixedSize(800,800);
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


    processListHeaderLayout = new QVBoxLayout;



    view = new QListView;
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
    headerLayout->addItem(new QSpacerItem(45,10,QSizePolicy::Minimum, QSizePolicy::Expanding));
    processListHeaderLayout->addWidget(view);
    view->setModel(model);
    view->uniformItemSizes();
    view->setBatchSize(100);
    view->setLayoutMode(QListView::Batched);
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

/**
 * @brief This Slot clears the left Log in the UI.
 *
 */
void MainWindow::logClear()
{
    logBox->clear();
}

/**
 * @brief This Slot recives a string that gets appended to the left Log.
 *
 * @param string String that gets appended.
 */
void MainWindow::logUpdate(QString string)
{
    //Updating the Log Text Box's content
    logBox->append(string);

}

/**
 * @brief This Slot clears the right Log in the UI.
 *
 */
void MainWindow::log2Clear()
{
    logBox2->clear();
}

/**
 * @brief This Slot recives a string that gets appended to the right Log.
 *
 * @param string string String that gets appended.
 */
void MainWindow::log2Update(QString string)
{
    //Updating the Log Text Box's content
    logBox2->append(string);

}

/**
 * @brief Calling this Slot Updates the processList and Algorithm Information based on the Parameters
 *
 * @param inputProcessList Recieves a list of type Process that gets Displayed in the processList dependend on the hasChanged Parameter.
 * @param a overrides the Selected Algorithm.
 * @param hasChanged Marks if the contents of inputProcessList differ from the previous version to reduce performance of the UI due to unnecessary reloads of the UI.
 */
void MainWindow::processListUpdate(QList<Process> * inputProcessList, Algorithm * a,bool hasChanged)
{
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

/**
 * @brief This Slot is for stetting the items of the Algorithm Select combobox.
 *
 * @param inputAlgoList Recieves a list of Strings to be displayed in the Algorithm select Combobox menu.
 */
void MainWindow::algorithmusBoxUpdate(QList<QString> inputAlgoList)
{
    //Update the content of the algorithm Drop-Down
    foreach(QString s,inputAlgoList){        
        algoSelectComboBox->addItem(s);
    }
}


/**
 * @brief This Signal gets emited if another Algorithm in the Algorithm Select Combobox gets selected.

 */
void MainWindow::boxChanged(int)
{
    QString selectedName = algoSelectComboBox->currentText();
    emit algorithmusBoxChanged(selectedName);
}

/**
 * @brief destructor of the UI.
 *
 */
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

