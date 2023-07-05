#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    videoWidget = new QVideoWidget(this);
    this->setCentralWidget(videoWidget);

    camera.start();
    mediaCaptureSession.setCamera(&camera);
    mediaCaptureSession.setVideoOutput(videoWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    if(this->isFullScreen())
    {
        this->showNormal();
        ui->statusbar->setVisible(true);
    }
    else
    {
        this->showFullScreen();
        ui->statusbar->setVisible(false);
    }
}

