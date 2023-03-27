#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
// 初始化
void MainWindow::Init()
{
    SerialGet();
    ui->SerialSwitchButton->setText("打开串口");
    ui->ReceivingWindow->setReadOnly(true);// 接收窗口默认只读权限
}
// 获取计算机中的串口
void MainWindow::SerialGet()
{
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        serial->setPort(info);// 在对象中设置串口
        ui->PortBox->addItem(info.portName().append(' ').append(info.description()));// 添加计算机中的端口
        portName.append(info.portName());// 将可用串口放到 portName list 中
        if (serial->isOpen()) {// 如果串口已经打开，则关闭串口
            serial->clear();
            serial->close();
        }
    }
}
// 初始串口参数设置
void MainWindow::SerialParameterInit()
{
    // 波特率，波特率默认选择 115200
    ui->BaudBox->setCurrentText("115200");
    serial->setBaudRate(QSerialPort::Baud115200);
    // 校验，校验默认选择 None
    ui->ParityBox->setCurrentText("None");
    serial->setParity(QSerialPort::NoParity);
    // 数据位，数据位默认选择 8 位
    ui->BitBox->setCurrentText("8");
    serial->setDataBits(QSerialPort::Data8);
    // 停止位，停止位默认选择 1 位
    ui->StopBox->setCurrentText("1");
    serial->setStopBits(QSerialPort::OneStop);
    // 控制流，默认选择 None
    ui->ControlBox->setCurrentText("None");
    serial->setFlowControl(QSerialPort::NoFlowControl);
}
// 初始控件权限设置
void MainWindow::PermissionInit()
{
    ui->HangUpModeButton->setDisabled(true);
    ui->ReceivingWindow->setReadOnly(true);
    ui->SendButton->setDisabled(true);
}
// 串口检查
void MainWindow::CheckSerial(int index)
{
    for (int i = 0; i < portName.size(); i++) {
        if (i != index) {
            serial->setPortName(portName[i]);
            if (serial->isOpen()) {
                serial->clear();
                serial->close();
            }
        }
    }
}
// 权限更新
void MainWindow::PermissionUpdate(bool select)
{
    if (select) {
        ui->HangUpModeButton->setDisabled(false);
        ui->SendButton->setDisabled(false);
        ui->SerialSwitchButton->setText("关闭串口");
    }
    else {
        ui->SendButton->setDisabled(true);
        ui->SerialSwitchButton->setText("打开串口");
    }
}
// connect 函数
void MainWindow::ConnectFun()
{
    connect(ui->SerialSwitchButton, &QPushButton::clicked, this, [&](){// 串口开关
        if (QString::compare(ui->SerialSwitchButton->text(), "打开串口") == 0) {
            CheckSerial(ui->PortBox->currentIndex());
            serial->setPortName(portName[ui->PortBox->currentIndex()]);
            serial->open(QIODevice::ReadWrite);
            if (serial->isOpen()) {// 打开成功
                QMessageBox::information(this, "提示", "串口打开成功");
                PermissionUpdate(true);
            }
            else {
                QMessageBox::information(this, "提示", "串口打开失败");
            }
        }
        else {
            serial->setPortName(portName[ui->PortBox->currentIndex()]);
            serial->clear();
            serial->close();
            if (serial->isOpen()) {// 串口关闭失败

            }
            else{// 串口关闭成功
                QMessageBox::information(this, "提示", "串口关闭成功");
                PermissionUpdate(false);
            }
        }
    });
    connect(ui->HangUpModeButton, &QPushButton::clicked, this, [&](){// 挂机模式

    });
    connect(ui->ViewLogButton, &QPushButton::clicked, this, [&](){// 查看日志

    });
    connect(ui->FileOpenButton, &QPushButton::clicked, this, [&](){// 打开文件

    });
    connect(ui->FileSendButton, &QPushButton::clicked, this, [&](){// 发送文件

    });
    connect(serial, &QSerialPort::readyRead, this, [&](){// 接收数据
        QByteArray data = serial->readAll();// 读取数据
        if(!data.isEmpty()){// 接收到数据
            QString str = ui->ReceivingWindow->toPlainText();// 返回纯文本
            if (!str.isEmpty()) {
                str.append('\n');
            }
            ui->ReceivingWindow->setReadOnly(false);
            ui->ReceivingWindow->append(data.toHex(' '));// 将数据放入接收窗口
            ui->ReceivingWindow->setReadOnly(true);
        }
        //
    });
    connect(ui->SendButton, &QPushButton::clicked, this, [&](){// 发送数据

    });
    connect(ui->ClearReceiveButton, &QPushButton::clicked, this, [&](){// 清空接收窗口

    });
    connect(ui->ClearEdit, &QPushButton::clicked, this, [&](){// 清空编辑窗口
        ui->EditWindow->setPlainText("");
    });
    connect(ui->GenerrateTestDataButton, &QPushButton::clicked, this, [&](){

    });
}
// 生成随机测试数据
QByteArray MainWindow::RandomDataGenerate(int length)
{

}
// 串口切换
void MainWindow::on_PortBox_activated(int index)
{
    serial->setPortName(portName[index]);
    if (serial->isOpen()) {
        PermissionUpdate(true);
    }
    else {
        PermissionUpdate(false);
    }
}
// 波特率选择
void MainWindow::on_BaudBox_activated(const QString &arg1)
{
    if (QString::compare(arg1, "19200") == 0) {
        serial->setBaudRate(QSerialPort::Baud19200);
    }
    else if (QString::compare(arg1, "38400") == 0) {
        serial->setBaudRate(QSerialPort::Baud38400);
    }
    else if (QString::compare(arg1, "56000") == 0) {
        serial->setBaudRate(56000);
    }
    else if (QString::compare(arg1, "57600") == 0) {
        serial->setBaudRate(QSerialPort::Baud57600);
    }
    else if (QString::compare(arg1, "115200") == 0) {
        serial->setBaudRate(QSerialPort::Baud115200);
    }
    else if (QString::compare(arg1, "128000") == 0) {
        serial->setBaudRate(128000);
    }
    else if (QString::compare(arg1, "230400") == 0) {
        serial->setBaudRate(230400);
    }
    else {
        serial->setBaudRate(256000);
    }
}
// 数据位选择
void MainWindow::on_BitBox_activated(const QString &arg1)
{

}
// 校验位选择
void MainWindow::on_ParityBox_activated(const QString &arg1)
{

}
// 停止位选择
void MainWindow::on_StopBox_activated(const QString &arg1)
{

}
// 控制流选择
void MainWindow::on_ControlBox_activated(const QString &arg1)
{

}
// 协议簇选择
void MainWindow::on_ProtocolSelect_activated(const QString &arg1)
{

}
