#include "screensurface.h"
#include "dothint.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QTime>
#include <QPainter>
#include <QPaintEvent>
#include <QScreen>

//#define DEBUG_FILL

ScreenSurface::ScreenSurface(int screen) :
    QWidget(0, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint), specs(), screen(screen)
{
    setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground);
    platformSpecificSetup();
    fillScreen();
}

ScreenSurface::~ScreenSurface() {
    closeAll();
}

void ScreenSurface::fillScreen() {
    QRect screen = screenSize();
    move(screen.x(),screen.y());
    resize(screen.width(),screen.height());
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
        QScreen *srn = QApplication::screens().at(screen);
        screenRect = srn->geometry();
    }
    return screenRect;
}

void ScreenSurface::paintEvent(QPaintEvent *ev) {
    QPainter painter(this);
    painter.setCompositionMode (QPainter::CompositionMode_Source);
    painter.fillRect(ev->rect(), Qt::transparent);
    painter.setCompositionMode (QPainter::CompositionMode_SourceOver);
#ifdef DEBUG_FILL
    painter.fillRect(ev->rect(), QColor(0,255,0,50));
#endif
}
