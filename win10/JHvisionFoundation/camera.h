#ifndef CAMERA_H
#define CAMERA_H

#include "globalvariable.h"
#include "hikvision.h"
#include "usbcam.h"

class Camera
{
public:
    Camera();
    //连接hik摄像机并开启图像捕捉线程
    bool connectToCamera(int capThreadPrio);
    //连接cam摄像机并开启图像捕捉线程
    bool connectTousbcam(int camThreadPrio);
    //hikvision摄像头对象
    Hikvision *hikThread;
    //usb摄像头对象
    UsbCam *usbThread;

private:

};

#endif // CAMERA_H
