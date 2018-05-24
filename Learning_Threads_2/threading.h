#ifndef THREADING_H
#define THREADING_H

#include <QtCore>
#include <QDebug>
#include <QThread>

class Threading : public QThread
{

    Q_OBJECT

public:
    Threading();
    void run();
    bool stop;

signals:
    void numberSent(int);
};

#endif // THREADING_H
