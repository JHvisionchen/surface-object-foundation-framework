#include "mainwindow.h"
#include "ui_mainwindow.h"
//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startBtn,SIGNAL(clicked(bool)),this,SLOT(startReceiveData()));
}
//开始接受图像数据
void MainWindow::startReceiveData(){
    inputdata=new InputData();
    connect(inputdata->processThread,SIGNAL(newFrame(QImage)),this,SLOT(updateFrame(QImage)));
}
//停止接受图像数据
void MainWindow::stopReceiveData(){

}
//刷新显示图像
void MainWindow::updateFrame(const QImage &frame){
    ui->showLabel->setPixmap(QPixmap::fromImage(frame));
}
//析构函数
MainWindow::~MainWindow()
{
    stopUI=true;
    delete ui;
}
