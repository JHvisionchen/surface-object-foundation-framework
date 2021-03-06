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
#include <vector>
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
//摄像头的选择，0表示hik，1表示usb
extern int camnum;
//输入数据类型选择，0表示摄像头，1表示视频，2表示图片
extern int inputtype;
//关闭总程序指示
extern bool stopUI;
//图像数据转换
QImage MatToQImage(const Mat&);
//qt下的延时函数
void qtsleep(unsigned int msec);
//获取目录下所有图片的文件名
vector<QString> getImgNames(QString path);

#endif // GLOBALVARIABLE_H
