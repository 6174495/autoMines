#include "timet.h"

timeT::timeT()
{

}

void timeT::run()
{
    while(!stop)
    {
        emit corn(i, j);
        sleep(1);
        i += PI / 30;
        j++;
        if(i > 2* PI)
            i = 0;
    }
}

void timeT::Tstart(int c)
{
    if(c==0){
        i = 0;
        j = 0;
        stop = false;
        start();
    }
    else if(c==1){
        stop = true;
        i = 0;
        j = 0;
        emit corn(i, j);
    }
    else if(c==2){
        stop = true;
    }
}
