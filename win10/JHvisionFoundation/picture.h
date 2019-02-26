#ifndef PICTURE_H
#define PICTURE_H

#include "globalvariable.h"

class Picture : public QThread
{
public:
    Picture(string picPath);

protected:
    //图像解析主线程
    void run();
    //采集的图像帧
    Mat frame;
    //图片路径
    string picPath;
    //图片名称
    string picname;
};

#endif // PICTURE_H
