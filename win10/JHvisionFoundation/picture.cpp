#include "picture.h"

Picture::Picture(string picPath):QThread(),picPath(picPath)
{

}
//图像解析主线程
void Picture::run(){
    while(1){
        frame=imread(picname);
        if(frame.empty()){
            break;
        }
        resize(frame,frame,Size(1280,720),0,0,INTER_LINEAR);
        imageBuffer->addFrame(frame);
        qtsleep(40);
    }
}
