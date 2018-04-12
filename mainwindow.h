#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cv.h"
#include "highgui.h"
#include <QTime>

namespace Ui {
class MainWindow;
}

class MyThread;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void cameraopen();
    //声明函数

    void set_edit_line (QString);

signals:
    void send_image (QImage);

private:
    Ui::MainWindow *ui;

     QTimer *timer;
    //QTimer 计时用；

    IplImage* pFrame;
    //申请IplImage类型指针，就是申请内存空间来存放每一帧图像

    CvCapture *cam;
    // 视频获取结构， 用来作为视频获取函数的一个参数

    MyThread *m_thread;
};

#endif // MAINWINDOW_H
