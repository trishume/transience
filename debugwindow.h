#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QMainWindow>

namespace Ui {
class DebugWindow;
}
class ScreenSurface;

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = 0);
    ~DebugWindow();

    virtual void closeEvent (QCloseEvent *);

    void setHintMan(ScreenSurface *man);

public slots:
    void manyDots();

private:
    Ui::DebugWindow *ui;
    ScreenSurface *hintMan;
};

#endif // DEBUGWINDOW_H
