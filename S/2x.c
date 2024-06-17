#include "../Librerias/getnum.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned int x,y;
    y=0;
    x=getint("dame x: ");
    A: if (x!=0)
        goto B;
    //salto incondicional
    goto C;
    B: y++;
    y++;
    x--;
    goto A;
    C: printf("Y=%d\n",y);
    return y;
}