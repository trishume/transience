#ifndef HINTMANAGERADAPTER_H
#define HINTMANAGERADAPTER_H

#include "screensurface.h"

#include <QDBusAbstractAdaptor>
#include <QDBusArgument>
#include <QList>

QDBusArgument &operator<<(QDBusArgument &argument, const DotSpec &mystruct);
const QDBusArgument &operator>>(const QDBusArgument &argument, DotSpec &mystruct);

class ScreenSurfaceAdapter : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ca.thume.transience.screensurface")
public:
    explicit ScreenSurfaceAdapter(ScreenSurface *surf);

signals:

public slots:
    void createDot(int x, int y, int r, int g, int b);
    Q_NOREPLY void testDot();
    void closeAllDots();
    void testPing();

    void doFrame(const QList<DotSpec> &specList);
private:
    ScreenSurface *surf;

};

#endif // HINTMANAGERADAPTER_H
