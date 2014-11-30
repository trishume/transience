#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QMainWindow>

namespace Ui {
class DebugWindow;
}

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = 0);
    ~DebugWindow();

public slots:
    void testDot();
    void createDot(const QPoint &pos, const QColor &color);

private:
    Ui::DebugWindow *ui;
};

#endif // DEBUGWINDOW_H
