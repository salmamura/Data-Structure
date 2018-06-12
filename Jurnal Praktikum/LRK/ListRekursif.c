#include <stdio.h>
#include "boolean.h"
#include "ListRekursif.h"

void makeListBill(ListOfHotel *LH, char* namaX, char* HariMasukX, char* HarikeluarX, int hargaTotalX){
    address rk = (address)malloc(sizeof(Elmtlist));

    if(rk != NULL){
        (*rk).namaPenyewa = namaX;
        (*rk).hariMasuk = HariMasukX;
        (*rk).hariKeluar = HarikeluarX;
        (*rk).hargaTotal = hargaTotalX;
        (*rk).next = NULL;
    }

    (*LH) = rk;
} //membuat list kosong

void insertLastBill(ListOfHotel *LH, char* namaX, char* HariMasukX, char* HarikeluarX, int hargaTotalX){
    ListOfHotel rk;

    if((*LH)->next != NULL){
        insertLastBill(&(*LH)->next,namaX,HariMasukX,HarikeluarX,hargaTotalX);
    }else{
        makeListBill(&rk,namaX,HariMasukX,HarikeluarX,hargaTotalX);
        (*LH)->next = rk;
    }
}

void cetakList(ListOfHotel LH){
    if(LH != NULL){
        printf("Nama\t\t: %s\n",(*LH).namaPenyewa);
        printf("Hari Masuk\t: %s\n",(*LH).hariMasuk);
        printf("Hari Keluar\t: %s\n",(*LH).hariKeluar);
        printf("Harga\t\t: %i/Hari\n\n",(*LH).hargaTotal);
        cetakList((*LH).next);
    }
} //mencetak nama penyewa, Hari masuk, Hari keluar, harga per Hari dari semua mahasiswa

boolean cariOrang(ListOfHotel LH, char* nama){
    if(LH != NULL){
        if(strcmp((*LH).namaPenyewa,nama)==0){
            return true;
        }else{
            cariOrang((*LH).next,nama);
        }
    }else{
        return NULL;
    }
}//pencarian berdasarkan nama, bila ketemu maka return address, bila tidak ketemu return NULL

int nbElmt(ListOfHotel LH){
    if((*LH).next != NULL){
        return 1+nbElmt((*LH).next);
    }else{
        return 1;
    }
} //menghitung banyaknya elemen di dalam list

int maxBill(ListOfHotel LH){
    if((*LH).next == NULL){
        return (*LH).hargaTotal;
    }else{
        if((*LH).hargaTotal > maxBill((*LH).next)){
            return (*LH).hargaTotal;
        }else{
            return maxBill((*LH).next);
        }
    }
} //mencari nilai tertinggi dari harga per Hari

int minBill(ListOfHotel LH){
    if((*LH).next == NULL){
        return (*LH).hargaTotal;
    }else{
        if((*LH).hargaTotal < minBill((*LH).next)){
            return (*LH).hargaTotal;
        }else{
            return minBill((*LH).next);
        }
    }
} //mencari nilai terendah dari harga per Hari

float avgBill(ListOfHotel LH){
    if(LH == NULL){
        return 0;
    }else{
        return sumBill(LH)/nbElmt(LH);
    }
} //mencari nilai rata-rata dari harga per Hari seluruh penyewa

int sumBill(ListOfHotel LH){
    if(LH == NULL){
        return 0;
    }else{
        return (*LH).hargaTotal + sumBill((*LH).next);
    }
} //menjumlahkan total harga per Hari seluruh penyewa
