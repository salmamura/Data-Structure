#ifndef pulsa_h
#define pulsa_h

#include <stdio.h>
#include <alloc.h>
#include <string.h>

#define namaPengguna(P) (P)->namaPengguna
#define jamMulai(P) (P)->jamMulai
#define jamSelesai(P) (P)->jamSelesai
#define pulsaPerJam(P) (P)->pulsaPerJam
#define biaya(P) (P)->biaya
#define nil NULL
#define next(P) (P)->next
#define first(L) ((L).first)

// INI ADALAH STRUKTUR DATA UNTUK MENGELOLA PEMAKAIAN TELEPON (DALAM JAM), DAN MENGHITUNG BIAYA YANG HARUS DIBAYAR UNTUK MENELEPON

typedef struct tElmtlist *address;
typedef struct tElmtlist {
	char namaPengguna[50];  //diasumsikan unik (tidak ada yang sama)
	int jamMulai; // jam yang valid: mulai dari 0 sampai 23
	int jamSelesai; // jam yang valid: mulai dari 0 sampai 23
	int pulsaPerJam;
	int biaya;
	address next;
} ElmtList; 

typedef struct {
	address first;
} ListOfPulsa;

void createListPulsa(ListOfPulsa *LP); //create list kosong

address alokasi(char namaX[50], int jamMulaiX, int jamSelesaiX, int pulsaPerJamX);
//ketika mengisikan nilai ke fieldbiaya, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processBiaya

void dealokasi(address *P);

void insertFirstPulsa(ListOfPulsa *LP, address p);
void insertLastPulsa(ListOfPulsa *LP, address p);

void deleteFirstPulsa(ListOfPulsa *LP);
void deleteLastPulsa(ListOfPulsa *LP);

void prosesBiaya(ListOfPulsa *LP); // mengisi field biaya dengan rumus biaya = (jamSelesai - jamMulai) * pulsaPerJam
void cetakList(ListOfPulsa LP); // mencetak nama pengguna, jam mulai, jam selesai, pulsa per jam, dan biaya penggunaan telepon
address search(ListOfPulsa LP, char nama[50]);
/* melakukan pencarian berdasarkan nama, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   nama pelanggan diasumsikan unik (tidak ada yang sama)
*/

int nbElmt(ListOfPulsa LP); //menghitung banyaknya elemen di dalam list
int maxBiaya(ListOfPulsa LP); //mencari nilai tertinggi dari field biaya
int minBiaya(ListOfPulsa LP); //mencari nilai terendah dari field biaya
float avgBiaya(ListOfPulsa LP); //mencari nilai rata-rata field biaya dari seluruh pengguna
int totalBiaya(); //menjumlahkan biaya seluruh penggunaan

#endif
