/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/multilistv2.pdf (langsung pakai Alternatif 3, lihat hal.4)
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include <string.h>


#ifndef multilist_nm_H
#define multilist_nm_H


typedef struct tElmtDosen *adrDosen;
typedef struct tElmtDosen {
	char* kodeDosen; // kode dosen bersifat unik (tidak ada yang sama)
	char* namaDosen;
	int gajiPokok;
	adrDosen nextDosen;
} dos1;

typedef struct tElmtMataKuliah *adrMK;
typedef struct tElmtMataKuliah {
	char* kodeMK; // kode matakuliah bersifat unik (tidak ada yang sama)
	char* namaMK;
	int sks;
	adrMK nextMK;
} mk1;

typedef struct tElmtMKDosen *adrMKDOS;
typedef struct tElmtMKDosen {
	adrDosen dosenPengajar;
	adrMK matkul;
	adrMKDOS nextMKDOS;
} mkd1;


typedef struct {
	adrDosen firstDosen;
} ListDosen;

typedef struct {
	adrMK firstMK;
} ListMK;

typedef struct {
	adrMKDOS firstMKDOS;
} ListMKDOS;




// HEADER PROSEDUR DAN FUNGSI

void createListDosen(ListDosen *LD); //create list kosong
adrDosen alokasiDosen(char* kodeX, char* namaX, int gajiX);
void insertFirstDosen(ListDosen *LD, adrDosen d);
void insertLastDosen(ListDosen *LD, adrDosen d);

void createListMK(ListMK *LMK); //create list kosong
adrMK alokasiMK(char* kodeX, char* namaX, int sksX);
void insertFirstMK(ListMK *LMK, adrMK m);
void insertLastMK(ListMK *LMK, adrMK m);

void createListMKDOS(ListMKDOS *LMKDOS); //create list kosong
adrMKDOS alokasiMKDOS(ListDosen LD, ListMK LMK, char kodeDosen[3], char kodeMK[6]);
void insertFirstMKDOS(ListMKDOS *LMKDOS, adrMKDOS md);
void insertLastMKDOS(ListMKDOS *LMKDOS, adrMKDOS md);


void cetakListMKDOS(ListMKDOS LMKDOS); // mencetak pasangan data kode matakuliah dan kode dosen yang mengajar matakuliah tersebut
boolean searchDosenBool(ListDosen LD, char* kodeX); // search dosen berdasarkan kode, bila ketemu maka return true
adrDosen searchDosen(ListDosen LD, char* kodeX);
// searchDosen: search dosen berdasarkan kode, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
boolean searchMKBool(ListMK LMK, char* kodeX); // search matakuliah berdasarkan kode, bila ketemu maka return true
adrMK searchMK(ListMK LMK, char* kodeX);
// searchMK: search matakuliah berdasarkan kode, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL

void cetakMKbyDosen(ListDosen LD, ListMKDOS LMKDOS, char* kodeDosenX);
// cetakMKbyDosen: mencetak semua kode matakuliah yang pernah/sedang diajar oleh kodedosenX
void cetakDosenbyMK(ListMK LMK, ListMKDOS LMKDOS, char* kodeMKX);
// cetakDosenbyMK: mencetak semua kode dosen yang pernah/sedang mengajar matakuliah kodeMKX

boolean isRelated(ListDosen LD, char* kodeDosenX, ListMK LMK, char* kodeMKX, ListMKDOS LMKDOS);
// isRelated: mereturn true bila ada hubungan/relasi antara kodeDosenX tertentu dengan kodeMKX tertentu
// atau dengan kata lain, pernah atau sedang mengajar matakuliah tsb

int totalSKSDosen(ListDosen LD, char* kodeDosenX, ListMKDOS LMKDOS);
// totalSKSDosen: mereturn total SKS dari semua matakuliah yang pernah/sedang diajar oleh kodeDosenX


#endif
