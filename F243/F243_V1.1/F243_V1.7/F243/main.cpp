#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTimer *timer = new QTimer();
//    timer->setInterval(1000);
//    QObject::connect(timer, SIGNAL(timeout()), &app, SLOT(onTimer()));
//    timer->start();
    MainWindow w;
    w.show();
    return a.exec();
}

/*
 * void MainWindow::onTimer()
 * {
 *     qDebug() << "Timer triggered";
 * }
 */
