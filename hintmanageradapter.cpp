#include "hintmanageradapter.h"
#include "hintmanager.h"

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

HintManagerAdapter::HintManagerAdapter(HintManager *parent) :
    QDBusAbstractAdaptor(parent), hintMan(parent)
{
}

void HintManagerAdapter::createDot(int x, int y, int r, int g, int b) {
    hintMan->createDot(QPoint(x,y),QColor(r,g,b));
}

void HintManagerAdapter::closeAllDots() {
    hintMan->closeAll();
}

void HintManagerAdapter::testDot() {
    hintMan->testDot();
}

void HintManagerAdapter::testPing() {
    qDebug() << "ping";
}

void HintManagerAdapter::doFrame(const QList<DotSpec> &specList) {
    for(int i = 0; i < specList.length(); ++i) {
        DotSpec spec = specList[i];
        qDebug() << "got spec: " << spec.x << spec.y << spec.r << spec.g << spec.b;
    }
}
