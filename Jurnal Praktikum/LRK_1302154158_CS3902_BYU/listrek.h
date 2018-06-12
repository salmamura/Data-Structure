//1302154158_SALMA
#ifndef LISTREK_H_INCLUDED
#define LISTREK_H_INCLUDED


/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/listRekursif.pdf
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"


typedef struct tElmtMahasiswa *address;
typedef struct tElmtMahasiswa {
	int nim; // NIM mahasiswa bersifat unik (tidak ada yang sama)
	char* nama;
	int nilai;
	address next;
} m1;

typedef address List;



// HEADER PROSEDUR DAN FUNGSI

void makeList(List *L, int nimX, char* namaX, int nilaiX); //create list dengan satu elemen
void insertLast(List *L, int nimX, char* namaX, int nilaiX);

void cetakList(List L); // secara rekursif mencetak nim, nama, nilai dari semua mahasiswa
boolean cariNim(List L, int nimX);
// melakukan pencarian rekursif berdasarkan NIM, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL

int nbElmt(List L); //menghitung banyaknya elemen di dalam list, secara rekursif
int sumNilai(List L); //menjumlahkan nilai seluruh mahasiswa, secara rekursif
int maxNilai(List L); //mencari yang tertinggi dari field nilai, secara rekursif
int minNilai(List L); //mencari yang terendah dari field nilai, secara rekursif
int avgNilai(List L); //mengembalikan rata-rata nilai dari seluruh mahasiswa
/*void del(List *L);*/
#endif // LISTREK_H_INCLUDED
