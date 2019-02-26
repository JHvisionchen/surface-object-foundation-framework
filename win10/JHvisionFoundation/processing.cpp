#include "processing.h"

processing::processing()
{

}

void processing::run(){
    while(1)
    {
        /////////////////////////////////、
        // Get frame from queue, store in currentFrame, set ROI
        currentFrame=Mat(imageBuffer->getFrame());//从缓冲区中取出一帧
        //currentFrame=imread("Penguins.jpg");
        updateMembersMutex.lock();
        //以下的函数或者程序可以用来对每一帧图像进行处理
        frame=MatToQImage(currentFrame);
        updateMembersMutex.unlock();
        //发出信号，通知GUI线程有新处理好的一帧
        emit newFrame(frame);
    }
    qDebug() << "Stopping processing thread...";
}
