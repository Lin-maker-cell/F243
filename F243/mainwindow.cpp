#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort;// 申请内存,并设置父对象
    seq = 0;
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
    SerialParameterInit();
    PermissionInit();
    ConnectFun();
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
    ui->SerialSwitchButton->setText("打开串口");// 串口开关

    ui->ShowFileData->setDisabled(true);// 初始无文件打开，不允许查看文件
    ui->FileSendButton->setDisabled(true);// 发送文件按钮不可按
    ui->SendButton->setDisabled(true);// 发送按钮不可按
    ui->ReceivingWindow->setReadOnly(true);// 接收窗口默认只读权限
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
        ui->BaudBox->setDisabled(true);
        ui->BitBox->setDisabled(true);
        ui->ParityBox->setDisabled(true);
        ui->StopBox->setDisabled(true);
        ui->ControlBox->setDisabled(true);
        ui->HangUpModeButton->setDisabled(false);
        ui->SendButton->setDisabled(false);
        ui->SerialSwitchButton->setText("关闭串口");
    }
    else {
        if (QString::compare(ui->HangUpModeButton->text(), "关闭挂机模式")) {
            ui->HangUpModeButton->setText("打开挂机模式");
            // 关闭挂机模式
        }
        ui->BaudBox->setDisabled(false);
        ui->BitBox->setDisabled(false);
        ui->ParityBox->setDisabled(false);
        ui->StopBox->setDisabled(false);
        ui->ControlBox->setDisabled(false);
        ui->HangUpModeButton->setDisabled(true);
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
                QMessageBox::information(this, "提示", serial->portName().append("串口打开成功"));
                PermissionUpdate(true);
            }
            else {
                QMessageBox::information(this, "提示", serial->portName().append("串口打开失败"));
            }
        }
        else {
            serial->setPortName(portName[ui->PortBox->currentIndex()]);
            serial->clear();
            serial->close();
            if (serial->isOpen()) {// 串口关闭失败
                QMessageBox::information(this, "提示", serial->portName().append("串口关闭失败"));
            }
            else{// 串口关闭成功
                QMessageBox::information(this, "提示", serial->portName().append("串口关闭成功"));
                PermissionUpdate(false);
            }
        }
    });

            /* 挂机模式
             * 打开挂机模式 { 自动生成数据，数据处理好放到 sendBuf 中，调用 sendData(sendBuf)  }
            for (int i = 0; i < 次数; i++){
                0. 收到 ack 的判断
                1. 自动生成数据
                2. dataAnasis() 处理数据完毕放到 sendBuf 中
                2.9 延时
                3. 调用 sendData(sendBuf)
            }
            */
    connect(ui->ViewLogButton, &QPushButton::clicked, this, [&](){// 查看日志
        /* 日志格式 -- 发生相应活动时写入 txt 文件
            1. [时间] [串口名] [数据编号] [发送成功 / 失败]
            2. [时间] [串口名] [数据编号] [接收成功 / 失败]
            3. [时间] [串口名] [数据编号] [发送超时]
        */
        // 打开 txt
    });
    connect(ui->FileOpenButton, &QPushButton::clicked, this, [&](){// 打开文件
        /*
            1. 选择本地文件
            2. 文件名加载到

        */
    });
    connect(ui->FileSendButton, &QPushButton::clicked, this, [&](){// 发送文件

    });
    connect(serial, &QSerialPort::readyRead, this, [&](){// 接收数据
        QByteArray data = serial->readAll();// 读取数据
        dataBuf.append(data);// 数据缓冲区
        if(!data.isEmpty()){// 接收到数据
            QString str = ui->ReceivingWindow->toPlainText();// 返回纯文本
            if (!str.isEmpty()) {
                str.append('\n');
            }
            ui->ReceivingWindow->setReadOnly(false);
            ui->ReceivingWindow->append(data.toHex(' '));// 将数据放入接收窗口
            ui->ReceivingWindow->setReadOnly(true);
        }
        // 待处理
    });
    connect(ui->SendButton, &QPushButton::clicked, this, [&](){// 发送数据
        SendData(sendBuf);
    });
    connect(ui->ClearReceive, &QPushButton::clicked, this, [&](){// 清空接收窗口
        ui->ReceivingWindow->setReadOnly(false);
        ui->ReceivingWindow->setText("");
        ui->ReceivingWindow->setReadOnly(true);
    });
    connect(ui->ClearEdit, &QPushButton::clicked, this, [&](){// 清空编辑窗口
        ui->EditWindow->setPlainText("");
    });
    connect(ui->GenerrateTestDataButton, &QPushButton::clicked, this, [&](){// 生成测试数据
        ui->EditWindow->setPlainText("");
        int length = ui->TestDataLength->text().toInt();
        RandomDataGenerate(length);
    });
}
// 处理原始数据得到最后待发送的数据
QByteArray MainWindow::DataAnasis(QString data)
{
    /*
     * 1. 数据加头
     * 2. 数据计算长度
     * 3. 数据计算校验位
    */
    QByteArray completeData = data.toUtf8();
    return completeData;
}
// 生成随机测试数据
QString MainWindow::RandomDataGenerate(int length)
{
    /*
     *  根据 length 生成指定长度（字节）的随机数据
    */
    QString randomData;
    return randomData + length;
}
// 将 data 通过串口发送出去
void MainWindow::SendData(QByteArray data)
{
    seq++;
    if (serial->write(data) > 0) {
        // 写日志：[时间] [串口名] [数据序号] [数据发送成功 / 失败]
        // 写到接受窗口
    }
}
// 串口切换
void MainWindow::on_PortBox_activated(int index)
{
    if (serial->isOpen())
        {
            if (serial->portName() == portName[index])
            {
                qDebug() << serial->portName() << "111";
                PermissionUpdate(true);
            }
            else {
                PermissionUpdate(false);}
        }
        else
    {qDebug() << serial->portName() << "333";
            PermissionUpdate(false);}
}
// 波特率选择
void MainWindow::on_BaudBox_activated(const QString &arg1)
{
    if (QString::compare(arg1, "Custom") == 0) {
        // 输入用户自定义的波特率
    }
    else {
        serial->setBaudRate(arg1.toInt());
    }
}
// 数据位选择
void MainWindow::on_BitBox_activated(const QString &arg1)
{
    if (QString::compare(arg1, "5") == 0) {
        serial->setDataBits(QSerialPort::Data5);
    }
    else if (QString::compare(arg1, "6") == 0) {
        serial->setDataBits(QSerialPort::Data6);
    }
    else if (QString::compare(arg1, "7") == 0) {
        serial->setDataBits(QSerialPort::Data7);
    }
    else if (QString::compare(arg1, "8") == 0) {
        serial->setDataBits(QSerialPort::Data8);
    }
}
// 校验位选择
void MainWindow::on_ParityBox_activated(const QString &arg1)
{
    if (QString::compare(arg1, "None") == 0) {
        serial->setParity(QSerialPort::NoParity);
    }
    else if (QString::compare(arg1, "Odd") == 0) {
        serial->setParity(QSerialPort::OddParity);
    }
    else if (QString::compare(arg1, "Even") == 0) {
        serial->setParity(QSerialPort::EvenParity);
    }
    else if (QString::compare(arg1, "Mark") == 0) {
        serial->setParity(QSerialPort::MarkParity);
    }
    else if (QString::compare(arg1, "Space") == 0) {
        serial->setParity(QSerialPort::SpaceParity);
    }
}
// 停止位选择
void MainWindow::on_StopBox_activated(const QString &arg1)
{
    if (QString::compare(arg1, "1") == 0) {
        serial->setStopBits(QSerialPort::OneStop);
    }
    else {
        serial->setStopBits(QSerialPort::TwoStop);
    }
}
// 控制流选择
void MainWindow::on_ControlBox_activated(const QString &arg1)
{
    if (QString::compare(arg1, "Hardware") == 0) {
        serial->setFlowControl(QSerialPort::HardwareControl);
    }
    else if (QString::compare(arg1, "Software") == 0) {
        serial->setFlowControl(QSerialPort::SoftwareControl);
    }
    else if (QString::compare(arg1, "None") == 0) {
        serial->setFlowControl(QSerialPort::NoFlowControl);
    }
}
// 协议簇选择
void MainWindow::on_ProtocolSelect_activated(const QString &arg1)
{
    QString str = arg1;// 待定
}
