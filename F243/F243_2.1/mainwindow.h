#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
//#include <limits>
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Init();// 初始化
    void SerialGet();// 获取计算机中的串口
    void SerialParameterInit();// 初始串口参数设置
    void PermissionInit();// 初始控件权限设置
    void CheckSerial(int index);// 确保其他串口都已经关闭
    void PermissionUpdate(bool select);
    void ConnectFun();// connect 函数
    void RandomDataGenerate(int length);// 生成随机数据
    QByteArray DataAnasis(QString data);// 包装数据给write
    QByteArray DataAnasisToLog(QString data);//包装数据给log
    QString XorChecksum(const QByteArray &data);// 求校验位
    void SendData(QByteArray data, QByteArray datatolog);// 数据发送
    void PraseACK();// 数据解析
    QString GetCurTime();// 获取当前时间
    void LogUpdate(QByteArray str);// 日志更新

signals:
    void ReceivedACK();//接收到ACK时发送

private slots:
    void on_PortBox_activated(int index);

    void on_BaudBox_activated(const QString &arg1);

    void on_BitBox_activated(const QString &arg1);

    void on_ParityBox_activated(const QString &arg1);

    void on_StopBox_activated(const QString &arg1);

    void on_ControlBox_activated(const QString &arg1);

    void on_ProtocolSelect_activated(const QString &arg1);

    void DelaySendData();//发送数据

    void on_flushPort_clicked();

private:
    //延时发送
    bool WaitForACK(const unsigned int millisecond);

    Ui::MainWindow *ui;
    QSerialPort *serial;// 定义全局的串口对象
    QStringList portName;// 存储串口名
    QByteArray dataBuf;// 接受数据缓存区
    QByteArray fileBuf;// 文件数据缓冲区
    QByteArray mByteArrayHead;// 协议头 [4 字节]
    QByteArray mByteArrayLength;// 数据长度 [2 字节]
    QByteArray mByteArrayParity;// 校验位 [1 字节]
    //自动延时发送
    unsigned int mDelayTime;
    unsigned int mAutoSendDelay;
    unsigned int mAutoSendTimes;
    unsigned int mAutoSendCount = 0; //需要初始化，否则在第一次打开定时发送时会有只发送一次的BUG
    QTimer mAutoSendTimer;

    //串口类 mSera;
    //MsgHandle
};
#endif // MAINWINDOW_H
