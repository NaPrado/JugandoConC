#if !defined(master_h)
#define master_h
#define MAX 9
#define MIN 1
#define VALID_COND (num>0 && num<11)
#define XDIGIT ( num>0 && cond )

struct cantCond{
    int bien;
    int regular;
};
int chooseLegth();
int * randomVec(int dim);
int nivel();
int isValidNum(int num,int dim);
int *leerNumero(int dim);
int coincideNumero(struct cantCond cond,int dim);
struct cantCond cantCond(int e [],int s [],int dim);


#endif // master_h
