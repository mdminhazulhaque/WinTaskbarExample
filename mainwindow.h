#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShowEvent>
#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *e);

private slots:
    void indeterminateState(bool indeterminate);

private:
    Ui::MainWindow *ui;
    QWinTaskbarButton *taskbarButton;
    QWinTaskbarProgress *taskbarProgress;
};

#endif // MAINWINDOW_H
