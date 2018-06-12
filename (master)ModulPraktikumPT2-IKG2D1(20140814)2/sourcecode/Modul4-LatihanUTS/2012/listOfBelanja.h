#include <stdio.h>
#include <alloc.h>
#include <string.h>


typedef struct tElmtlist *address;
typedef struct tElmtlist {
	char[50] namaItem; //diasumsikan unik (tidak ada yang sama)
	int hargaSatuan;
	int quantity;
	int subTotal;
	address next;
} ElmtList;

typedef struct {
	address First;
} ListOfBelanja;

void createListBel(ListOfBelanja *LB); //create list kosong

address alokasi(char[50] itemX, int hargaSatX, int qtyX, int subTotalX);
//ketika mengisikan nilai ke field subTotal, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processSubTotal

void dealokasi(address P);

void insertFirstBel(ListOfBelanja *LB, address p);
void insertLastBel(ListOfBelanja *LB, address p);

void deleteFirstBel(ListOfBelanja *LB, address *p);
void deleteLastBel(ListOfBelanja *LB, address *p);

void prosesSubTotal(ListOfBelanja *LB); //mengisi field subTotal sebagai hasil perkalian dari hargaSatuan * quantity
void cetakListBel(ListOfBelanja LB); // mencetak namaItem, hargaSatuan, quantity, dan subTotal dari setiap elemen list
address search(ListOfBelanja LB, char[50] namaX);
/* melakukan pencarian berdasarkan nama item, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL 
   nama item diasumsikan unik (tidak ada yang sama)
*/

int nbElmt(ListOfBelanja LB); //menghitung banyaknya elemen di dalam list
int maxHargaSatuan(ListOfBelanja LB); //mencari nilai tertinggi dari field hargaSatuan
int minHargaSatuan(ListOfBelanja LB); //mencari nilai terendah dari field hargaSatuan
float avgHargaSatuan(ListOfBelanja LB); //mencari nilai rata-rata hargaSatuan seluruh item
int totalHarga(); //menjumlahkan subTotal seluruh elemen list

#endif