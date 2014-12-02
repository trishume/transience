#ifndef DOTHINT_H
#define DOTHINT_H

#include <QWidget>
#include <QRadialGradient>
#include <QColor>

class DotHint : public QWidget
{
    Q_OBJECT
public:
    explicit DotHint(const QColor &col);
    ~DotHint();
    virtual QSize sizeHint() const;
    virtual void paintEvent(QPaintEvent *ev);

signals:

public slots:
    void setColor(QColor col);

protected:
    QRadialGradient *grad;
    QColor *pointColor;
};

#endif // DOTHINT_H
