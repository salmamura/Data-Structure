#ifndef kosan_h
#define kosan_h

#include <stdio.h>
#include <alloc.h>
#include <string.h>

#define namaPenyewa(P) (P)->namaPenyewa
#define bulanMasuk(P) (P)->bulanMasuk
#define bulanKeluar(P) (P)->bulanKeluar
#define hargaPerBulan(P) (P)->hargaPerBulan
#define totalHarga(P) (P)->totalHarga
#define nil NULL
#define next(P) (P)->next
#define first(L) ((L).first)

// INI ADALAH STRUKTUR DATA UNTUK MENGELOLA BILLING WARNET

typedef struct tElmtlist *address;
typedef struct tElmtlist {
	char namaPenyewa[50];  //diasumsikan unik (tidak ada yang sama)
	int bulanMasuk; // bulan yang valid: mulai dari 1 sampai 12
	int bulanKeluar; // bulan yang valid: mulai dari 1 sampai 12
	int hargaPerBulan;
	int totalHarga;
	address next;
} ElmtList;

typedef struct {
	address first;
} ListOfKosan;

void createListBill(ListOfKosan *LK); //create list kosong

address alokasi(char namaX[50], int bulanMasukX, int bulanKeluarX, int hargaPerBulanX);
//ketika mengisikan nilai ke field totalHarga, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processBilling

void dealokasi(address *P);

void insertFirstBill(ListOfKosan *LK, address p);
void insertLastBill(ListOfKosan *LK, address p);

void deleteFirstBill(ListOfKosan *LK);
void deleteLastBill(ListOfKosan *LK);

void prosesBilling(ListOfKosan *LK); // mengisi field totalHarga dengan rumus totalHarga = (bulanKeluar - bulanMasuk) * hargaPerBulan
void cetakListMhs(ListOfKosan LK); // mencetak nama penyewa, bulanMasuk, bulanKeluar, hargaPerBulan, dan totalHarga dari semua mahasiswa
address search(ListOfKosan LK, char nama[50]);
/* melakukan pencarian berdasarkan nama, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   nama penyewa diasumsikan unik (tidak ada yang sama)
*/

int nbElmt(ListOfKosan LK); //menghitung banyaknya elemen di dalam list
int maxBill(ListOfKosan LK); //mencari nilai tertinggi dari field totalHarga
int minBill(ListOfKosan LK); //mencari nilai terendah dari field totalHarga
float avgBill(ListOfKosan LK); //mencari nilai rata-rata totalHarga seluruh penyewa
int totalBilling(ListOfKosan LK); //menjumlahkan totalHarga seluruh penyewa

#endif