#include "mainwindow.h"
#include "ui_mainwindow.h"
//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,30,1920,750);
    connect(ui->startBtn,SIGNAL(clicked(bool)),this,SLOT(startReceiveData()));
    connect(ui->stopBtn,SIGNAL(clicked(bool)),this,SLOT(stopReceiveData()));
}
//开始接受图像数据
void MainWindow::startReceiveData(){
    inputdata=new InputData();
    connect(inputdata->processThread,SIGNAL(newFrame(QImage)),this,SLOT(updateFrame(QImage)));
}
//停止接受图像数据
void MainWindow::stopReceiveData(){
    //停止usb摄像头的循环指令
    stopUI=true;
    inputdata->camera->usbThread->quit();
    inputdata->camera->usbThread->wait();
    delete inputdata->camera->usbThread;
    //delete inputdata;
}
//刷新显示图像
void MainWindow::updateFrame(const QImage &frame){
    ui->showLabel->setPixmap(QPixmap::fromImage(frame));
}
//析构函数
MainWindow::~MainWindow()
{
    //停止usb摄像头的循环指令
    stopUI=true;
    //输入摄像头数据
    if(inputtype==0){
        if(camnum==0){
            inputdata->camera->hikThread->quit();
            inputdata->camera->hikThread->wait();
            delete inputdata->camera->hikThread;
        }
        else{
            inputdata->camera->usbThread->quit();
            inputdata->camera->usbThread->wait();
            delete inputdata->camera->usbThread;
        }
    }
    /*
    //输入视频数据
    else if(inputtype==1){
        inputdata->videoThread->quit();
        inputdata->videoThread->wait();
        delete inputdata->videoThread;
    }
    //输入图片数据
    else{
        inputdata->picThread->quit();
        inputdata->picThread->wait();
        delete inputdata->picThread;
    }
    inputdata->processThread->quit();
    inputdata->processThread->wait();
    delete inputdata->processThread;
    */
    delete inputdata;
    delete ui;
}
