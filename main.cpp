#include "debugwindow.h"
#include <QApplication>
#include <QTime>
#include <QDBusConnection>
#include <QDebug>
#include <QDBusMetaType>

#include "screensurface.h"
#include "screensurfaceadapter.h"

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);

    ScreenSurface surf(0); // 0 = Appear on main monitor
    qDBusRegisterMetaType<DotSpec>();
    qDBusRegisterMetaType<QList<DotSpec> >();
    new ScreenSurfaceAdapter(&surf);
    QDBusConnection::sessionBus().registerObject("/ca/thume/transience/screensurface", &surf);
    surf.show();

    if(!QDBusConnection::sessionBus().registerService("ca.thume.transience")) {
        qDebug() << "Couldn't grab DBus service.";
        exit(0);
    }

    DebugWindow w;
    w.setHintMan(&surf);
    w.show();

    return a.exec();
}
