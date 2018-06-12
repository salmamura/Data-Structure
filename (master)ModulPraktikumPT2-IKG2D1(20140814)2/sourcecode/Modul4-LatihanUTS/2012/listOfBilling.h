#include <stdio.h>
#include <alloc.h>
#include <string.h>


// INI ADALAH STRUKTUR DATA UNTUK MENGELOLA BILLING WARNET

typedef struct tElmtlist *address;
typedef struct tElmtlist {
	char[50] namaPelanggan;  //diasumsikan unik (tidak ada yang sama)
	int jamMulai; // jam yang valid: mulai dari 0 sampai 23
	int jamSelesai; // jam yang valid: mulai dari 0 sampai 23
	int hargaPerJam;
	int billing;
	address next;
} ElmtList;

typedef struct {
	address First;
} ListOfBill;

void createListBill(ListOfBill *LB); //create list kosong

address alokasi(char[50] namaX, int jamMulaiX, int jamSelesaiX, int hargaPerJamX, int billing);
//ketika mengisikan nilai ke field billing, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processBilling

void dealokasi(address P);

void insertFirstBill(ListOfBill *LB, address p);
void insertLastBill(ListOfBill *LB, address p);

void deleteFirstBill(ListOfBill *LB, address *p);
void deleteLastBill(ListOfBill *LB, address *p);

void prosesBilling(ListOfBill *LB); // mengisi field billing dengan rumus billing = (jamSelesai - jamMulai) * hargaPerJam
void cetakListMhs(ListOfBill LB); // mencetak nama pelanggan, jam mulai, jam selesai, harga per jam, dan billing dari semua mahasiswa
address search(ListOfBill LB, char[50] nama);
/* melakukan pencarian berdasarkan nama, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   nama pelanggan diasumsikan unik (tidak ada yang sama)
*/

int nbElmt(ListOfBill LB); //menghitung banyaknya elemen di dalam list
int maxBill(ListOfBill LB); //mencari nilai tertinggi dari field billing
int minBill(ListOfBill LB); //mencari nilai terendah dari field billing
float avgBill(ListOfBill LB); //mencari nilai rata-rata billing seluruh pelanggan
int totalBilling(); //menjumlahkan billing seluruh pelanggan

#endif