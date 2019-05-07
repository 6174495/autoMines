#include "timethread.h"

timeThread::timeThread()
{

}

void timeThread::run()
{
    int i = 0;
    while(true){
        emit corns(i);
        sleep(10);
        i++;
    }
}
