#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "string.h"
#include <math.h>



#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct tElmtData *adrData;
typedef struct tElmtData {
	char* nama;
	char* alamat;
	char* nomorTelp; // nomor telepon bersifat unik (tidak ada yang sama)
	adrData nextData;
} data1;
typedef struct tElmtDataPaketBatal *adrDatabatal;
typedef struct tElmtDataPaketBatal {
	char* namaBatal;
	char* alamatBatal;
	char* nomorTelpBatal; // nomor telepon bersifat unik (tidak ada yang sama)
	adrDatabatal nextDatabatal;
} data2;

typedef struct tElmtPaket *adrPaket;
typedef struct tElmtPaket {
	char* namaPaket;
	char* makanan1;
	char* makanan2;
	char* makanan3;
	char* makanan4;
	char* makanan5;
	int harga;
	adrPaket nextPaket;
} paket1;

typedef struct tElmtDataPaket *adrDP;
typedef struct tElmtDataPaket {
	adrData dataPemesan;
	adrPaket PaketMakan;
	adrDP nextDP;
} dp1;
typedef struct tElmtDataPaketJadi *adrDatajadi;
typedef struct tElmtDataPaketJadi {
	adrData dataPemesanJadi;
	adrPaket PaketMakanJadi;
	adrDatajadi nextDJ;
} data3;


typedef struct {
	adrData firstData;
} ListData;

typedef struct {
	adrPaket firstPaket;
} ListPaket;

typedef struct {
	adrDP firstDP;
} ListDP;
typedef struct {
    adrDatabatal firstDatabatal;
} ListDatabatal;
typedef struct {
    adrDatajadi firstDatajadi;
}ListDatajadi;

boolean inputLagi(char pilih);
void dealokasi(adrDP p);
void createListData(ListData *LD); //create list kosong
adrData alokasiData(char namaX[100],char alamatX[100],char noTelp[100]);
adrData alokasiDataAlamat(adrData q);
void insertLastData(ListData *LD, adrData d);
void insertAfterData(ListData *LD, adrData d);
void insertFirstData(ListData *LD, adrData d);
void cetakData(ListData LD);
void deleteData(ListData *LD,char* noTelp);
adrData searchData(ListData LD, char* noTelp);
boolean searchDataBool(ListData LD, char* noTelp);

void createListPaket(ListPaket *LP); //create list kosong
adrPaket alokasiPaket(char namaPaketX[10], char makanan1X[20],
char makanan2X[20], char makanan3X[20], char makanan4X[20],
char makanan5X[20], int hargaX);
void insertPaket(ListPaket *LP, adrPaket md);
void cetakListPaket(ListPaket LP);
adrPaket searchPaket(ListPaket LMK, char* namaPaketX);
boolean searchPaketbool(ListPaket LMK, char* namaPaketX);

void createListDataPaket(ListDP *LDP); //create list kosong
adrDP alokasiDataPaket(ListData LD,ListPaket LP,char* noTelp,char namaPaketX[10]);
void insertDataPaket(ListDP *LDP, adrDP md);
void insertAfterDataPaket(ListDP *LDP, adrDP d);
void cetakListDataPaket(ListDP LDP);

void deleteDPPaket(ListDP *LDP,char noTelp[100],char namaPaketX[10]);
void deleteDP(ListDP *LDP,char* noTelp);
boolean searchDP(ListDP LDP,char* noTelp);
adrDP searchDPadr(ListDP LDP,char* noTelp);
boolean cekPaket(ListDP LDP);


void createListDataBatal(ListDatabatal *LDPB);
adrDatabatal alokasiDataBatal(adrData q);
void insertDatabatal(ListDatabatal *LDPB,adrDatabatal d);
void cetakListDataBatal(ListDatabatal LDPB);

void createListDataPaketJadi(ListDatajadi *LDPJ); //create list kosong
adrDatajadi alokasiDataPaketJadi(adrDP q);
void insertDataPaketJadi(ListDatajadi *LDPJ, adrDatajadi md);
int hitungTotal(ListDatajadi LDPJ);
int hitungPaket(ListDatajadi LDPJ,char* namaPaketX);
void cetakListDataPaketJadi(ListDatajadi LDPJ);

#endif // HEADER_H_INCLUDED
