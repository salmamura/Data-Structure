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
	int nomorMeja;
	adrData nextData;
} data1;
typedef struct tElmtDataMenuBatal *adrDatabatal;
typedef struct tElmtDataMenuBatal {
	char* namaBatal;
	char* alamatBatal;
	int nomorMejaBatal;
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
typedef struct tElmtMeja *adrMeja;
typedef struct tElmtMeja {
    int noMeja;
    boolean status;
    adrMeja next;
} Meja;
typedef struct {
	adrMeja firstMeja;
} ListMeja;

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
void createListData(ListData *LD); //create list kosong
adrData alokasiData(char namaX[100],char alamatX[100],int noMeja);
void insertFirstData(ListData *LD, adrData d);
void insertLastData(ListData *LD, adrData d);
adrData searchData(ListData LD, int noMeja);

void createListMeja(ListMeja *LD); //create list kosong
adrMeja alokasiMeja(int noMejaX,boolean statusX);
void insertLastMeja(ListMeja *LD, adrMeja d);
adrMeja searchMeja(ListMeja LD, int mejaX);
void cetakListMeja(ListMeja LDP);
void ubahStatus(ListMeja *LDP, int nomor);

void createListMenu(ListMenu *LP); //create list kosong
adrMenu alokasiMenu(int namaMenuX, char makanan1X[30],int hargaX);
void insertMenu(ListMenu *LP, adrMenu md);
void cetakListMenu(ListMenu LP);
adrMenu searchMenu(ListMenu LMK, char* namaMenuX);
boolean searchMenubool(ListMenu LMK, char* namaMenuX);
void insertDataMenu(ListDP *LDP, adrDP md);
void createListDataMenu(ListDP *LDP); //create list kosong
adrDP alokasiDataMenu(ListData LD,ListMenu LP,int noMeja,char namaMenuX[10]);
void cetakListDataMenu(ListDP LDP);

void deleteDP(ListDP *LDP,int noMeja);
boolean searchDP(ListDP LDP,int noMeja);
adrDP searchDPadr(ListDP LDP,int noMeja);


void createListDataBatal(ListDatabatal *LDPB);
void cetakListDataBatal(ListDatabatal LDPB);
void createListDataMenuJadi(ListDatajadi *LDPJ); //create list kosong
adrDatajadi alokasiDataMenuJadi(adrDP q);
void insertDataMenuJadi(ListDatajadi *LDPJ, adrDatajadi md);
int hitungTotal(ListDatajadi LDPJ);
void cetakListDataMenuJadi(ListDatajadi LDPJ);

#endif // HEADER_H_INCLUDED
