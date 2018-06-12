#include "stack.h"
#include <string.h>

// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S){
    (*S).top=NULL;
} //create stack kosong
address alokasi(int noPegX, char* namaX, int gajiX){
    address a=(address)malloc(sizeof(b1));
    if(a!=NULL){
        (a)->noPeg=noPegX;
        (a)->nama=namaX;
        (a)->gaji=gajiX;
        (a)->next=NULL;
    }
    return a;
}
void dealokasi(address p){
    free(p);
}
boolean isEmpty(Stack S){
    if((S).top==NULL){
        return true;
    }else{
        return false;
    }
}
void pushAddress(Stack *S, address p){
    address a=(address)malloc(sizeof(b1));
    if(((*S).top)==NULL){
        (*S).top=p;
    }else{
        (p)->next=(*S).top;
        (*S).top=p;
    }
}
void push(Stack *S, int noPegX, char* namaX, int gajiX){
    address a=alokasi(noPegX,namaX,gajiX);
    if(a==NULL){
        printf("Alokasi Gagal");
    }else{
        pushAddress(S,a);
    }
}
void pop(Stack *S, int *noPegX, char* namaX, int *gajiX){
    address a;
    a=(*S).top;
    *noPegX=(a)->noPeg;
    strcpy(namaX,(a)->nama);
    *gajiX=(a)->gaji;
    (*S).top=(a)->next;
    dealokasi(a);
}
