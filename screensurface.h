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
    explicit ScreenSurface(int screen);
    ~ScreenSurface();

signals:

public slots:
    void testDot();
    void testFrame();
    void createDot(const QPoint &pos, const QColor &color);
    void closeAll();
    void doFrame(const QList<DotSpec> &specList);

    void fillScreen();

protected:
    QList<DotSpec> specs;
    QRect screenRect;
    int screen;

    QPoint randomPoint();
    QColor randomColor();

    void platformSpecificSetup();
    void drawDot(QPainter &painter, const DotSpec &dot);
    virtual void paintEvent(QPaintEvent *ev);
};

#endif // HINTMANAGER_H
