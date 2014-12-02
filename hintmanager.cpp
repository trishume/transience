#include "hintmanager.h"
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

HintManager::HintManager(QObject *parent) :
    QObject(parent), widgetList()
{
}

HintManager::~HintManager() {
    closeAll();
}

void HintManager::testDot() {
    createDot(randomPoint(), randomColor());
}

void HintManager::createDot(const QPoint &pos, const QColor &color) {
    DotHint *hint = new DotHint(color);
    hint->show();
    hint->move(pos);
    widgetList << hint;
}

void HintManager::closeAll() {
    while (!widgetList.isEmpty()) {
        QWidget *win = widgetList.takeFirst();
        win->close();
        delete win;
    }
}