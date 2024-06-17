#include <math.h>

void
piramide(int * latas,int * altura){
    int cantLatas=pow(*(altura)+1,2);
    if (*latas<cantLatas){
        (*altura)++;
        *latas-=cantLatas;
        piramide(latas,altura);
    }
}
