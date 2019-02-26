#ifndef CAMERA_H
#define CAMERA_H

#include "globalvariable.h"
#include "hikvision.h"

class Camera
{
public:
    Camera();
    //连接摄像机并开启图像捕捉线程
    bool connectToCamera(int capThreadPrio);

private:
    Hikvision *hikThread;
};

#endif // CAMERA_H
