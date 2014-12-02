#ifndef HINTMANAGERADAPTER_H
#define HINTMANAGERADAPTER_H

#include <QDBusAbstractAdaptor>

class HintManager;
class HintManagerAdapter : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ca.thume.transience.hintmanager")
public:
    explicit HintManagerAdapter(HintManager *man);

signals:

public slots:
    void createDot(int x, int y, int r, int g, int b);
    void testDot();
    void closeAllDots();
private:
    HintManager *hintMan;

};

#endif // HINTMANAGERADAPTER_H
