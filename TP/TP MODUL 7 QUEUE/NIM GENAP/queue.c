//SALMA 1302154158
#include <stdio.h>
#include <string.h>
#include "queue.h"

void createEmpty(Queue *Q){ //create queue kosong
    (*Q).head=NULL;
    (*Q).tail=NULL;
}
address alokasi(char* kode, char* nama, char* dokter){
    address p=(address)malloc(sizeof(pasien));
    if(p!=NULL){
        (*p).kodePasien=kode;
        (*p).nama=nama;
        (*p).dokter=dokter;
        (*p).next=NULL;
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
    if((*Q).head==NULL){
        (*Q).head=p;
        (*Q).tail=p;
    }else{
        ((*Q).tail)->next=p;
        ((*Q).tail)=p;
    }
}

void add(Queue *Q, char* kode, char* nama, char* dokter){
    address p =alokasi(kode,nama,dokter);
    addAddress(Q,p);
}

void del(Queue *Q, char kode[50], char nama[50], char dokter[50]){
    address p=(*Q).head;
    strcpy(kode,(((*Q).head)->kodePasien));
    strcpy(nama,((*Q).head)->nama);
    strcpy(dokter,((*Q).head)->dokter);
    ((*Q).head)=(*p).next;
    dealokasi(p);
}

void dequeue(Queue *Q){//membuat head queue terhapus , didalam fungsi harus ada kondisi jika
//1.List kosong
//2.Isi List cuma 1
//3.Isi list banyak
    address p=(*Q).head;
    if((*Q).head==NULL){
        printf("Queue Kosong\n");
    }else{
        if((*Q).tail==1){
            (*Q).head=NULL;
            (*Q).tail=NULL;
        }else{
            (*Q).head=(*p).next;
        }
    }
}
