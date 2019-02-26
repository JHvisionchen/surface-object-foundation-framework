#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "globalvariable.h"
#include "inputdata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //开始接受图像数据
    void startReceiveData();
    //停止接受图像数据
    void stopReceiveData();

private slots:
    //刷新显示图像
    void updateFrame(const QImage &frame);

private:
    Ui::MainWindow *ui;
    //操作数据接口
    InputData *inputdata;
};

#endif // MAINWINDOW_H
