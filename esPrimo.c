#include <stdio.h>
int esPrimo(int num){
    int count=0;
    for (int i = 1; i < num-1 && count!=2; i++)
        count+=(num%i==0);
    return count-1?0:1;
}


int main(int argc, char const *argv[])
{
    printf("%d\n",esPrimo(11));
    return 0;
}
