#include "serialport.h"

Serialport::Serialport():QObject()
{
    // initial a serialport
    port=new QSerialPort();
    connect(port,SIGNAL(readyRead()),this,SLOT(readread()));
    // list the information of connnect serialport
    QList<QSerialPortInfo> strlist=QSerialPortInfo::availablePorts();
    QList<QSerialPortInfo>::const_iterator iter;
}
// read serial port data
void Serialport::readread()
{
    QByteArray arr= port->readAll();
    //arr= port->readAll();
    QString str="";
    for(int i=0;i<arr.length();i++)
    {
        str+=QString("%1").arg((uchar)arr.at(i),2,16,QLatin1Char('0')).toUpper()+" ";
    }
    receive_command+=str;
    cout<<receive_command.toStdString()<<endl;
}
// send the command to serialport
void Serialport::sendcommand(QString cmd){
    QString str=cmd;
    QStringList strlist=str.trimmed().split(" ");
    QByteArray arr;
    for(int i=0;i<strlist.count();++i)
    {
        bool bl=false;
        QString ch=strlist.at(i);
        uchar byte=(uchar)ch.toInt(&bl,16);
        if(!bl)
        {
            return;
        }
        arr.append(byte);
    }
    port->write(arr);
    cout<<"send success"<<endl;
}
