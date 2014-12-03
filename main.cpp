#include "debugwindow.h"
#include <QApplication>
#include <QTime>
#include <QDBusConnection>
#include <QDebug>
#include <QDBusMetaType>

#include "hintmanager.h"
#include "hintmanageradapter.h"

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);

    HintManager hintMan;
    qDBusRegisterMetaType<DotSpec>();
    qDBusRegisterMetaType<QList<DotSpec> >();
    new HintManagerAdapter(&hintMan);
    QDBusConnection::sessionBus().registerObject("/ca/thume/transience/hintmanager", &hintMan);

    if(!QDBusConnection::sessionBus().registerService("ca.thume.transience")) {
        qDebug() << "Couldn't grab DBus service.";
        exit(0);
    }

    DebugWindow w;
    w.setHintMan(&hintMan);
    w.show();

    return a.exec();
}
