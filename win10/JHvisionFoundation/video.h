#ifndef VIDEO_H
#define VIDEO_H

#include "globalvariable.h"

class Video : public QThread
{
public:
    Video(string videoPath);

protected:
    //图像解析主线程
    void run();
    //视频对象
    VideoCapture videoname;
    //采集的图像帧
    Mat frame;
    //视频路径
    string videoPath;
};

#endif // VIDEO_H
