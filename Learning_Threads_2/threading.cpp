#include "threading.h"

Threading::Threading()
{

}

void Threading::run()
{
    for(int i = 0; i < 1000; i++)
    {
        QMutex mutex;
        mutex.lock();

        if(stop == true)
        {
            break;
        }

        mutex.unlock();

        emit numberSent(i);

        msleep(100);
    }
}
