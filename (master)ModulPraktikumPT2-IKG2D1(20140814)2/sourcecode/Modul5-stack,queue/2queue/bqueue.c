#include <stdio.h>
#include "queue.h"

void createEmpty(Queue *Q){
Q->head = NULL;
Q->tail = NULL;
} //create queue kosong
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
boolean isEmpty(Queue Q){

    if(Q.head==NULL){
        return true;
    }else{
        return false;
    }
}

void addAddress(Queue *Q, address p){

    if(isEmpty(*Q)){
        Q->head = p;
        Q->tail = p;
    }else{
        (Q->tail)->next = p;
        Q->tail = p;

    }
}
void add(Queue *Q, int nimX, char* namaX, int nilaiX){

    address p = alokasi(nimX,namaX,nilaiX);

    if(p==NULL){
        printf("alokasi gagal");
    }else{
        addAddress(Q,p);
    }
}
void del(Queue *Q, int *nimX, char* namaX, int *nilaiX){

    address p;

    *nimX = (Q->head)->nim;
    strcpy(namaX,(Q->head)->nama);
    *nilaiX = (Q->head)->nilai;
    p = Q->head;
    Q->head=p->next;
    dealokasi(p);
}
