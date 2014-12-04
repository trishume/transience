#include "screensurface.h"
#include "dothint.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QTime>

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

ScreenSurface::ScreenSurface(QObject *parent) :
    QObject(parent), widgetList()
{
}

ScreenSurface::~ScreenSurface() {
    closeAll();
}

void ScreenSurface::testDot() {
    createDot(randomPoint(), randomColor());
}

void ScreenSurface::testFrame() {
    QTime myTimer;
    myTimer.start();
    QList<DotSpec> list;
    for(int i = 0; i < 10; ++i) {
        QColor col = randomColor();
        QPoint pt = randomPoint();
        DotSpec spec(pt,col);
        list << spec;
    }
    doFrame(list);
    int nMilliseconds = myTimer.elapsed();
    qDebug() << "Did frame in ms: " << nMilliseconds;
}

void ScreenSurface::createDot(const QPoint &pos, const QColor &color) {
    DotHint *hint = new DotHint(color);
    hint->show();
    hint->move(pos);
    widgetList << hint;
}

void ScreenSurface::closeAll() {
    while (!widgetList.isEmpty()) {
        DotHint *win = widgetList.takeFirst();
        win->close();
        delete win;
    }
}

void ScreenSurface::doFrame(const QList<DotSpec> &specList) {
    int common = std::min(specList.length(), widgetList.length());
    qDebug() << "moving common widgets: " << common;
    // reuse widgets on the screen
    for(int i = 0; i < common; ++i) {
        DotHint *hint = widgetList[i];
        DotSpec spec = specList[i];
        hint->setColor(spec.color);
        hint->move(spec.point);
    }
    // deal with the difference
    int diff = specList.length() - widgetList.length();
    if(diff > 0) { // more specs than widgets, create new widgets
        for(int i = widgetList.length(); i < specList.length(); ++i) {
            DotSpec spec = specList[i];
            createDot(spec.point,spec.color);
        }
    } else if(diff < 0) { // more widgets than specs, close widgets
        for(int i = 0; i < -diff; ++i) {
            DotHint *win = widgetList.takeLast();
            win->close();
            delete win;
        }
    }
}
