#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort;// 申请内存,并设置父对象
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
// 初始化
void MainWindow::Init()
{
    // [len / 986] + 1,最低 5 s
    mAutoSendCount = 0;// 初始化
    SerialGet();
    SerialParameterInit();
    PermissionInit();
    ConnectFun();
//    QDoubleValidator *validatorSec = new QDoubleValidator(ui->DelayTimeEdit);// 延时发送时间编辑限制
//    validatorSec->setRange(0.0001, std::numeric_limits<double>::max(), 4);
//    ui->DelayTimeEdit->setValidator(validatorSec);
//    QIntValidator *validatorTimes = new QIntValidator(ui->DelaySendTimes);// 延时发送次数编辑限制
//    validatorTimes->setRange(1, 10000);
//    ui->DelaySendTimes->setValidator(validatorTimes);
//    QIntValidator *validatorLen = new QIntValidator(ui->TestDataLength);// 随机数据长度编辑限制
//    validatorLen->setRange(1, 51200);
//    ui->TestDataLength->setValidator(validatorLen);
    ui->SerialSwitchButton->setText("打开串口");
    ui->FileSendButton->setDisabled(true);
    ui->SendButton->setDisabled(true);
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
    ui->DelaySend->setDisabled(true);
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
    ui->BaudBox->setDisabled(select);
    ui->BitBox->setDisabled(select);
    ui->ParityBox->setDisabled(select);
    ui->StopBox->setDisabled(select);
    ui->ControlBox->setDisabled(select);
    ui->SendButton->setDisabled(!select);
    ui->DelaySend->setDisabled(!select);
    if (select) { 
        ui->SerialSwitchButton->setText("关闭串口");
        if (!ui->FileName->text().isEmpty()) {
            ui->FileSendButton->setDisabled(!select);
        }
    }
    else {     
        if (ui->DelaySend->isChecked()) {// 如果挂机模式已经打开，关闭它
            ui->DelaySend->setChecked(false);
            mAutoSendCount = 0;
            ui->TestDataLength->setDisabled(false);
            mAutoSendCount = 0;
            LogUpdate("挂机模式未执行完毕，已强制关闭");
        }
        ui->SerialSwitchButton->setText("打开串口");
        ui->FileSendButton->setDisabled(!select);
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
    connect(ui->ViewLogButton, &QPushButton::clicked, this, [&](){// 查看日志
        QFile file("log.txt");
        if (!file.exists()) {// 文件不存在
            if (file.open(QIODevice::WriteOnly)) {
                QTextStream out(&file);
                out << GetCurTime().append(" 以下为日志信息");
                QMessageBox::information(this, "提示", "日志文件不存在，已创建新的日志文件");
                file.close();
            } else {
                QMessageBox::information(this, "提示", "日志文件创建失败");
            }
        }
        else {// 如果文件已经存在，以只读模式打开文件，并读取文件内容
            ui->ReceivingWindow->clear();
            if (file.open(QIODevice::ReadOnly)) {
                QTextStream stream(&file);
                QUrl fileUrl = QUrl::fromLocalFile("log.txt");
                QDesktopServices::openUrl(fileUrl);
                file.close();
            } else {
                QMessageBox::information(this, "提示", "日志文件打开失败");
            }
        }
    });
    connect(ui->FileOpenButton, &QPushButton::clicked, this, [&](){// 打开文件
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("Text Files (*.txt);;All Files (*)"));
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                fileBuf.clear();
                fileBuf.append(stream.readAll());// 文件数据写入文件缓冲区
                qDebug() << fileBuf;
                ui->ReceivingWindow->append(GetCurTime().append(" -> ").append(fileBuf));
                LogUpdate("文件打开成功");
                ui->FileName->setText(fileName);// 文件名
                file.close();
            }
        }
        if (QString::compare(ui->SerialSwitchButton->text(), "关闭串口") == 0) {
            ui->FileSendButton->setEnabled(true);
        }
    });
    connect(ui->FileSendButton, &QPushButton::clicked, this, [&](){// 发送文件
        ui->ReceivingWindow->append(GetCurTime().append(" -> ").append(fileBuf));
        SendData(DataAnasis(fileBuf), DataAnasisToLog(fileBuf));
    });
    connect(serial, &QSerialPort::readyRead, this, [&](){// 接收数据
        QByteArray data = serial->readAll();// 读取数据
        // 计算接收数据长度 len =
        dataBuf.append(data);// 数据缓冲区
        PraseACK();
        if(!data.isEmpty()){// 接收到数据
            ui->ReceivingWindow->setReadOnly(false);
            ui->ReceivingWindow->append(GetCurTime().append(" <- ").append(data.toHex(' ')));// 将数据放入接收窗口
            ui->ReceivingWindow->setReadOnly(true);
        }
    });
    connect(ui->SendButton, &QPushButton::clicked, this, [&](){// 发送数据
        if (!ui->EditWindow->toPlainText().isEmpty()) {
            ui->ReceivingWindow->append(GetCurTime().append(" -> ").append(ui->EditWindow->toPlainText()));
            SendData(DataAnasis(ui->EditWindow->toPlainText()),DataAnasisToLog(ui->EditWindow->toPlainText()));
        }
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
        RandomDataGenerate(ui->TestDataLength->text().toInt());
    });
    // 延时设置
    connect(this->ui->DelaySend, &QCheckBox::clicked, this, &MainWindow::DelaySendData);
    connect(&this->mAutoSendTimer, &QTimer::timeout, this, &MainWindow::DelaySendData);
}
// 生成随机测试数据
void MainWindow::RandomDataGenerate(int length)
{
    if (length >= 1 && length <= 51200) {
        const QString allChars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";// 字符集
        const int allCharsLength = allChars.length();// 字符集长度
        QString str;
        for (int i = 0; i < length; ++i) {
            str.append(allChars.at(qrand() % allCharsLength));
        }
        ui->EditWindow->setPlainText(str);
    }
    else {
        QMessageBox::information(this, "提示", "长度不合法");
        return;
    }
}

