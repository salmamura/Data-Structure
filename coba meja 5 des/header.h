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
	char* nomorMeja; // nomor telepon bersifat unik (tidak ada yang sama)
	adrData nextData;
} data1;
typedef struct tElmtDataMenuBatal *adrDatabatal;
typedef struct tElmtDataMenuBatal {
	char* namaBatal;
	char* alamatBatal;
	char* nomorMejaBatal; // nomor telepon bersifat unik (tidak ada yang sama)
	adrDatabatal nextDatabatal;
} data2;

typedef struct tElmtMenu *adrMenu;
typedef struct tElmtMenu {
	char* namaMenu;
	char* makanan1;
	int harga;
	adrMenu nextMenu;
} Menu1;

typedef struct tElmtDataMenu *adrDP;
typedef struct tElmtDataMenu {
	adrData dataPemesan;
	adrMenu MenuMakan;
	adrDP nextDP;
} dp1;
typedef struct tElmtDataMenuJadi *adrDatajadi;
typedef struct tElmtDataMenuJadi {
	adrData dataPemesanJadi;
	adrMenu MenuMakanJadi;
	adrDatajadi nextDJ;
} data3;

typedef struct nMeja *adrMe;
typedef struct nMeja{
    int noMeja;
    int noPelanggan;
    adrData firstP;
    adrMe next;
}Meja;

typedef struct{
    adrMe firstMe;
}lMeja;

typedef struct {
	adrData firstData;
} ListData;

typedef struct {
	adrMenu firstMenu;
} ListMenu;

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
void dealokasiMeja(adrMe p);
void createListData(ListData *LD); //create list kosong
void createListMeja(lMeja *LMe);

adrData alokasiData(char namaX[100],char alamatX[100],char noMeja[100]);
adrMe alokasiMeja(int noMejaX, int noPelangganX);
void insertFirstData(ListData *LD, adrData d);
void insertLastData(ListData *LD, adrData d);
adrData searchData(ListData LD, char* noMeja);
void isiListMeja(lMeja *LM, int noMejaX, int noPelangganX);

void createListMenu(ListMenu *LP); //create list kosong
adrMenu alokasiMenu(int namaMenuX, char makanan1X[30],int hargaX);
void insertMenu(ListMenu *LP, adrMenu md);
void cetakListMenu(ListMenu LP);
adrMenu searchMenu(ListMenu LMK, char* namaMenuX);
boolean searchMenubool(ListMenu LMK, char* namaMenuX);
void insertDataMenu(ListDP *LDP, adrDP md);
void createListDataMenu(ListDP *LDP); //create list kosong
adrDP alokasiDataMenu(ListData LD,ListMenu LP,char* noMeja,char namaMenuX[10]);
void cetakListDataMenu(ListDP LDP);

void deleteDP(ListDP *LDP,char* noMeja);
boolean searchDP(ListDP LDP,char* noMeja);
adrDP searchDPadr(ListDP LDP,char* noMeja);


void createListDataBatal(ListDatabatal *LDPB);
void cetakListDataBatal(ListDatabatal LDPB);
void createListDataMenuJadi(ListDatajadi *LDPJ); //create list kosong
adrDatajadi alokasiDataMenuJadi(adrDP q);
void insertDataMenuJadi(ListDatajadi *LDPJ, adrDatajadi md);
int hitungTotal(ListDatajadi LDPJ);
void cetakListDataMenuJadi(ListDatajadi LDPJ);

#endif // HEADER_H_INCLUDED
