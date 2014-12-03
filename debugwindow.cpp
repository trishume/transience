#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "hintmanager.h"

#include <QDebug>
#include <QTime>

DebugWindow::DebugWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DebugWindow), hintMan(NULL)
{
    ui->setupUi(this);
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::setHintMan(HintManager *man) {
    hintMan = man;
    QObject::connect(ui->pushButton, SIGNAL(clicked()),hintMan,SLOT(testDot()));
    QObject::connect(ui->closeDotsButton, SIGNAL(clicked()),hintMan,SLOT(closeAll()));
    QObject::connect(ui->clearCache, SIGNAL(clicked()),hintMan,SLOT(clearCache()));
    QObject::connect(ui->manyDots, SIGNAL(clicked()),this,SLOT(manyDots()));
}

void DebugWindow::closeEvent (QCloseEvent *) {
    hintMan->closeAll();
}

void DebugWindow::manyDots() {
    QTime myTimer;
    myTimer.start();
    for(int i = 0; i < 50; ++i) hintMan->testDot();
    int nMilliseconds = myTimer.elapsed();
    qDebug() << "Opened windows in ms: " << nMilliseconds;
}
