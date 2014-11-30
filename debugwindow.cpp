#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "dothint.h"

#include <QApplication>
#include <QDesktopWidget>

QPoint randomPoint() {
    QDesktopWidget widget;
    QRect screenSize = widget.availableGeometry(widget.primaryScreen());
    int x = qrand() % (((screenSize.x() + screenSize.width()) + 1) - screenSize.x()) + screenSize.x();
    int y = qrand() % (((screenSize.y() + screenSize.height()) + 1) - screenSize.y()) + screenSize.y();
    return QPoint(x,y);
}

QColor randomColor() {
    return QColor::fromHsv(qrand() % 255, 255,255);
}

DebugWindow::DebugWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(testDot()));
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::testDot() {
    createDot(randomPoint(), randomColor());
}

void DebugWindow::createDot(const QPoint &pos, const QColor &color) {
    DotHint *hint = new DotHint(color);
    hint->show();
    hint->move(pos);
}
