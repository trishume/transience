#include "screensurface.h"
#include "dothint.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QTime>
#include <QPainter>
#include <QPaintEvent>
#include <QScreen>
#include <QRadialGradient>

//#define DEBUG_FILL

static const int dotRadius = 10;

ScreenSurface::ScreenSurface(int screen) :
    QWidget(0, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint), specs(), screen(screen)
{
    setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground);
    platformSpecificSetup();

    QScreen *srn = QApplication::screens().at(screen);
    screenRect = srn->geometry();
    fillScreen();
}

ScreenSurface::~ScreenSurface() {
    closeAll();
}

void ScreenSurface::fillScreen() {
    move(screenRect.x(),screenRect.y());
    resize(screenRect.width(),screenRect.height());
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
    DotSpec spec(pos,color);
    specs << spec;
    repaint();
}

void ScreenSurface::closeAll() {
    specs.clear();
    repaint();
}

void ScreenSurface::doFrame(const QList<DotSpec> &specList) {
    specs = specList;
    for(int i = 0; i < specs.length(); ++i) {
        DotSpec spec = specs[i];
        qDebug() << "got spec: " << spec.point << spec.color;
    }
    repaint();
}

QPoint ScreenSurface::randomPoint() {
    int x = qrand() % (((screenRect.x() + screenRect.width()) + 1) - screenRect.x()) + screenRect.x();
    int y = qrand() % (((screenRect.y() + screenRect.height()) + 1) - screenRect.y()) + screenRect.y();
    return QPoint(x,y);
}

QColor ScreenSurface::randomColor() {
    return QColor::fromHsv(qrand() % 255, 255,255);
}

// DRAWING LOGIC

void ScreenSurface::drawDot(QPainter &painter, const DotSpec &dot) {
    QColor col = dot.color;
    QColor pointColor(255 - col.red(), 255 - col.green(), 255 - col.blue(), 255);
    QRadialGradient grad(dot.point,dotRadius);
    col.setAlpha(0);
    grad.setColorAt(1,col);
    col.setAlpha(200);
    grad.setColorAt(0,col);

    QRect rect(dot.point.x() - dotRadius, dot.point.y() - dotRadius, dotRadius*2, dotRadius*2);
    painter.fillRect(rect, grad);
    painter.fillRect(dot.point.x()-1,dot.point.y()-1,2,2,pointColor);
}

void ScreenSurface::paintEvent(QPaintEvent *ev) {
    QPainter painter(this);

    // Filling with transparent doesn't clear the screen with normal overlay logic :P
    painter.setCompositionMode (QPainter::CompositionMode_Source);
    painter.fillRect(ev->rect(), Qt::transparent);
    painter.setCompositionMode (QPainter::CompositionMode_SourceOver);

#ifdef DEBUG_FILL
    painter.fillRect(ev->rect(), QColor(0,255,0,50));
#endif

    for(int i = 0; i < specs.length(); ++i) {
        drawDot(painter, specs[i]);
    }
}
