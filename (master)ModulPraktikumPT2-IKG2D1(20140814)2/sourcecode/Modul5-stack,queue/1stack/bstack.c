#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

void createEmpty(Stack *S){

    S->top = NULL;
} //create stack kosong
address alokasi(int nimX, char* namaX, int nilaiX){

    address p = (address)malloc(sizeof(m1));

    if(p!=NULL){
        p->nim = nimX;
        p->nama = namaX;
        p->nilai = nilaiX;
        p->next = NULL;
    }
    return p;
}
void dealokasi(address p){
    free(p);
}
boolean isEmpty(Stack S){
    if(S.top == NULL){
        return true;
    }else{
        return false;
    }
}

void pushAddress(Stack *S, address p){

    p->next = S->top;
    S->top = p;
}

void push(Stack *S, int nimX, char* namaX, int nilaiX){

    address p = alokasi(nimX,namaX,nilaiX);

    p->next = S->top;
    S->top = p;
}
void pop(Stack *S, int *nimX, char* namaX, int *nilaiX){

    address p = S->top;

    *nimX = p->nim;
    strcpy(namaX,p->nama);
    *nilaiX = p->nilai;
    S->top = p->next;
    dealokasi(p);
}
