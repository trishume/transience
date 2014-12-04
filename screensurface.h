#ifndef HINTMANAGER_H
#define HINTMANAGER_H

#include <QWidget>
#include <QList>
#include <QPoint>
#include <QColor>

struct DotSpec {
    QPoint point;
    QColor color;

    DotSpec() {}
    DotSpec(const QPoint &pt, const QColor &col) : point(pt), color(col) {}
};
Q_DECLARE_METATYPE(DotSpec)

class ScreenSurface : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenSurface(QWidget *parent = 0);
    ~ScreenSurface();

signals:

public slots:
    void testDot();
    void testFrame();
    void createDot(const QPoint &pos, const QColor &color);
    void closeAll();
    void doFrame(const QList<DotSpec> &specList);

protected:
    QList<DotSpec> specs;
    QRect screenRect;

    QPoint randomPoint();
    QColor randomColor();
    QRect screenSize();
};

#endif // HINTMANAGER_H
