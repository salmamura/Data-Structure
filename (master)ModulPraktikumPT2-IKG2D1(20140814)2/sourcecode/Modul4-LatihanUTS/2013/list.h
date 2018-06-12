/*SOAL UTS PRAKTIKUM PEMROGRAMAN TERSTRUKTUR 2*/
/*Buatlah body atau implementasi dari file header berikut*/
/*Cantumkan identitas Anda pada bagian comment di atas file yg Anda buat, contohnya:
  Author: Izzatul Ummah (IK-36-02, 1181200001) */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "jam.h"
#include "date.h"

#ifndef list_H
#define list_H

typedef struct tElmtList *address;
typedef struct tElmtList {
	char* nama;
	char* no_ktp; // Nomor KTP bersifat unik (tidak ada yang sama)
	int umur;
	char* asal;
	char* tujuan;
	char* kelas;
	char* no_seat;
	char* pesawat;
	Date tanggal;
	Jam jadwal;
	address next;
} elmtList;

typedef struct {
	address first;
} List;

// HEADER PROSEDUR DAN FUNGSI
/* Asumsikan semua fungsi penting seperti createList, alokasi, dealokasi, insertFirst,
 dan insertLast sudah ada dan tidak perlu dibuat (tinggal Anda panggil saja).
 Yang harus Anda buat body-nya adalah semua prosedur/fungsi di bawah ini*/

void cetakList(List L); // mencetak detail informasi dari semua penumpang pesawat
boolean searchByKTP(List L, char* ktp); // melakukan pencarian berdasarkan Nomor KTP
int maxUmur(List L); //mencari nilai yang tertinggi dari field umur
int jumlahP(List L, char* namaPswt, Date tgl, Jam waktu);
	// menghitung jumlah penumpang pada nama pesawat tertentu dengan tgl dan waktu tertentu
boolean searchSeat(List L, char* kelasX, char* seatX, string namaPesawatX, Date tgl, Jam waktu); 
	// fungsi untuk mencari apakah Kelas dan No_Seat pada Pesawat tertentu dengan tgl dan waktu 
	// tertentu, ada atau tidak di dalam list?

#endif

/* Untuk membandingkan Date atau Jam, panggil fungsi yang sudah tersedia berikut ini:
   - Fungsi ADT Jam			boolean jEqual(Jam j1, Jam j2);
   - Fungsi ADT Date		boolean dEqual(Date d1, Date d2);
*/