#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include <string.h>

typedef struct nMeja *adrMe;
typedef struct nPes *adrP;
typedef struct nMak *adrMa;
typedef struct nTunggu *adrT;

typedef struct nMeja{
    int noMeja;
    int noPelanggan;
    adrP firstP;
    adrMe next;
}Meja;

typedef struct{
    adrMe firstMe;
}lMeja;

typedef struct nPes{
    char* namaPesanan;
    int banyak;
    int harga;
    adrP next;
}Pesanan;

typedef struct nMak{
    int noMakanan;
    char* namaMakanan;
    int harga;
    adrMa next;
}Makanan;

typedef struct{
    adrMa firstMa;
}lMakanan;

typedef struct nTunggu{
    int noPelanggan;
    adrT next;
}Tunggu;

typedef struct{
    adrT headT;
    adrT tailT;
}QTunggu;

void createListMeja(lMeja *LMe);
void createListMakanan(lMakanan *LMa);
void createQueueTunggu(QTunggu *QT);

adrMe alokasiMeja(int noMejaX, int noPelangganX);
adrP alokasiPesanan(char* namaPesananX, int banyakX, int hargaX);
adrMa alokasiMakanan(int noX, char* namaX, int hargaX);
adrT alokasiTunggu(int noPelangganX);

void dealokasiMeja(adrMe p);
void dealokasiPesanan(adrP p);
void dealokasiMakanan(adrMa p);
void dealokasiTunggu(adrT p);

void isiMenuMakanan(lMakanan *LM,int noX, char* namaX, int hargaX);
void isiListMeja(lMeja *LM, int noMejaX, int noPelangganX);

void masukQueueTunggu(QTunggu *QT,int noPelX);
void keluarQueueTunggu(QTunggu *QT,int* noPelangganKeluar);

void insertPesanan(adrP *p, char* namaMakananX, int hargaX, int q);
void hitungPesanan(adrP p);
void hapusSemuaPesanan(adrMe *p);

void yaTidak(boolean *YN);
void tekanSembarang();

void pesanMakanan(adrMe *mejaKosong,lMakanan LMa);
void pengosonganMeja(lMeja *LMe, QTunggu *QT, adrMe *mejaKosong);

void delAllMeja(lMeja *LMe);
void delAllMakanan(lMakanan *LMa);
#endif // TUBES_H_INCLUDED
