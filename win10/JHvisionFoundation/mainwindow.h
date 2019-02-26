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
    void startReceiveData();
    void stopReceiveData();

private slots:
    void updateFrame(const QImage &frame);

private:
    Ui::MainWindow *ui;
    InputData *inputdata;
};

#endif // MAINWINDOW_H
