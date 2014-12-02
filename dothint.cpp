#include "dothint.h"

#include <QPainter>
#include <QPaintEvent>

#define DOT_SIZE 20

DotHint::DotHint(const QColor &col) :
    QWidget(0, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint), grad(NULL), pointColor(NULL)
{
    setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_TransparentForMouseEvents);

    float halfSize = DOT_SIZE / 2.0;
    grad = new QRadialGradient(QPoint(halfSize,halfSize),halfSize);
    pointColor = new QColor();
    setColor(col);
}

DotHint::~DotHint() {
    delete grad;
    delete pointColor;
}

void DotHint::setColor(QColor col) {
    col.setAlpha(0);
    grad->setColorAt(1,col);
    col.setAlpha(200);
    grad->setColorAt(0,col);
    pointColor->setRgb(255 - col.red(), 255 - col.green(), 255 - col.blue(), 255);
    repaint();
}

QSize DotHint::sizeHint() const {
    return QSize(DOT_SIZE, DOT_SIZE);
}

void DotHint::paintEvent(QPaintEvent *ev) {
    QPainter painter(this);
    painter.setCompositionMode (QPainter::CompositionMode_Source);
    painter.fillRect(ev->rect(), Qt::transparent);
    painter.setCompositionMode (QPainter::CompositionMode_SourceOver);

    float halfSize = DOT_SIZE / 2.0;
    painter.fillRect(ev->rect(), *grad);

    painter.fillRect(halfSize-1,halfSize-1,2,2,*pointColor);
}
