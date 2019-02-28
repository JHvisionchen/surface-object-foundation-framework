#ifndef SERIALPORT_H
#define SERIALPORT_H

// for serialport
#include <QSerialPort>
#include <QSerialPortInfo>

#include "globalvariable.h"

class Serialport:public QObject
{
    Q_OBJECT

public:
    Serialport();
    //发送指令
    void sendcommand(QString cmd);

    //
    inline QSerialPort::DataBits getbit(int bit)
    {
        switch (bit)
        {
        case 5:
            return QSerialPort::Data5;
        case 6:
            return QSerialPort::Data6;
        case 7:
            return QSerialPort::Data7;
        default:
            return QSerialPort::Data8;
        }
    }

private slots:
    //读取指令
    void readread();

private:
    //control port
    QSerialPort *port;
    //serialport open or not
    bool is_port;
    //receive imformation from serialport
    QString receive_command;
};

#endif // SERIALPORT_H
