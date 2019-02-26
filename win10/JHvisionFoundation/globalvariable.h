#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H
// Qt header files
#include <QtGui>
#include <QThread>
#include <QDebug>
#include <iostream>
//hikvision头文件
#include "HCNetSDK.h"
#include "plaympeg4.h"
// OpenCV header files
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
// imagebuffer
#include "ImageBuffer.h"

using namespace cv;
using namespace std;

// 图像缓存区
extern ImageBuffer *imageBuffer;
// 摄像机云台控制
extern int pantilt;
extern bool forLeft;
extern bool forRight;
extern bool forUp;
extern bool forDown;
// 摄像机焦距控制
extern bool forZoomIn;
extern bool forZoomOut;

QImage MatToQImage(const Mat&);

#endif // GLOBALVARIABLE_H
