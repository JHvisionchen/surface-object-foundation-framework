#include "camera.h"

Camera::Camera()
{

}
//连接摄像机并开启图像捕捉线程
bool Camera::connectToCamera(int hikThreadPrio){
    hikThread=new Hikvision();
    hikThread->start((QThread::Priority)hikThreadPrio);
    return true;
}
