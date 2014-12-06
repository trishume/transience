#include "screensurfaceadapter.h"
#include "screensurface.h"

#include <QPoint>
#include <QColor>
#include <QDebug>

QDBusArgument &operator<<(QDBusArgument &argument, const DotSpec &spec)
{
    argument.beginStructure();
    argument << spec.point.x() << spec.point.y() << spec.color.red() << spec.color.red() << spec.color.blue();
    argument.endStructure();
    return argument;
}

// Retrieve the MyStructure data from the D-Bus argument
const QDBusArgument &operator>>(const QDBusArgument &argument, DotSpec &spec)
{
    int x,y,r,g,b;
    argument.beginStructure();
    argument >> x >> y >> r >> g >> b;
    argument.endStructure();

    spec.point.setX(x);
    spec.point.setY(y);
    spec.color.setRed(r);
    spec.color.setGreen(g);
    spec.color.setBlue(b);

    return argument;
}

ScreenSurfaceAdapter::ScreenSurfaceAdapter(ScreenSurface *parent) :
    QDBusAbstractAdaptor(parent), surf(parent)
{
}

void ScreenSurfaceAdapter::createDot(int x, int y, int r, int g, int b) {
    surf->createDot(QPoint(x,y),QColor(r,g,b));
}

void ScreenSurfaceAdapter::closeAllDots() {
    surf->closeAll();
}

void ScreenSurfaceAdapter::testDot() {
    surf->testDot();
}

void ScreenSurfaceAdapter::testPing() {
    qDebug() << "ping";
}

void ScreenSurfaceAdapter::doFrame(const QList<DotSpec> &specList) {
    surf->doFrame(specList);
}
