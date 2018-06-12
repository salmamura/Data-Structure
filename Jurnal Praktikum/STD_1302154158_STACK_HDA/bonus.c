#include<stdio.h>
#include<stdlib.h>
#include"bonus.h"

void createEmpty(Stack *S); //create stack kosong
address alokasi(char* kasurX);
void dealokasi(address p);
boolean isEmpty(Stack S);
void pushAddress(Stack *S, address p);
void push(Stack *S, char* kasurX);
void pop(Stack *S, char* kasurX);


void createEmpty(Stack *S){
    (*S).top=NULL;
} //create stack kosong

address alokasi(char* kasurX){
    address p=(address)malloc(sizeof(rusak));
    if(p!=NULL){
        (*p).kasur=kasurX;
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
void push(Stack *S, char* kasurX){
    address p=alokasi(kasurX);
    if(p==NULL){
        printf("Alokasi Gagal");
    }else{
        pushAddress(S,p);
    }
}
void pop(Stack *S, char* kasurX){
    address p=(*S).top;
    strcpy(kasurX,(*p).kasur);
    (*S).top=(*p).next;
    dealokasi(p);
    }
