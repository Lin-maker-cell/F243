#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>         // 提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo>     // 提供系统中存在的串口信息
#include <QMessageBox>
#include <QDebug>

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
    QString RandomDataGenerate(int length);// 生成随机数据
    QByteArray DataAnasis(QString data);
    void SendData(QByteArray data);// 数据发送

private slots:
    void on_PortBox_activated(int index);

    void on_BaudBox_activated(const QString &arg1);

    void on_BitBox_activated(const QString &arg1);

    void on_ParityBox_activated(const QString &arg1);

    void on_StopBox_activated(const QString &arg1);

    void on_ControlBox_activated(const QString &arg1);

    void on_ProtocolSelect_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;// 定义全局的串口对象
    QStringList portName;// 存储串口名
    QByteArray dataBuf;// 接受数据缓存区
    QByteArray sendBuf;// 待发送数据
    QByteArray fileBuf;
    QByteArray mByteArrayHead;// 协议头
    QByteArray mByteArrayLength;// 数据长度
    QByteArray mByteArrayParity;// 校验位
    int seq;// 数据编号
};
#endif // MAINWINDOW_H
