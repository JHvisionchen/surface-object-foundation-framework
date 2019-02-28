#include "picture.h"

Picture::Picture(QString picPath):QThread(),picPath(picPath)
{

}
//图像解析主线程
void Picture::run(){
    imgNames=getImgNames(picPath);

    uint i=0;
    while(i<imgNames.size()){
        qDebug()<<imgNames[i];
        picname=imgNames[i].toStdString();
        frame=imread(picname);
        resize(frame,frame,Size(1280,720),0,0,INTER_LINEAR);
        imageBuffer->addFrame(frame);
        qtsleep(40);
        i++;
    }
}
