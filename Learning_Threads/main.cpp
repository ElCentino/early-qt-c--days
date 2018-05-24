#include <QCoreApplication>
#include "threading.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Threading *t = new Threading;
    t->name = "Thread 1";

    Threading *v = new Threading;
    v->name = "Thread 2";

    Threading *c = new Threading;
    c->name = "Thread 3";


    t->start(QThread::NormalPriority);
    v->start(QThread::HighestPriority);
    c->start(QThread::HighPriority);

    return a.exec();
}
