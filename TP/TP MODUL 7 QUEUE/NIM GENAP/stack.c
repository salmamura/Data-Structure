//1302154158//SALMA//
#include "stack.h"

void createEmpty(Stack *S){
    (*S).top=NULL;
}

address alokasi(int noPegX, char* namaX, int gajiX){
    address p=(address)malloc(sizeof(b1));
    if(p!=NULL){
        (*p).noPeg=noPegX;
        (*p).nama=namaX;
        (*p).gaji=gajiX;
    }
    return p;
}

void dealokasi(address p){
    free(p);
}

boolean isEmpty(Stack S){
    return (S).top==NULL;
}

void pushAddress(Stack *S, address p){
    (*p).next=(*S).top;
    (*S).top=p;
}

void push(Stack *S, int noPegX, char* namaX, int gajiX){
    address p=alokasi(noPegX,namaX,gajiX);
    if(p==NULL){
        printf("alokasi gagal");
    }else{
    pushAddress(S,p);
    }
}

void pop(Stack *S, int *noPegX, char* namaX, int *gajiX){
    address p=(*S).top;
    *noPegX=(*p).noPeg;
    strcpy(namaX,(*p).nama);
    *gajiX=(*p).gaji;
    (*S).top=(*p).next;
    dealokasi(p);
}


