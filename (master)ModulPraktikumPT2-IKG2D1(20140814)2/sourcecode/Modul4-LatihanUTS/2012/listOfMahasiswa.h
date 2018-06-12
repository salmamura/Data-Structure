#include <stdio.h>
#include <alloc.h>
#include <string.h>


typedef struct tElmtlist *address;
typedef struct tElmtlist {
	int nim; // NIM bersifat unik (tidak ada yang sama)
	char[50] nama;
	int transportasi;
	int makan;
	int biayaKost;
	int totalBiaya;
	address next;
} ElmtList;

typedef struct {
	address First;
} ListOfMhs;

void createListMhs(ListOfMhs *LM); //create list kosong

address alokasi(int nimX, char[50] namaX, int transportX, int makanX, int biayaKostX, int totalBiayaX);
//ketika mengisikan nilai ke field totalBiaya, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processTotalBiaya

void dealokasi(address P);

void insertFirstMhs(ListOfMhs *LM, address p);
void insertLastMhs(ListOfMhs *LM, address p);

void deleteFirstMhs(ListOfMhs *LM, address *p);
void deleteLastMhs(ListOfMhs *LM, address *p);

void prosesTotalBiaya(ListOfMhs *LM); //mengisi field totalBiaya sebagai hasil penjumlahan dari field transportasi, makan, dan biayaKost
void cetakListMhs(ListOfMhs LM); // mencetak nim, nama, biaya transportasi, makan, biayaKost, dan totalBiaya dari semua mahasiswa
address search(ListOfMhs LM, int nimX);
/* melakukan pencarian berdasarkan NIM, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   NIM bersifat unik (tidak ada yang sama)
*/

int nbElmt(ListOfMhs LM); //menghitung banyaknya elemen di dalam list
int maxKost(ListOfMhs LM); //mencari nilai tertinggi dari field biayaKost
int minKost(ListOfMhs LM); //mencari nilai terendah dari field biayaKost
float avgKost(ListOfMhs LM); //mencari nilai rata-rata biayaKost seluruh mahasiswa
int sumTotalBiaya(); //menjumlahkan totalBiaya seluruh mahasiswa

#endif