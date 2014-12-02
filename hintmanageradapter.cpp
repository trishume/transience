#include "hintmanageradapter.h"
#include "hintmanager.h"

#include <QPoint>
#include <QColor>

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
