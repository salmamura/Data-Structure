/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Materi   : List Linier Berkait Pointer (untuk yang tabel/kontigu tidak diajarkan implementasinya di praktikum)
Reference Utama:
- http://kur2003.if.itb.ac.id/file/LIST%20LINIER.pdf
- http://kur2003.if.itb.ac.id/file/ListBhsC.pdf
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


#ifndef list_H
#define list_H


typedef struct tElmtMahasiswa *address;
typedef struct tElmtMahasiswa {
	int nim; // NIM mahasiswa bersifat unik (tidak ada yang sama)
	char* nama;
	int nilai;
	address next;
} mhs1;

typedef struct {
	address first;
} List;



// HEADER PROSEDUR DAN FUNGSI

void createList(List *L); //create list kosong
address alokasi(int nimX, char* namaX, int nilaiX);
void dealokasi(address p);

void insertFirst(List *L, address p);
void insertLast(List *L, address p);

void deleteFirst(List *L);
void deleteLast(List *L);

void cetakList(List L); // mencetak nim, nama, nilai dari semua mahasiswa
boolean searchBool(List L, int nimX); // melakukan pencarian berdasarkan NIM, bila ketemu maka return true
address search(List L, int nimX);
// melakukan pencarian berdasarkan NIM, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL

int nbElmt(List L); //menghitung banyaknya elemen di dalam list
int maxNilai(List L); //mencari yang tertinggi dari field nilai
int minNilai(List L); //mencari yang terendah dari field nilai
int sumNilai(List L); //menjumlahkan nilai seluruh mahasiswa
float avgNilai(List L); //mencari rata-rata nilai seluruh mahasiswa

#endif



