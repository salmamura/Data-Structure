/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/multilistv2.pdf (Alternatif 2, hal.2)
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


#ifndef multilist2_H
#define multilist2_H


typedef struct tElmtPegawai *adrPeg;
typedef struct tElmtPegawai {
	int nip; // NIP pegawai bersifat unik (tidak ada yang sama)
	char* nama;
	int gajiPokok;
	adrPeg nextPeg;
} peg1;

typedef struct tElmtAnak *adrAnak;
typedef struct tElmtAnak {
	char* nama;
	boolean gender;
	adrPeg parent;
	adrAnak nextAnak;
} a1;

typedef struct {
	adrPeg firstPeg;
} ListPeg;

typedef struct {
	adrAnak firstAnak;
} ListAnak;



// HEADER PROSEDUR DAN FUNGSI

void createListPeg(ListPeg *LP); //create list kosong
adrPeg alokasiPeg(int nipX, char* namaX, int gajiX);
void insertFirstPeg(ListPeg *LP, adrPeg p);
void insertLastPeg(ListPeg *LP, adrPeg p);
int nbElmtPeg(ListPeg LP); //menghitung banyaknya pegawai di dalam ListPeg
int maxGajiPeg(ListPeg LP); //mencari nilai tertinggi dari field gaji pegawai

void createListAnak(ListAnak *LA); //create list kosong
adrAnak alokasiAnak(char* namaX, boolean genderX, adrPeg parentX);
void insertFirstAnak(ListAnak *LA, adrAnak a);
void insertLastAnak(ListAnak *LA, adrAnak a);

void cetakPegAnak(ListPeg LP, ListAnak LA); // mencetak data seluruh pegawai dan anak-anaknya dengan format tampilan seperti di multilist1.h
boolean searchPegBool(ListPeg LP, int nipX); // mencari pegawai berdasarkan NIP, bila ketemu maka return true
adrPeg searchPeg(ListPeg LP, int nipX);
// searchPeg: mencari pegawai berdasarkan NIP, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
void cetakAnak(ListPeg LP, ListAnak LA, int nipX); // mencetak anak-anak dari pegawai dengan NIP = nipX
boolean searchAnakBool(ListAnak LA, char* namaAnak); // mencari anak berdasarkan nama, bila ketemu maka return true
int searchAnak(ListAnak LA, char* namaAnak);
// searchAnak: mencari anak berdasarkan nama, yang pertama ketemu langsung direturn NIP orangtuanya, bila tidak ketemu maka return -1
int nbAnak(ListAnak LA); //menghitung banyaknya anak di ListAnak 
int nbSon(ListAnak LA); //menghitung banyaknya anak laki-laki di ListAnak
int nbDaughter(ListAnak LA); //menghitung banyaknya anak laki-laki di ListAnak


#endif
