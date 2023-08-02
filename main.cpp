#include <utmpx.h>

#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

void getBootStamp();

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";

    getBootStamp();

    return QCoreApplication::exec();
}

void getBootStamp()
{
    struct utmpx *utx;
    while ((utx = getutxent()) != nullptr) {
        if (BOOT_TIME == utx->ut_type) {
            qDebug() << "Boot time" << QDateTime::fromTime_t(utx->ut_tv.tv_sec);
        }
    }
}

//static void
//process_utmp(void)
//{
//    struct utmpx *utx;
//
//    while ((utx = getutxent()) != nullptr) {
//#ifdef __APPLE__
//        if (aflag) {
//            row(utx);
//        }
//        else if (!bflag && utx->ut_type == USER_PROCESS) {
//            if (ttystat(utx->ut_line) == 0) {
//                if (!rflag && !lflag && !dflag) {
//                    row(utx);
//                }
//            }
//        }
//        else if (bflag && utx->ut_type == BOOT_TIME) {
//#ifndef __APPLE__
//            if (ttystat(utx->ut_line) == 0) {
//#endif /* __APPLE__ */
//
//            row(utx);
//#ifndef __APPLE__
//            }
//#endif /* __APPLE__ */
//        }
//        else if (dflag && utx->ut_type == DEAD_PROCESS) {
//            row(utx);
//        }
//        else if (lflag && utx->ut_type == LOGIN_PROCESS) {
//            row(utx);
//        }
//#else
//        if (((aflag || !bflag) && utx->ut_type == USER_PROCESS) ||
//		    (bflag && utx->ut_type == BOOT_TIME))
//			if (ttystat(utx->ut_line) == 0)
//				row(utx);
//#endif
//    }
//#ifdef __APPLE__
//    if (rflag) {
//        printf("   .       run-level 3\n");
//    }
//#endif
//}
