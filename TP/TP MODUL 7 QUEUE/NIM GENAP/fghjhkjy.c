//Nisrina Nur Faizah (1302154143)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S){
    (*S).top=NULL;
} //create stack kosong

address alokasi(int nisbnX, char* judulX, char* authorX){
    address p;
    p=(address)malloc(sizeof(b1));
    if(p!=NULL){
        (p)->NISBN=nisbnX;
        (p)->judul=judulX;
        (p)->author=authorX;
        (p)->next=NULL;
    }
    return p;
}

void dealokasi(address p){
    free(p);
}

boolean isEmpty(Stack S){
    if(S.top==NULL){
        return true;
    }else{
        return false;
    }
}

void pushAddress(Stack *S, address p){
    (p)->next=(*S).top;
    (*S).top=p;
}

void push(Stack *S, int nisbnX, char* judulX, char* authorX){
    address p;
    p=alokasi(nisbnX,judulX,authorX);
    if(p==NULL){
        printf("Alokasi Gagal");
    }else{
        pushAddress(S,p);
    }
}

void pop(Stack *S, int *nisbnX, char* judulX, char* authorX){
    address p;
    p=(*S).top;
    (*nisbnX)=(p)->NISBN;
    strcpy(judulX,(p)->judul);
    strcpy(authorX,(p)->author);
    (*S).top=(p)->next;
    dealokasi(p);
}
