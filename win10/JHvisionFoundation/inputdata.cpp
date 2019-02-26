#include "inputdata.h"

InputData::InputData()
{
    cameraStarted=false;
    cameraInput();
}

void InputData::cameraInput(){
    camera=new Camera();
    processThread=new processing();

    cameraStarted=camera->connectToCamera(7);
    processThread->start((QThread::Priority)7);

}

void InputData::videoInput(){

}

void InputData::pictureInput(){

}

