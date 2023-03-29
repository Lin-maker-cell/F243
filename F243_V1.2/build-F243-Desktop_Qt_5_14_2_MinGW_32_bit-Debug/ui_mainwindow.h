/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *PortBox;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_14;
    QLabel *label_12;
    QVBoxLayout *verticalLayout;
    QPushButton *SerialSwitchButton;
    QComboBox *BaudBox;
    QComboBox *BitBox;
    QComboBox *ParityBox;
    QComboBox *StopBox;
    QComboBox *ControlBox;
    QComboBox *ProtocolBox;
    QPushButton *HangUpModeButton;
    QPushButton *ViewLogButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QTextEdit *ReceivingWindow;
    QLabel *label_7;
    QPlainTextEdit *EditWindow;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_15;
    QPushButton *ClearReceive;
    QSpacerItem *verticalSpacer_3;
    QPushButton *SendButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *FileOpenButton;
    QLineEdit *FileName;
    QPushButton *FileSendButton;
    QPushButton *ClearEdit;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QLineEdit *DelayTimeEdit;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *TestDataLength;
    QPushButton *GenerrateTestDataButton;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(809, 660);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        PortBox = new QComboBox(centralwidget);
        PortBox->setObjectName(QString::fromUtf8("PortBox"));
        PortBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(PortBox, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);

        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setVerticalSpacing(25);
        gridLayout_3->setContentsMargins(-1, 52, -1, 10);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 4, 0, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 5, 0, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_14, 6, 0, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 7, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        SerialSwitchButton = new QPushButton(centralwidget);
        SerialSwitchButton->setObjectName(QString::fromUtf8("SerialSwitchButton"));

        verticalLayout->addWidget(SerialSwitchButton);

        BaudBox = new QComboBox(centralwidget);
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->setObjectName(QString::fromUtf8("BaudBox"));

        verticalLayout->addWidget(BaudBox);

        BitBox = new QComboBox(centralwidget);
        BitBox->addItem(QString());
        BitBox->addItem(QString());
        BitBox->addItem(QString());
        BitBox->addItem(QString());
        BitBox->setObjectName(QString::fromUtf8("BitBox"));

        verticalLayout->addWidget(BitBox);

        ParityBox = new QComboBox(centralwidget);
        ParityBox->addItem(QString());
        ParityBox->addItem(QString());
        ParityBox->addItem(QString());
        ParityBox->addItem(QString());
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QString::fromUtf8("ParityBox"));

        verticalLayout->addWidget(ParityBox);

        StopBox = new QComboBox(centralwidget);
        StopBox->addItem(QString());
        StopBox->addItem(QString());
        StopBox->addItem(QString());
        StopBox->setObjectName(QString::fromUtf8("StopBox"));

        verticalLayout->addWidget(StopBox);

        ControlBox = new QComboBox(centralwidget);
        ControlBox->addItem(QString());
        ControlBox->addItem(QString());
        ControlBox->addItem(QString());
        ControlBox->addItem(QString());
        ControlBox->setObjectName(QString::fromUtf8("ControlBox"));

        verticalLayout->addWidget(ControlBox);

        ProtocolBox = new QComboBox(centralwidget);
        ProtocolBox->addItem(QString());
        ProtocolBox->addItem(QString());
        ProtocolBox->addItem(QString());
        ProtocolBox->addItem(QString());
        ProtocolBox->setObjectName(QString::fromUtf8("ProtocolBox"));

        verticalLayout->addWidget(ProtocolBox);

        HangUpModeButton = new QPushButton(centralwidget);
        HangUpModeButton->setObjectName(QString::fromUtf8("HangUpModeButton"));

        verticalLayout->addWidget(HangUpModeButton);

        ViewLogButton = new QPushButton(centralwidget);
        ViewLogButton->setObjectName(QString::fromUtf8("ViewLogButton"));

        verticalLayout->addWidget(ViewLogButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_4->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        ReceivingWindow = new QTextEdit(centralwidget);
        ReceivingWindow->setObjectName(QString::fromUtf8("ReceivingWindow"));

        verticalLayout_4->addWidget(ReceivingWindow);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        EditWindow = new QPlainTextEdit(centralwidget);
        EditWindow->setObjectName(QString::fromUtf8("EditWindow"));

        verticalLayout_4->addWidget(EditWindow);


        gridLayout_4->addLayout(verticalLayout_4, 1, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_15);

        ClearReceive = new QPushButton(centralwidget);
        ClearReceive->setObjectName(QString::fromUtf8("ClearReceive"));

        verticalLayout_3->addWidget(ClearReceive);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        SendButton = new QPushButton(centralwidget);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));

        verticalLayout_3->addWidget(SendButton);


        gridLayout_4->addLayout(verticalLayout_3, 1, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        FileOpenButton = new QPushButton(centralwidget);
        FileOpenButton->setObjectName(QString::fromUtf8("FileOpenButton"));

        horizontalLayout->addWidget(FileOpenButton);

        FileName = new QLineEdit(centralwidget);
        FileName->setObjectName(QString::fromUtf8("FileName"));

        horizontalLayout->addWidget(FileName);

        FileSendButton = new QPushButton(centralwidget);
        FileSendButton->setObjectName(QString::fromUtf8("FileSendButton"));

        horizontalLayout->addWidget(FileSendButton);

        ClearEdit = new QPushButton(centralwidget);
        ClearEdit->setObjectName(QString::fromUtf8("ClearEdit"));

        horizontalLayout->addWidget(ClearEdit);


        gridLayout_4->addLayout(horizontalLayout, 2, 1, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(14);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        DelayTimeEdit = new QLineEdit(centralwidget);
        DelayTimeEdit->setObjectName(QString::fromUtf8("DelayTimeEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DelayTimeEdit->sizePolicy().hasHeightForWidth());
        DelayTimeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(DelayTimeEdit);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout_4->addLayout(horizontalLayout_3, 3, 1, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(14);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEdit_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout_4->addLayout(horizontalLayout_4, 4, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_2->addWidget(label_11);

        TestDataLength = new QLineEdit(centralwidget);
        TestDataLength->setObjectName(QString::fromUtf8("TestDataLength"));
        sizePolicy.setHeightForWidth(TestDataLength->sizePolicy().hasHeightForWidth());
        TestDataLength->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(TestDataLength);

        GenerrateTestDataButton = new QPushButton(centralwidget);
        GenerrateTestDataButton->setObjectName(QString::fromUtf8("GenerrateTestDataButton"));

        horizontalLayout_2->addWidget(GenerrateTestDataButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_2, 5, 1, 1, 2);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 809, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\346\265\201", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\345\215\217\350\256\256\347\260\207", nullptr));
        label_12->setText(QString());
        SerialSwitchButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        BaudBox->setItemText(0, QCoreApplication::translate("MainWindow", "Custom", nullptr));
        BaudBox->setItemText(1, QCoreApplication::translate("MainWindow", "110", nullptr));
        BaudBox->setItemText(2, QCoreApplication::translate("MainWindow", "300", nullptr));
        BaudBox->setItemText(3, QCoreApplication::translate("MainWindow", "600", nullptr));
        BaudBox->setItemText(4, QCoreApplication::translate("MainWindow", "1200", nullptr));
        BaudBox->setItemText(5, QCoreApplication::translate("MainWindow", "2400", nullptr));
        BaudBox->setItemText(6, QCoreApplication::translate("MainWindow", "4800", nullptr));
        BaudBox->setItemText(7, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudBox->setItemText(8, QCoreApplication::translate("MainWindow", "14400", nullptr));
        BaudBox->setItemText(9, QCoreApplication::translate("MainWindow", "19200", nullptr));
        BaudBox->setItemText(10, QCoreApplication::translate("MainWindow", "38400", nullptr));
        BaudBox->setItemText(11, QCoreApplication::translate("MainWindow", "56000", nullptr));
        BaudBox->setItemText(12, QCoreApplication::translate("MainWindow", "57600", nullptr));
        BaudBox->setItemText(13, QCoreApplication::translate("MainWindow", "115200", nullptr));
        BaudBox->setItemText(14, QCoreApplication::translate("MainWindow", "128000", nullptr));
        BaudBox->setItemText(15, QCoreApplication::translate("MainWindow", "230400", nullptr));
        BaudBox->setItemText(16, QCoreApplication::translate("MainWindow", "256000", nullptr));
        BaudBox->setItemText(17, QCoreApplication::translate("MainWindow", "460800", nullptr));
        BaudBox->setItemText(18, QCoreApplication::translate("MainWindow", "500000", nullptr));
        BaudBox->setItemText(19, QCoreApplication::translate("MainWindow", "512000", nullptr));
        BaudBox->setItemText(20, QCoreApplication::translate("MainWindow", "600000", nullptr));
        BaudBox->setItemText(21, QCoreApplication::translate("MainWindow", "750000", nullptr));
        BaudBox->setItemText(22, QCoreApplication::translate("MainWindow", "921600", nullptr));
        BaudBox->setItemText(23, QCoreApplication::translate("MainWindow", "1000000", nullptr));
        BaudBox->setItemText(24, QCoreApplication::translate("MainWindow", "1500000", nullptr));
        BaudBox->setItemText(25, QCoreApplication::translate("MainWindow", "2000000", nullptr));

        BitBox->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        BitBox->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        BitBox->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        BitBox->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        ParityBox->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        ParityBox->setItemText(1, QCoreApplication::translate("MainWindow", "Odd", nullptr));
        ParityBox->setItemText(2, QCoreApplication::translate("MainWindow", "Even", nullptr));
        ParityBox->setItemText(3, QCoreApplication::translate("MainWindow", "Mark", nullptr));
        ParityBox->setItemText(4, QCoreApplication::translate("MainWindow", "Space", nullptr));

        StopBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopBox->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        StopBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        ControlBox->setItemText(0, QCoreApplication::translate("MainWindow", "Hardware", nullptr));
        ControlBox->setItemText(1, QCoreApplication::translate("MainWindow", "Software", nullptr));
        ControlBox->setItemText(2, QCoreApplication::translate("MainWindow", "None", nullptr));
        ControlBox->setItemText(3, QCoreApplication::translate("MainWindow", "Custom", nullptr));

        ProtocolBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        ProtocolBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        ProtocolBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        ProtocolBox->setItemText(3, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));

        HangUpModeButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\214\202\346\234\272\346\250\241\345\274\217", nullptr));
        ViewLogButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\346\227\245\345\277\227", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\347\252\227\345\217\243", nullptr));
        ClearReceive->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        SendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        FileOpenButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        FileSendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        ClearEdit->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\274\226\350\276\221", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "s/\346\254\241", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201\346\254\241\346\225\260", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\225\260\346\215\256\351\225\277\345\272\246", nullptr));
        GenerrateTestDataButton->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\346\265\213\350\257\225\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
