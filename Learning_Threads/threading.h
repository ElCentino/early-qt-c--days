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
    ~Threading();
    void run();
    QString name;
};

#endif // THREADING_H
