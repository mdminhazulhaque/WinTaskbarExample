#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/appicon"));

    taskbarButton = new QWinTaskbarButton(this);
    taskbarButton->setWindow(this->windowHandle());
    taskbarButton->setOverlayIcon(QIcon(":/overlay"));

    taskbarProgress = taskbarButton->progress();

    connect(ui->slider, SIGNAL(valueChanged(int)), taskbarProgress, SLOT(setValue(int)));
    connect(ui->checkBox, SIGNAL(clicked(bool)), taskbarProgress, SLOT(setVisible(bool)));
    connect(ui->indeterminate, SIGNAL(clicked(bool)), this, SLOT(indeterminateState(bool)));
    connect(ui->normal, SIGNAL(clicked()), taskbarProgress, SLOT(resume()));
    connect(ui->paused, SIGNAL(clicked()), taskbarProgress, SLOT(pause()));
    connect(ui->stopped, SIGNAL(clicked()), taskbarProgress, SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *e)
{
#ifdef Q_OS_WIN32
    taskbarButton->setWindow(windowHandle());
#endif
    e->accept();
}

void MainWindow::indeterminateState(bool indeterminate)
{
    if(indeterminate)
    {
        taskbarProgress->setMinimum(0);
        taskbarProgress->setMaximum(0);
    }
    else
    {
        taskbarProgress->setMinimum(0);
        taskbarProgress->setMaximum(100);
    }
}
