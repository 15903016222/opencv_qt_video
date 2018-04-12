#ifndef __MYTHREAD_H__
#define __MYTHREAD_H__

#include <QThread>
#include <QTimer>
#include <QImage>
#include <QString>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread();
    ~MyThread();

public slots:
    void recognise_image(QImage);

signals:
    void send_text (QString);

protected:
    void run();

};

#endif // MYTHREAD_H
