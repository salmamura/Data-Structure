#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef LISTOFBELANJA_H_INCLUDED
#define LISTOFBELANJA_H_INCLUDED


typedef struct tElmtlist *address;
typedef struct tElmtlist {
	char* namaItem; //diasumsikan unik (tidak ada yang sama)
	int hargaSatuan;
	int quantity;
	int subTotal;
	address next;
} ElmtList;

typedef struct {
	address first;
} ListOfBelanja;

void createListBel(ListOfBelanja *LB); //create list kosong

address alokasi(char* itemX, int hargaSatX, int qtyX);
//ketika mengisikan nilai ke field subTotal, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processSubTotal

void dealokasi(address P);

void insertFirstBel(ListOfBelanja *LB, address p);
void insertLastBel(ListOfBelanja *LB, address p);

void deleteFirstBel(ListOfBelanja *LB);
void deleteLastBel(ListOfBelanja *LB);

void prosesSubTotal(ListOfBelanja *LB); //mengisi field subTotal sebagai hasil perkalian dari hargaSatuan * quantity
void cetakListBel(ListOfBelanja LB); // mencetak namaItem, hargaSatuan, quantity, dan subTotal dari setiap elemen list
address searchBel(ListOfBelanja LB, char* namaX);
/* melakukan pencarian berdasarkan nama item, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   nama item diasumsikan unik (tidak ada yang sama)
*/

int nbElmt(ListOfBelanja LB); //menghitung banyaknya elemen di dalam list
int maxHargaSatuan(ListOfBelanja LB); //mencari nilai tertinggi dari field hargaSatuan
int minHargaSatuan(ListOfBelanja LB); //mencari nilai terendah dari field hargaSatuan
int totalHarga(ListOfBelanja LB); //menjumlahkan subTotal seluruh elemen list
float avgHargaSatuan(ListOfBelanja LB); //mencari nilai rata-rata subTotal seluruh item

#endif // LISTOFBELANJA_H_INCLUDED
