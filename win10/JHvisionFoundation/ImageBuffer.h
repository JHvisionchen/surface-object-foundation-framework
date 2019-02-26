#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

// Qt header files
#include <QMutex>
#include <QQueue>
#include <QSemaphore>
#include <QDebug>
// OpenCV header files
#include <opencv/highgui.h>

using namespace cv;

class ImageBuffer
{

public:
    ImageBuffer(int size, bool dropFrame);
    //向缓冲区队列中添加帧
    void addFrame(const Mat& frame);
    //从缓冲区队列中拿走帧
    Mat getFrame();
    //清空缓冲区
    void clearBuffer();
    //获取缓存区的大小
    int getSizeOfImageBuffer();

private:
    //保护锁
    QMutex imageQueueProtect;
    //帧缓冲区队列
    QQueue<Mat> imageQueue;
    QSemaphore *freeSlots;
    QSemaphore *usedSlots;
    QSemaphore *clearBuffer1;
    QSemaphore *clearBuffer2;
    int bufferSize;
    //是否允许丢帧的标志
    bool dropFrame;
};

#endif // IMAGEBUFFER_H
