#ifndef USBCAM_H
#define USBCAM_H

#include "globalvariable.h"

class UsbCam : public QThread
{
public:
    UsbCam();

protected:
    //图像解析主线程
    void run();
    //摄像头对象
    VideoCapture usbcam;
    //采集的图像帧
    Mat frame;
};

#endif // USBCAM_H