QByteArray MainWindow::DataAnasis(QString data)
{
    // abcd -> 16进制
    QByteArray ans = data.toLatin1();// 8 位 ASCII 码
    QString length = QString("%1").arg(data.size(), 4, 16, QLatin1Char('0')).toUpper();// 16 进制长度
    ans.prepend(QByteArray::fromHex(length.toStdString().c_str()));// 添加长度
    ans.append(QByteArray::fromHex(XorChecksum(ans).toStdString().c_str()));// 添加校验位
    ans.prepend("$DAT");// 添加协议头
    return ans;
}

QByteArray MainWindow::DataAnasisToLog(QString data)
{
    QByteArray ans = data.toLatin1();
    QString length = QString("%1").arg(data.size(), 4, 16, QLatin1Char('0')).toUpper();// 16 进制长度
    ans.prepend(length.toLatin1());// 添加长度
    ans.append(XorChecksum(ans).toLatin1());// 添加校验位
    ans.prepend("$DAT");// 添加协议头
    return ans;
}

// 求校验位
QString MainWindow::XorChecksum(const QByteArray &data)
{
    QByteArray head = data.left(4);
    QByteArray body = data.mid(4);
    body.prepend(head.fromHex(head));
    int result = 0;
    for (int i = 0; i < body.size(); i++) {
        result ^= static_cast<uchar>(body.at(i));
    }
    return QString("%1").arg(result, 2, 16, QLatin1Char('0')).toUpper();
}

void MainWindow::SendData(QByteArray data,QByteArray datatolog)
{
    // QByteArray -> char 数组
    // 24 44 41 54 00 04 61 62 63 64 00
    // 直接发 tempstr 会崩
    serial->write(data);
//    LogUpdate("发送数据 " + QString::fromUtf8(data, data.size()));
    LogUpdate("发送数据 " + datatolog);
}
// 解析ACK
void MainWindow::PraseACK()
{   // 超时时间与数据长度挂钩 如：数据长度 1k -> 超时时间 5s，线性增长
    QByteArray hexData = dataBuf.toHex();
    // 24 41 43 4B 00 01 01 00 成功
    // 24 41 43 4B 00 01 00 01 失败
    int headIndex = hexData.indexOf("2441434b");
    if (headIndex != -1 && hexData.size() >= 13) {// 检测到指令头
        dataBuf.remove(0, headIndex / 2);// 丢弃头之前无效数据
        hexData.remove(0, headIndex);
        if (hexData.at(11) == '1') {// 判断长度
            if (hexData.at(13) == '1') {
                LogUpdate("接收ACK成功");
                emit ReceivedACK();
            }
            else if (hexData.at(13) == '0' ) {
                LogUpdate("接收ACK失败");
                emit ReceivedACK();
            }
            else {
                LogUpdate("收到的指令不为 ACK");
            }
        }
        else {// 长度不为 1
            LogUpdate("收到的指令不为 ACK");
        }
        dataBuf.remove(0, 4);
    }
}

