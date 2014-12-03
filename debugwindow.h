#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QMainWindow>

namespace Ui {
class DebugWindow;
}
class HintManager;

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = 0);
    ~DebugWindow();

    virtual void closeEvent (QCloseEvent *);

    void setHintMan(HintManager *man);

public slots:
    void manyDots();

private:
    Ui::DebugWindow *ui;
    HintManager *hintMan;
};

#endif // DEBUGWINDOW_H
