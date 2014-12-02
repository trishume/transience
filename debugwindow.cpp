#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "hintmanager.h"

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
}

void DebugWindow::closeEvent (QCloseEvent *) {
    hintMan->closeAll();
}
