//1302154158_SALMA
#include "listrekursif.h"

void makeListBill(ListOfHotel *LH, char* namaX, char* hariMasukX, char* harikeluarX, int hargaTotalX){//membuat list dengan isi masukan pertama
    address a = (address)malloc(sizeof(Elmtlist));
    if(a!=NULL){
        a->namaPenyewa=namaX;
        a->hariMasuk=hariMasukX;
        a->hariKeluar=harikeluarX;
        a->hargaTotal=hargaTotalX;
        a->next=NULL;
    }
    (*LH)=a;
}


void insertLastBill(ListOfHotel *LH, char* namaX, char* hariMasukX, char* harikeluarX, int hargaTotalX){
    ListOfHotel b=(*LH);
    if((*LH)->next!=NULL){
        insertLastBill(&((*LH)->next),namaX,hariMasukX,harikeluarX,hargaTotalX);
    }else{

        makeListBill(&b,namaX,hariMasukX,harikeluarX,hargaTotalX);
        (*LH)->next=b;
    }
}

void cetakList(ListOfHotel LH){ //mencetak nama penyewa, hari masuk, hari keluar, harga total dari semua penyewa
    if(LH!=NULL){
        printf(" Nama Penyewa : %s\n
               Hari Masuk   : %s\n
               Hari Keluar  : %s\n
               Harga Total  : %d \n"
               ,LH->namaPenyewa,LH->hariMasuk,LH->hariKeluar,LH->hargaTotal);
        cetakList(LH->next);
    }
}

boolean cariOrang(ListOfHotel LH, char* nama){//pencarian berdasarkan nama, bila ketemu maka return address, bila tidak ketemu return NULL
    if(LH==NULL){
        return false;
    }else{
        if(strcmp(LH->namaPenyewa,nama)){
            return true;
        }else{
            return cariOrang(LH->next,nama);
        }
    }
}


int nbElmt(ListOfHotel LH){ //menghitung banyaknya elemen di dalam list
    if(LH==NULL){
        return 0;
    }else{
        return(1+nbElmt(LH->next));
    }
}

int maxBill(ListOfHotel LH){ //mencari nilai tertinggi dari harga total
    if(LH==NULL){
        return 0;
    }else{
        if((LH)->hargaTotal>maxBill(LH->next)){
            return LH->hargaTotal;
        }else{
            return maxBill(LH->next);
        }
    }
}

int minBill(ListOfHotel LH){ //mencari nilai terendah dari harga total
    if(LH==NULL){
        return 0;
    }else{
        if(LH->hargaTotal<maxBill(LH->next)){
            return (LH)->hargaTotal;
        }else{
            return maxBill(LH->next);
        }
    }
}

float avgBill(ListOfHotel LH){ //mencari nilai rata-rata dari harga total seluruh penyewa
    return(sumBill(LH)/nbElmt(LH));
}
int sumBill(ListOfHotel LH){ //menjumlahkan total harga total seluruh penyewa
    if(LH==NULL){
        return 0;
    }else{
        return(LH->hargaTotal+sumBill(LH->next));
    }
}
