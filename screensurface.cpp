#include "screensurface.h"
#include "dothint.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QTime>

ScreenSurface::ScreenSurface(QWidget *parent) :
    QWidget(parent), specs()
{

}

ScreenSurface::~ScreenSurface() {
    closeAll();
}

void ScreenSurface::testDot() {
    createDot(randomPoint(), randomColor());
//    createDot(QPoint(100,100),randomColor());
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
    DotSpec spec(pos,color);
    specs << spec;
}

void ScreenSurface::closeAll() {
    specs.clear();
}

void ScreenSurface::doFrame(const QList<DotSpec> &specList) {
    specs = specList;
}

QPoint ScreenSurface::randomPoint() {
    QRect screenRect = screenSize();
    int x = qrand() % (((screenRect.x() + screenRect.width()) + 1) - screenRect.x()) + screenRect.x();
    int y = qrand() % (((screenRect.y() + screenRect.height()) + 1) - screenRect.y()) + screenRect.y();
    return QPoint(x,y);
}

QColor ScreenSurface::randomColor() {
    return QColor::fromHsv(qrand() % 255, 255,255);
}

QRect ScreenSurface::screenSize() {
    if(screenRect.width() == 0) {
        QDesktopWidget widget;
        screenRect = widget.availableGeometry(widget.primaryScreen());
    }
    return screenRect;
}
