#include "screensurfaceadapter.h"
#include "screensurface.h"

#include <QPoint>
#include <QColor>
#include <QDebug>

QDBusArgument &operator<<(QDBusArgument &argument, const DotSpec &spec)
{
    argument.beginStructure();
    argument << spec.x << spec.y << spec.r << spec.g << spec.b;
    argument.endStructure();
    return argument;
}

// Retrieve the MyStructure data from the D-Bus argument
const QDBusArgument &operator>>(const QDBusArgument &argument, DotSpec &spec)
{
    argument.beginStructure();
    argument >> spec.x >> spec.y >> spec.r >> spec.g >> spec.b;
    argument.endStructure();
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
    for(int i = 0; i < specList.length(); ++i) {
        DotSpec spec = specList[i];
        qDebug() << "got spec: " << spec.x << spec.y << spec.r << spec.g << spec.b;
    }
}
