#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void createEmpty(Queue *Q){
    (*Q).head=NULL;
    (*Q).tail=NULL;
} //create queue kosong
address alokasi(int kode, char* nama, char* dokter){
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
    if((Q).head==NULL){
        return true;
    }else{
        return false;
    }
}
void addAddress(Queue *Q, address p){
    if(isEmpty(*Q)==true){
        (*Q).head=p;
        (*Q).tail=p;
    }else{
        (*Q).tail->next=p;
        (*Q).tail=p;
    }
}
void add(Queue *Q, int kode, char* nama, char* dokter){
    address p=alokasi(kode,nama,dokter);
    addAddress(Q,p);
}
void del(Queue *Q, int *kode, char* nama, char* dokter){
    address p=(*Q).head;
    *kode=(*p).kodePasien;
    strcpy(nama, (*p).nama);
    strcpy(dokter, (*p).dokter);
    (*Q).head=(*p).next;
    dealokasi (p);
}
void printfInfo(Queue Q){///mencetak semua data pasien yang ada
    address p=(Q).head;
    while(p!=NULL){
        printf("kode : %d \nnama: %s \ndokter: %s\n\n"
               ,(p)->kodePasien, (p)->nama,(p)->dokter);
    p=p->next;
    }
}
void dequeue(Queue *Q){
///membuat head queue terhapus , didalam fungsi harus ada kondisi jika
///1.List kosong
///2.Isi List cuma 1
///3.Isi list banyak
    address p=(*Q).head;
    if((*Q).head==NULL){
        printf("Queue Kosong");
    }else{
        if((*Q).head==(*Q).tail){
            (*Q).head=NULL;
            (*Q).tail=NULL;
        }else{
            (*Q).head=(*p).next;
        }
    }
}
address cariPasien(Queue *Q,int pasienX){///mencari pasien berdasarkan kode pasien dan yang dioutput adalah nama Pasien dan Dokternya
    address q=(*Q).head;
    while((*q).next!=NULL){
        if(pasienX==(*q).kodePasien){
            //printfInfo(*Q);
            return q;
        }
        q=(q)->next;
    }
}

//void split(Queue Q, Queue *q1, Queue *q2){
        //createEmpty(*q1);
        //createEmpty(*q2);
        //address p=(Q).head;
       // address d=(*q1).head;
       // address e=(*q2).head;
   // while(p->next!=NULL){
    //    if(q1->kodePasien%2==0){
     //       addAddress(q1,d);
      //  }else{
       //      addAddress(q1,e);
       // }
       // p=p->next;
//    }
//}