QString MainWindow::GetCurTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();   // 获取当前日期和时间
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");   // 转换为字符串格式
    return currentDateTimeString;
}
// 日志更新
void MainWindow::LogUpdate(QString str)
{
    // 打开日志文件，若不存在则创建，以追加方式写入日志
    QFile file("log.txt");
    if (!file.exists()) {// 文件不存在
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            out << GetCurTime().append(" 以下为日志信息\n");
            out << GetCurTime().append(" ").append(str);
            file.close();
        } else {
            QMessageBox::information(this, "提示", "日志文件创建失败");
        }
    }
    else {
        // 如果文件已经存在，以只读模式打开文件，并读取文件内容
        if (file.open(QIODevice::WriteOnly|QIODevice::Append)) {
            QTextStream out(&file);
            out << "\n";
            out << GetCurTime().append(" ").append(str);
            file.close();
        } else {
            QMessageBox::information(this, "提示", "日志文件打开失败");
        }
    }
}
// 串口切换
void MainWindow::on_PortBox_activated(int index)
{
    if (serial->isOpen()) {
        if (serial->portName() == portName[index]) {
            PermissionUpdate(true);
        }
        else {
            PermissionUpdate(false);
        }
    }
    else {
        PermissionUpdate(false);
    }
}
// 波特率选择
void MainWindow::on_BaudBox_activated(const QString &arg1)
{
    serial->setBaudRate(arg1.toInt());
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
// 挂机模式
void MainWindow::DelaySendData()
{
    this->ui->DelayTimeEdit->setEnabled(false);
    this->ui->DelaySendTimes->setEnabled(false);
    mAutoSendDelay = this->ui->DelayTimeEdit->text().toUInt();// 延时时间
    mAutoSendTimes = this->ui->DelaySendTimes->text().toUInt();// 发送次数
    if (mAutoSendTimes == 0) {
        this->ui->DelayTimeEdit->setEnabled(true);
        this->ui->DelaySendTimes->setEnabled(true);
        this->ui->DelaySend->setChecked(false);
        return;
    }
    if (this->ui->DelaySend->isChecked()) {// 打开挂机模式
        ui->TestDataLength->setDisabled(true);
        if (mAutoSendCount == 0) {
            LogUpdate("挂机模式已打开");
        }
        int TestLen = ui->TestDataLength->text().toInt();
        int time;
        RandomDataGenerate(TestLen);// 生成随机数据
        ui->ReceivingWindow->append(GetCurTime().append(" -> ").append(ui->EditWindow->toPlainText()));
        SendData(DataAnasis(ui->EditWindow->toPlainText()), DataAnasisToLog(ui->EditWindow->toPlainText()));// 发送数据
        mAutoSendCount++;// 发送次数计数
        if (TestLen / 986 < 1) {// 最短 5 s
            time = 5;
        }
        else {
            time = TestLen / 986 * 5;
        }
        if (WaitForACK((unsigned int)(TestLen * 1000))) {// 收到 ack 延时
            mAutoSendTimer.setSingleShot(true);
            mAutoSendTimer.start(mAutoSendDelay*1000);
        }
        else {// 一直未收到 ack 超时
            mAutoSendTimer.stop();
            mAutoSendCount = 0;
            LogUpdate("ack 超时");
            QMessageBox::warning(this, "挂机模式", "ACK超时");
            this->ui->DelayTimeEdit->setEnabled(true);
            this->ui->DelaySendTimes->setEnabled(true);
            this->ui->DelaySend->setChecked(false);
            ui->TestDataLength->setDisabled(false);
            return;
        }
        if (mAutoSendTimes <= mAutoSendCount) {// 挂机模式执行完毕
            mAutoSendCount = 0;
            mAutoSendTimer.stop();
            LogUpdate("挂机模式已执行完成");
            QMessageBox::information(this, "挂机模式", "数据发送完成");
            this->ui->DelayTimeEdit->setEnabled(true);
            this->ui->DelaySendTimes->setEnabled(true);
            this->ui->DelaySend->setChecked(false);
            ui->TestDataLength->setDisabled(false);
            return;
        }
    }
    else {// 手动关闭挂机模式
        LogUpdate("挂机模式未完成，已手动强行关闭");
        mAutoSendCount = 0;
        mAutoSendTimer.stop();
        this->ui->DelayTimeEdit->setEnabled(true);
        this->ui->DelaySendTimes->setEnabled(true);
        this->ui->DelaySend->setChecked(false);
        ui->TestDataLength->setDisabled(false);
        return;
    }
}
// 等待 ack 信号
bool MainWindow::WaitForACK(const unsigned int millisecond)
{
    bool result = true;
    QEventLoop loop;
    connect(this, &MainWindow::ReceivedACK, &loop, &QEventLoop::quit); //第一个形参改为信号发出的对象
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, &QTimer::timeout, [&loop, &result] {
        result = false;
        loop.quit();
    });
    timer.start(millisecond);
    loop.exec();
    timer.stop();
    return result;
}
