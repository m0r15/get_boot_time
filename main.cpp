#include <utmpx.h>

#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

QString getBootTime();

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";

    getBootTime();

    return QCoreApplication::exec();
}

QString getBootTime()
{
    struct utmpx *utx;
    while ((utx = getutxent()) != nullptr) {
        if (BOOT_TIME == utx->ut_type) {
            qDebug() << "Boot time" << QDateTime::fromTime_t(utx->ut_tv.tv_sec).toString("yyyy.MM.dd HH:mm:sss");
        }
    }
}
