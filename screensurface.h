#ifndef HINTMANAGER_H
#define HINTMANAGER_H

#include <QObject>
#include <QList>
#include <QPoint>
#include <QColor>

struct DotSpec {
    int x,y,r,g,b;

    DotSpec() {}
    DotSpec(int x, int y, int r, int g, int b) : x(x), y(y), r(r), g(g), b(b) {}
    QPoint getPoint() const {return QPoint(this->x,this->y);}
    QColor getColor() const {return QColor(this->r,this->g,this->b);}
};
Q_DECLARE_METATYPE(DotSpec)

class DotHint;
class ScreenSurface : public QObject
{
    Q_OBJECT
public:
    explicit ScreenSurface(QObject *parent = 0);
    ~ScreenSurface();

signals:

public slots:
    void testDot();
    void testFrame();
    void createDot(const QPoint &pos, const QColor &color);
    void closeAll();
    void doFrame(const QList<DotSpec> &specList);

protected:
    QList<DotHint*> widgetList;
};

#endif // HINTMANAGER_H
