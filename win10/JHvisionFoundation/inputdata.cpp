#include "inputdata.h"
//构造函数
InputData::InputData()
{
    cameraStarted=false;
    //输入摄像头数据
    if(inputtype==0){
        cameraInput();
    }
    //输入视频数据
    else if(inputtype==1){
        videoInput();
    }
    //输入图片数据
    else{

    }
}
//摄像头输入
void InputData::cameraInput(){
    camera=new Camera();
    processThread=new processing();
    if(camnum==0){
        cameraStarted=camera->connectToCamera(7);
    }
    else{
        cameraStarted=camera->connectTousbcam(7);
    }
    processThread->start((QThread::Priority)7);

}
//视频输入
void InputData::videoInput(){
    videoThread=new Video("./backlight01.avi");
    videoThread->start((QThread::Priority)7);
    processThread=new processing();
    processThread->start((QThread::Priority)7);
}
//图片输入
void InputData::pictureInput(){

}

