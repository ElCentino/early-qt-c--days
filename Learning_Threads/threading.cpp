#include "threading.h"

Threading::Threading()
{

}

void Threading::run()
{

    for(int i = 0; i < 10000; i++)
    {
        qDebug() << "This is " << this->name;

    }
}

Threading::~Threading()
{

}


