#ifndef HIKVISION_H
#define HIKVISION_H

#include "globalvariable.h"

class Hikvision : public QThread
{
public:
    Hikvision();

protected:
    //图像解析主线程
    void run();
};

#endif // HIKVISION_H
