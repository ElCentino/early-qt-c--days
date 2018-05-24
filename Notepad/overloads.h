#ifndef OVERLOADS_H
#define OVERLOADS_H

#include <QtCore>
#include <QDataStream>
#include "settings.h"

QDataStream &operator<<(QDataStream &out, Settings &settings);
QDataStream &operator>>(QDataStream &in, Settings settings);

QDataStream &operator<<(QDataStream &out,  Settings &settings)
{


    return out;
}

QDataStream &operator>>(QDataStream &in, Settings settings)
{
    return in;
}

#endif // OVERLOADS_H

