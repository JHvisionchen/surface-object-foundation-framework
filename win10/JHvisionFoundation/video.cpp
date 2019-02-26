#include "video.h"

Video::Video(string videoPath):QThread(),videoPath(videoPath)
{

}

//图像解析主线程
void Video::run(){
    videoname.open(videoPath);
    while(1){
        videoname>>frame;
        if(frame.empty()){
            break;
        }
        resize(frame,frame,Size(1280,720),0,0,INTER_LINEAR);
        imageBuffer->addFrame(frame);
        qtsleep(40);
    }
    videoname.release();
}
