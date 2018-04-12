#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QZXing.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    //初始化timer

    cam = NULL;
    // 初始化cam

    connect(timer, SIGNAL(timeout()), this, SLOT(cameraopen()));
    // 时间到，读取当前摄像头信息,这个必须加，因为timer需要配合timeout()信号用
    //没有的话会出现错误；
    //另外注意自己有没有野指针，有的话常常会
    //出现Program Files (x86)\SogouInput\7.2.0.2124\程序异常终止,这样的错误

    m_count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    cvReleaseCapture(&cam);
    //释放内存；
}

void MainWindow::cameraopen()
{
    pFrame = cvQueryFrame(cam);
    // 从摄像头中抓取并返回每一帧

    QImage image((const uchar*)pFrame->imageData, pFrame->width, pFrame->height,QImage::Format_RGB888);
    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。

    if (! (++m_count % 33)) {
        QZXing *pDecoder = new QZXing(QZXing::DecoderFormat_MAXICODE);
        //Qzxing对象
        QString qrmsg=pDecoder->decodeImage(image);
        //decodeImage是Qzxing解码函数，解码出来的是QString字符体
        if (!qrmsg.isEmpty())
        {
            ui->lineEdit->setText(qrmsg);
//            timer->stop();
        }
        else
        {
            ui->lineEdit->setText("未检测到");
            //显示解码失败
        }
    }

    QGraphicsScene *scene = new QGraphicsScene;
    //创建图片显示方式的容器

    scene->addPixmap(QPixmap::fromImage(image));
    //装载图片

    ui->graphicsView->setScene(scene);
    //显示图片，自动添加滚动条

    ui->graphicsView->show();
    //显示图片

}

void MainWindow::on_pushButton_clicked()
{
    cam = cvCreateCameraCapture(0);
    //打开摄像头，从摄像头中获取视频

    timer->start(33);
    // 开始计时，超时则发出timeout()信号
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
    // 停止读取数据。

    cvReleaseCapture(&cam);
    //释放内存；
}
