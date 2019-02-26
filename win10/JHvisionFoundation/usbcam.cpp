#include "usbcam.h"

UsbCam::UsbCam()
{

}
void UsbCam::run(){
    usbcam.open(0);
    while(!stopUI){
        usbcam>>frame;
        resize(frame,frame,Size(1280,720),0,0,INTER_LINEAR);
        imageBuffer->addFrame(frame);
    }
    usbcam.release();
}

