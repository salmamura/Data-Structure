#include <stdio.h>
#include <alloc.h>
#include <string.h>


typedef struct tElmtlist *address;
typedef struct tElmtlist {
	int ISBN; // kodeISBN bersifat unik (tidak ada yang sama)
	char[50] judul;
	char[50] pengarang;
	int hargaKotor;
	float diskon; // diskon berbeda untuk tiap buku
	float hargaBersih;
	address next;
} ElmtList;

typedef struct {
	address First;
} ListOfBook;

void createListBook(ListOfBook *LB); //create list kosong

address alokasi(int isbnX, char[50] judulX, char[50] pengarangX, int hargaKotorX, float diskonX, float hargaBersihX);
//ketika mengisikan nilai ke field hargaBersih, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure prosesHargaBersih

void dealokasi(address P);

void insertFirstBook(ListOfBook *LB, address p);
void insertLastBook(ListOfBook *LB, address p);

void deleteFirstBook(ListOfBook *LB, address *p);
void deleteLastBook(ListOfBook *LB, address *p);

void prosesHargaBersih(ListOfBook *LB); //mengisi field hargaBersih dengan rumus hargaBersih = hargaKotor - (diskon*hargaKotor)
void cetakListBook(ListOfBook LB); // mencetak ISBN, judul, pengarang, hargaKotor, diskon, dan hargaBersih dari semua buku
address search(ListOfBook LB, int isbnX);
/* melakukan pencarian berdasarkan ISBN, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   kode ISBN bersifat unik (tidak ada yang sama)
*/

int nbElmt(ListOfBook LB); //menghitung banyaknya elemen di dalam list
int maxHargaKotor(ListOfBook LB); //mencari nilai tertinggi dari field HargaKotor
int minHargaKotor(ListOfBook LB); //mencari nilai terendah dari field HargaKotor
float avgHargaKotor(ListOfBook LB); //mencari nilai rata-rata HargaKotor seluruh buku
int totalHargaBersih(); //menjumlahkan hargaBersih seluruh buku

#endif