#include "globalvariable.h"

// 图像缓存区
ImageBuffer *imageBuffer = new ImageBuffer(5,true);
// 摄像机云台控制
int pantilt=0;
bool forLeft=false;
bool forRight=false;
bool forUp=false;
bool forDown=false;
// 摄像机焦距控制
bool forZoomIn=false;
bool forZoomOut=false;
//摄像头的选择，0表示hik，1表示usb
int camnum=1;
//关闭总程序指示
bool stopUI=false;
//输入数据类型选择，0表示摄像头，1表示视频，2表示图片
int inputtype=0;
//图像数据转换
QImage MatToQImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
//qt下的延时函数
void qtsleep(unsigned int msec){
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}
//获取目录下所有图片的文件名
vector<QString> getImgNames(QString path){
    vector<QString> imgNames;
    QDir dir(path);
    if(!dir.exists()){
        qDebug()<<"the dir is not exist!";
    }
    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Name);
    QFileInfoList list=dir.entryInfoList();
    for(int i=0;i<list.size();i++){
        QFileInfo fileinfo=list.at(i);
        //qDebug()<<fileinfo.fileName();
        QString tmp;
        tmp.append(path);
        tmp.append("/");
        tmp.append(fileinfo.fileName());
        qDebug()<<tmp;
        imgNames.push_back(tmp);
    }
    return imgNames;
}
