#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QObject>
#include "globalvariable.h"
#include "camera.h"
#include "processing.h"
#include "video.h"
#include "picture.h"

class InputData : public QObject
{
    Q_OBJECT

public:
    InputData();
    //摄像头输入
    void cameraInput();
    //视频输入
    void videoInput();
    //图片输入
    void pictureInput();
    //处理线程对象
    processing *processThread;
    //摄像头对象
    Camera *camera;
    //视频对象
    Video *videoThread;
    //图片对象
    Picture *picThread;

private:
    QImage frame;
    bool cameraStarted;

};

#endif // INPUTDATA_H
