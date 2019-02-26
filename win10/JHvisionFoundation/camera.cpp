#include "camera.h"

Camera::Camera()
{

}
//连接摄像机并开启图像捕捉线程
bool Camera::connectToCamera(int hikThreadPrio){
    hikThread=new Hikvision();
    //开启hik摄像头读取线程
    hikThread->start((QThread::Priority)hikThreadPrio);
    return true;
}
//连接cam摄像机并开启图像捕捉线程
bool Camera::connectTousbcam(int camThreadPrio){
    usbThread=new UsbCam();
    usbThread->start((QThread::Priority)camThreadPrio);
    return true;
}
