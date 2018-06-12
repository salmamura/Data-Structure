#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void createEmpty(Stack *S){
    (*S).top=NULL;
} //create stack kosong

address alokasi(char* kodeX, char* judulX, char* penciptaX, int yearX){
    address p=(address)malloc(sizeof(lagu));
    if(p!=NULL){
        (*p).kodeLagu=kodeX;
        (*p).judul=judulX;
        (*p).pencipta=penciptaX;
        (*p).tahun=yearX;
        (*p).next=NULL;
    }
    return p;
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
    (*p).next=(*S).top;
    (*S).top=p;
}
void push(Stack *S, char* kodeX, char* judulX, char* penciptaX, int yearX){
    address p=alokasi(kodeX,judulX,penciptaX,yearX);
    if(p==NULL){
        printf("Alokasi Gagal");
    }else{
        pushAddress(S,p);
    }
}
void pop(Stack *S, char* kodeX, char* judulX, char* penciptaX, int *yearX){
    address p=(*S).top;
    strcpy(kodeX,(*p).kodeLagu);
    strcpy(judulX,(*p).judul);
    strcpy(penciptaX,(*p).pencipta);
    *yearX=(*p).tahun;
    (*S).top=(*p).next;
    dealokasi(p);
    }
