#include "hikvision.h"

long int nPort=0;
LONG lUserID;
LONG lRealPlayHandle;
//构造函数
Hikvision::Hikvision()
{

}
//解码函数
void CALLBACK DecCBFun(long int , char * pBuf, long int, FRAME_INFO * pFrameInfo, long int , long int)
{
    long lFrameType = pFrameInfo->nType;
    if (lFrameType == T_YV12)
    {
        Mat pImg(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC3);
        Mat src(pFrameInfo->nHeight + pFrameInfo->nHeight / 2, pFrameInfo->nWidth, CV_8UC1, pBuf);
        cvtColor(src, pImg, CV_YUV2BGR_YV12);
        //改变图片的尺寸
        resize(pImg, pImg, Size(1280, 720), 0, 0, INTER_LINEAR);
        imageBuffer->addFrame(pImg);//添加到缓冲区队列
    }
}
//实时流回调
void CALLBACK fRealDataCallBack(LONG, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *)
{
    switch (pantilt) {
    case 1:
        if(forLeft){
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,PAN_LEFT,0,3);
        }
        else{
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,PAN_LEFT,1,3);
            pantilt=0;
        }
        break;
    case 2:
        if(forRight){
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,PAN_RIGHT,0,3);
        }
        else{
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,PAN_RIGHT,1,3);
            pantilt=0;
        }
        break;
    case 3:
        if(forUp){
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,TILT_UP,0,3);
        }
        else{
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,TILT_UP,1,3);
            pantilt=0;
        }
        break;
    case 4:
        if(forDown){
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,TILT_DOWN,0,3);
        }
        else{
           NET_DVR_PTZControlWithSpeed(lRealPlayHandle,TILT_DOWN,1,3);
           pantilt=0;
        }
        break;
    case 5:
        if(forZoomIn){
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,ZOOM_IN,0,3);
        }
        else{
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,ZOOM_IN,1,3);
            pantilt=0;
        }
        break;
    case 6:
        if(forZoomOut){
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,ZOOM_OUT,0,3);
        }
        else{
            NET_DVR_PTZControlWithSpeed(lRealPlayHandle,ZOOM_OUT,1,3);
            pantilt=0;
        }
        break;
    default:
        break;
    }
    switch (dwDataType)
    {
    case NET_DVR_SYSHEAD: //系统头
        if (!PlayM4_GetPort(&nPort))  //获取播放库未使用的通道号
        {
            break;
        }
        if (dwBufSize > 0)
        {
            std::cout<<"dwBufSize      "<<dwBufSize<<std::endl;
            if (!PlayM4_SetStreamOpenMode(nPort, STREAME_REALTIME))  //设置实时流播放模式
            {
                break;
            }
            if (!PlayM4_OpenStream(nPort, pBuffer, dwBufSize, 10*1024 * 1024)) //打开流接口
            {
                break;
            }

            if (!PlayM4_Play(nPort, 0)) //播放开始
            {
                break;
            }
            if (!PlayM4_SetDecCallBack(nPort, DecCBFun))
            {
                break;
            }
        }
        break;
    case NET_DVR_STREAMDATA:   //码流数据
        if (dwBufSize > 0 && nPort != -1)
        {
            if (!PlayM4_InputData(nPort, pBuffer, dwBufSize))
            {
                std::cout << "error" << PlayM4_GetLastError(nPort) << std::endl;
                break;
            }
        }
        break;
    default: //其他数据
        if (dwBufSize > 0 && nPort != -1)
        {
            if (!PlayM4_InputData(nPort, pBuffer, dwBufSize))
            {
                break;
            }
        }
        break;
    }
}
//异常消息回调函数
void CALLBACK g_ExceptionCallBack(DWORD dwType, LONG , LONG , void *)
{
    switch (dwType)
    {
    case EXCEPTION_RECONNECT:    //预览时重连
        printf("----------reconnect--------\n");
        break;
    default:
        break;
    }
}
//图像数据解析主线程
void Hikvision::run()
{
    //---------------------------------------
    // 初始化
    NET_DVR_Init();
    //设置连接时间与重连时间
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);
    //---------------------------------------
    // 注册设备
    NET_DVR_DEVICEINFO_V30 struDeviceInfo;
    lUserID = NET_DVR_Login_V30((char*)"192.168.4.32", 8000, (char*)"admin", (char*)"jinghai32", &struDeviceInfo);
    if (lUserID < 0)
    {
        cout<<"Login error, ";
        cout<<int(NET_DVR_GetLastError())<<endl;
        NET_DVR_Cleanup();
        return;
    }
    //---------------------------------------
    //设置异常消息回调函数
    NET_DVR_SetExceptionCallBack_V30(0, NULL, g_ExceptionCallBack, NULL);
    //---------------------------------------
    //启动预览并设置回调数据流
    NET_DVR_PREVIEWINFO struPlayInfo = { 0,0,0,0,0,0,0,"jh_3",0,0,0,0,0,0};
    struPlayInfo.hPlayWnd = 0;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel = 1;           //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode = 1;         //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP

    lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, fRealDataCallBack, NULL);

    if (lRealPlayHandle < 0)
    {
        printf("NET_DVR_RealPlay_V40 error\n");
        printf("%d\n", int(NET_DVR_GetLastError()));
        NET_DVR_Logout(lUserID);
        NET_DVR_Cleanup();
        return;
    }
    usleep(-1);
    //---------------------------------------
    //关闭预览
    NET_DVR_StopRealPlay(lRealPlayHandle);
    //注销用户
    NET_DVR_Logout(lUserID);
    //释放SDK资源
    NET_DVR_Cleanup();
    qDebug() << "Stopping capture thread...";
}

