#include "mythread.h"
#include "QZXing.h"
#include <QDebug>
#include <QTime>

MyThread::MyThread() :
    QThread()
{

}

void MyThread::run()
{
}

MyThread::~MyThread()
{
}

void MyThread::recognise_image(QImage image)
{
    qDebug("111111111");
    QZXing *pDecoder = new QZXing(QZXing::DecoderFormat_MAXICODE);
    //Qzxing对象
    QString qrmsg=pDecoder->decodeImage(image);
    //decodeImage是Qzxing解码函数，解码出来的是QString字符体
    if (!qrmsg.isEmpty())
    {
        emit send_text(qrmsg);
    }
    else
    {
        emit send_text("未检测到");
    }
}
