//1302154158//SALMA//
#include "bonus.h"


// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S){ //create stack kosong
    (*S).top=NULL;
}
address alokasi(char* hurufX){
    address p=(address)malloc(sizeof(p1));
    if(p!=NULL){
        (*p).huruf=hurufX;
    }
        return p;
}

void dealokasi(address p){
    free(p);
}
boolean isEmpty(Stack S){
    return (S).top=NULL;
}
void pushAddress(Stack *S, address p){
    (*p).next=(*S).top;
    (*S).top=p;
    (*p).next=NULL;
}
void push(Stack *S, char*hurufX){
    address p=alokasi(hurufX);
    pushAddress(S,p);
}
void pop(Stack *S, char*hurufX){
    address p=(*S).top;
    strcpy(hurufX,(*p).huruf);
    (*S).top=(*p).next;
    dealokasi(p);
}
