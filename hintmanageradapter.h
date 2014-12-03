#ifndef HINTMANAGERADAPTER_H
#define HINTMANAGERADAPTER_H

#include "hintmanager.h"

#include <QDBusAbstractAdaptor>
#include <QDBusArgument>
#include <QList>

QDBusArgument &operator<<(QDBusArgument &argument, const DotSpec &mystruct);
const QDBusArgument &operator>>(const QDBusArgument &argument, DotSpec &mystruct);

class HintManagerAdapter : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ca.thume.transience.hintmanager")
public:
    explicit HintManagerAdapter(HintManager *man);

signals:

public slots:
    void createDot(int x, int y, int r, int g, int b);
    Q_NOREPLY void testDot();
    void closeAllDots();
    void testPing();

    void doFrame(const QList<DotSpec> &specList);
private:
    HintManager *hintMan;

};

#endif // HINTMANAGERADAPTER_H
