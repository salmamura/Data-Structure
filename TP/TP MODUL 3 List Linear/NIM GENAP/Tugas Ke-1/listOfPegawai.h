#ifndef LISTOFPEGAWAI_H_INCLUDED
#define LISTOFPEGAWAI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tElmtlist *address;
typedef struct tElmtlist{
	int nip; // NIP bersifat unik (tidak ada yang sama)
	char* nama;
	int transportasi; //uang transport
	int makan; //uang makan
	int gaji; //gaji pokok
	int totalBiaya;
	address next;
}ElmtList;

typedef struct {
	address first;
}ListOfPgw;

void createListPgw(ListOfPgw *LP); //create list kosong

address alokasi(int nipX, char* namaX, int transportX, int makanX, int gajiX);
//ketika mengisikan nilai ke field totalBiaya, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processTotalPendapatan

void dealokasi(address p);

void insertFirstPgw(ListOfPgw *LP, address p);
void insertLastPgw(ListOfPgw *LP, address p);

void deleteFirstPgw(ListOfPgw *LP);
void deleteLastPgw(ListOfPgw *LP);

void prosesTotalBiaya(ListOfPgw *LP); //mengisi field totalBiaya sebagai hasil penjumlahan dari field transportasi, makan, dan gaji
void cetakListPgw(ListOfPgw LP); // mencetak nim, nama, biaya transportasi, makan, gaji, dan totalBiaya dari semua pegawai
address searchPeg(ListOfPgw LP, int nipX);
/* melakukan pencarian berdasarkan NIP, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   NIP bersifat unik (tidak ada yang sama)
*/

int nbElmt(ListOfPgw LP); //menghitung banyaknya elemen di dalam list
int maxGaji(ListOfPgw LP); //mencari nilai tertinggi dari field gaji
int minGaji(ListOfPgw LP); //mencari nilai terendah dari field gaji
float avgGaji(ListOfPgw LP); //mencari nilai rata-rata gaji seluruh pegawai
int sumTotalBiaya(ListOfPgw LP); //menjumlahkan totalBiaya seluruh pegawai

#endif // LISTOFPEGAWAI_H_INCLUDED
