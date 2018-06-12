//1302154158_SALMA
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "boolean.h"

#ifndef LISTREKURSIF_H_INCLUDED
#define LISTREKURSIF_H_INCLUDED


typedef struct tElmtlist *address;
typedef struct tElmtlist{
    char* namaPenyewa; //diasumsikan unik (tidak ada yang sama)
    char* hariMasuk;   //hari check in
    char* hariKeluar;  //hari check out
    int hargaTotal;
    address next;
}Elmtlist;

typedef address ListOfHotel;

void makeListBill(ListOfHotel *LH, char* namaX, char* hariMasukX, char* harikeluarX, int hargaTotalX);
//membuat list dengan isi masukan pertama

void insertLastBill(ListOfHotel *LH, char* namaX, char* hariMasukX, char* harikeluarX, int hargaTotalX);
void cetakList(ListOfHotel LH); //mencetak nama penyewa, hari masuk, hari keluar, harga total dari semua penyewa

boolean cariOrang(ListOfHotel LH, char* nama);
//pencarian berdasarkan nama, bila ketemu maka return address, bila tidak ketemu return NULL

int nbElmt(ListOfHotel LH); //menghitung banyaknya elemen di dalam list
int maxBill(ListOfHotel LH); //mencari nilai tertinggi dari harga total
int minBill(ListOfHotel LH); //mencari nilai terendah dari harga total
float avgBill(ListOfHotel LH); //mencari nilai rata-rata dari harga total seluruh penyewa
int sumBill(ListOfHotel LH); //menjumlahkan total harga total seluruh penyewa

#endif // LISTREKURSIF_H_INCLUDED
