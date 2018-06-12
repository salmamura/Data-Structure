//tugas pendahuluan multilist 1 n ganjil


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


#ifndef ganjil_H
#define ganjil_H


typedef struct mahasiswa *mhs;
typedef struct buku *adrBuku;

typedef struct mahasiswa {
	int nim; // nim mahasiswa bersifat unik (tidak ada yang sama)
	char* nama;
	int jumlah; //jumlah buku yang di pinjam
	adrBuku firstBuku;
	mhs nextmhs;
} ElmtMhs;

typedef struct buku {
	char* namaBuku;
	boolean type; //type buku (ebook atau book)
	adrBuku nextBuku;
} ElmtBuku;

typedef struct {
	mhs firsMhs;
} ListMhs;



// HEADER PROSEDUR DAN FUNGSI

void createListMhs(ListMhs *LP); //create list kosong
mhs alokasiMhs(int nimX, char namaX[50], int jumlahX);
void insertfirsMhs(ListMhs *LP, mhs p); // firstBuku diisi NULL (tambahBuku bisa dilakukan belakangan)
void insertLastMhs(ListMhs *LP, mhs p); // firstBuku diisi NULL (tambahBuku bisa dilakukan belakangan)
int nbElmtMhs(ListMhs LP); //menghitung banyaknya mahasiswa di dalam ListMhs
int maxJumlahBuku(ListMhs LP); //mencari nilai tertinggi dari field jumlah mahasiswa

adrBuku alokasiBuku(char namaX[50], boolean typeX);
void tambahAnak(ListMhs *LP, adrBuku a, char namaMhs[50]);

void cetakMhsBuku(ListMhs LP); // mencetak data seluruh mahasiswa dan buku yg di pinjam
boolean searchMhsBool(ListMhs LP, int nimX); // mencari mahasiswa berdasarkan nim, bila ketemu maka return true
mhs searchMhs(ListMhs LP, int nimX);
// searchPeg: mencari mahasiswa berdasarkan nim, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
void cetakBuku(ListMhs LP, int nimX); // mencetak Buku-Buku dari mahasiswa dengan nim = nimX
boolean searchBukuBool(ListMhs LP, char namaBuku[50]); // mencari buku berdasarkan nama, bila ketemu maka return true
int searchBuku(ListMhs LP, char namaAnak[50]);
// searchBuku: mencari Buku berdasarkan nama, yang pertama ketemu langsung direturn nim mahasiswanya, bila tidak ketemu maka return -1
int nbBuku(ListMhs LP); //menghitung banyaknya anak dari semua mahasiswa di dalam ListMhs
int nbebook(ListMhs LP); //menghitung banyaknya buku electronik dari semua mahasiswa di dalam ListMhs
int nbbook(ListMhs LP); //menghitung banyaknya buku fisik dari semua mahasiswa di dalam ListMhs

#endif
