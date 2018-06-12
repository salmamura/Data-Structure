#ifndef pegawai_h
#define pegawai_h

#include <stdio.h>
#include <alloc.h>
#include <string.h>

#define nil NULL
#define next(P) (P)->next
#define nip(P) (P)->nip
#define nama(P) (P)->nama
#define transportasi(P) (P)->transportasi
#define makan(P) (P)->makan
#define gaji(P) (P)->gaji
#define totalPendapatan(P) (P)->totalPendapatan
#define first(L) ((L).first)

typedef struct tElmtlist *address;
typedef struct tElmtlist{
	int nip; // NIM bersifat unik (tidak ada yang sama)
	char nama[50];
	int transportasi; //uang transport
	int makan; //uang makan
	int gaji; //gaji pokok
	int totalPendapatan;
	address next;
}ElmtList;

typedef struct {
	address first;
}ListOfPgw;

void createListPgw(ListOfPgw *LP); //create list kosong

address alokasi(int nipX, char namaX[50], int transportX, int makanX, int gajiX);
//ketika mengisikan nilai ke field totalBiaya, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processTotalPendapatan

void dealokasi(address *P);

void insertFirstPgw(ListOfPgw *LP, address p);
void insertLastPgw(ListOfPgw *LP, address p);

void deleteFirstPgw(ListOfPgw *LP);
void deleteLastPgw(ListOfPgw *LP);

void prosesTotalPendapatan(ListOfPgw *LP); //mengisi field totalPendapatan sebagai hasil penjumlahan dari field transportasi, makan, dan gaji
void cetakListPgw(ListOfPgw LP); // mencetak nim, nama, biaya transportasi, makan, gaji, dan totalBiaya dari semua mahasiswa
address search(ListOfPgw LP, int nipX);
/* melakukan pencarian berdasarkan NIM, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   NIM bersifat unik (tidak ada yang sama)
*/

int nbElmt(ListOfPgw LP); //menghitung banyaknya elemen di dalam list
int maxGaji(ListOfPgw LP); //mencari nilai tertinggi dari field gaji
int minGaji(ListOfPgw LP); //mencari nilai terendah dari field gaji
float avgGaji(ListOfPgw LP); //mencari nilai rata-rata gaji seluruh mahasiswa
int sumTotalPendapatan(ListOfPgw LP); //menjumlahkan totalBiaya seluruh mahasiswa

#endif