/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/multilistv2.pdf (Alternatif 1, hal.1)
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


#ifndef multilist1_H
#define multilist1_H


typedef struct tElmtPeg *adrPeg;
typedef struct tElmtAnak *adrAnak;

typedef struct tElmtPeg {
	int nip; // NIP pegawai bersifat unik (tidak ada yang sama)
	char* nama;
	int gajiPokok;
	adrAnak firstAnak;
	adrPeg nextPeg;
} ElmtPeg;

typedef struct tElmtAnak {
	char* nama;
	boolean gender;
	adrAnak nextAnak;
} ElmtAnak;

typedef struct {
	adrPeg firstPeg;
} ListPeg;



// HEADER PROSEDUR DAN FUNGSI

void createListPeg(ListPeg *LP); //create list kosong
adrPeg alokasiPeg(int nipX, char namaX[50], int gajiX);
void insertFirstPeg(ListPeg *LP, adrPeg p); // firstAnak diisi NULL (tambahAnak bisa dilakukan belakangan)
void insertAfterPeg(ListPeg *LP, adrPeg prevNode, adrPeg p);
void insertLastPeg(ListPeg *LP, adrPeg p); // firstAnak diisi NULL (tambahAnak bisa dilakukan belakangan)
void deleteFirstPeg(ListPeg *LP);
void deleteLastPeg(ListPeg *LP);
int nbElmtPeg(ListPeg LP); //menghitung banyaknya pegawai di dalam ListPeg
int maxGajiPeg(ListPeg LP); //mencari nilai tertinggi dari field gaji pegawai

adrAnak alokasiAnak(char namaX[50], boolean genderX);
void tambahAnak(ListPeg *LP, adrAnak a, char namaPeg[50]);

void cetakPegAnak(ListPeg LP); // mencetak data seluruh pegawai dan anak-anaknya
void cetakAnak(ListPeg LP, int nipX); // mencetak anak-anak dari pegawai dengan NIP = nipX

#endif
