#include "mythread.h"
#include <QTCore>

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    for(int i =0 ; i < 1000;i++) {

        //QMutex is similar to Synchronize in JAVA
        QMutex mutex;
        mutex.lock();
        if(this->stop) break;
        mutex.unlock();

        emit NumberChanged(i);

        this->msleep(100);
    }
}
