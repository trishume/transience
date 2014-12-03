#include "hintmanager.h"
#include "dothint.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

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
    QObject(parent), widgetList(), cache()
{
}

HintManager::~HintManager() {
    closeAll();
}

void HintManager::testDot() {
    createDot(randomPoint(), randomColor());
}

void HintManager::createDot(const QPoint &pos, const QColor &color) {
    DotHint *hint;
    if(cache.isEmpty()) {
        hint = new DotHint(color);
    } else {
        hint = cache.takeFirst();
        hint->setColor(color);
        //qDebug() << "hit cache";
    }
    hint->show();
    hint->move(pos);
    widgetList << hint;
}

void HintManager::closeAll() {
    while (!widgetList.isEmpty()) {
        DotHint *win = widgetList.takeFirst();
        win->hide();
        cache << win;
    }
}

void HintManager::clearCache() {
    while (!cache.isEmpty()) {
        QWidget *win = cache.takeFirst();
        win->close();
        delete win;
    }
}
