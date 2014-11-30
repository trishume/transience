#include "debugwindow.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);
    DebugWindow w;
    w.show();

    return a.exec();
}
