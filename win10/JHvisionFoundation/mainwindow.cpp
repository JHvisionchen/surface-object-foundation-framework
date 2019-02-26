#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startBtn,SIGNAL(clicked(bool)),this,SLOT(startReceiveData()));
}
void MainWindow::startReceiveData(){
    inputdata=new InputData();
    qDebug()<<"123";
    connect(inputdata->processThread,SIGNAL(newFrame(QImage)),this,SLOT(updateFrame(QImage)));
}

void MainWindow::stopReceiveData(){

}

void MainWindow::updateFrame(const QImage &frame){
    qDebug()<<"143";
    ui->showLabel->setPixmap(QPixmap::fromImage(frame));
}

MainWindow::~MainWindow()
{
    delete ui;
}
