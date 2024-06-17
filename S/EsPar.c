/* 
    IF X≠0 GOTO [A]
[C] Y   ← Y+1
    Z₁  ← Z₁+1
    IF Z₁≠0 GOTO [E]
[A] X   ← X-1
    IF X≠0 GOTO [B]
    Z₂  ← Z₂+1
    IF Z₂≠0 GOTO [E]
[B] X   ← X-1
    IF X≠0 GOTO [A]
    Z₃  ← Z₃+1
    IF Z₃≠0 GOTO [C]

*/
#include "../Librerias/getnum.h"
#include <stdio.h>
int esPar(__u_int x){
    unsigned int y,z1,z2,z3;
    z1=z2=z3=y=0;
    if(x!=0) goto A;
    C:y++;
    z1++;
    if (z1!=0) goto E;
    A: x--;
    if (x!=0) goto B;
    z2++;
    if (z2!=0) goto E;
    B: x--;
    if (x!=0) goto A;
    z3++;
    if (z3!=0) goto C;
    E: printf("Y=%d\n",y);
    return y;
}


int main(int argc, char const *argv[]){
    for (int i = 0; i < 12; i++){
        esPar(i);
    }
    return 0;
}
