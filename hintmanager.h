#ifndef HINTMANAGER_H
#define HINTMANAGER_H

#include <QObject>
#include <QList>

class HintManager : public QObject
{
    Q_OBJECT
public:
    explicit HintManager(QObject *parent = 0);
    ~HintManager();

signals:

public slots:
    void testDot();
    void createDot(const QPoint &pos, const QColor &color);
    void closeAll();

protected:
    QList<QWidget*> widgetList;
};

#endif // HINTMANAGER_H
