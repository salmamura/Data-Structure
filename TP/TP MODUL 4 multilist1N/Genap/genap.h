// tugas pendahuluan multilist 1 n ganjil
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


#ifndef genap_H
#define genap_H


typedef struct tElmtsekolah *adrsekolah;
typedef struct tElmtmurid *adrmurid;

typedef struct tElmtsekolah {
	int noSK; // Nomor Sekolah bersifat unik (tidak ada yang sama)
	char* nama;
	int jlhSiswa;
	adrmurid firstmurid;
	adrsekolah nextsekolah;
} Elmtsekolah;

typedef struct tElmtmurid {
	char* nama;
	boolean gender;
	adrmurid nextmurid;
} Elmtmurid;

typedef struct {
	adrsekolah firstsekolah;
} Listsekolah;

// HEADER PROSEDUR DAN FUNGSI

void createListsekolah(Listsekolah *LS); //create list kosong
adrsekolah alokasisekolah(int SK, char namaX[50], int jlh);
void insertFirstsekolah(Listsekolah *LS, adrsekolah S); // firstAnak diisi NULL (tambahAnak bisa dilakukan belakangan)
void insertLastsekolah(Listsekolah *LS, adrsekolah S); // firstAnak diisi NULL (tambahAnak bisa dilakukan belakangan)

int nbElmtsekolah(Listsekolah LS); //menghitung banyaknya sekolah di dalam ListSekolah
int maxKuotasekolah(Listsekolah Ls); //mencari jumlah murid terbanyak dari filed jumlah siswa

adrAnak alokasimurid(char namaX[50], boolean genderX);
void tambahmurid(Listsekolah *LS, adrmurid m, char namasekolah[50]);

void cetaksekolahanak(Listsekolah LS); // mencetak data seluruh sekolah dengan murid-muridnya
boolean searchsekolahBool(Listsekolah LS, int SK); // mencari sekolah berdasarkan noSK, bila ketemu maka return true
adrsekolah searchsekolah(Listsekolah LS, int SK);
// searchPeg: mencari Sekolah berdasarkan noSK, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
void cetakmurid(Listmurid LS, int SK); // mencetak murid-murid dari sekolah dengan noSK = sk
boolean searchmuridBool(Listsekolah LS, char namamurid[50]); // mencari murid berdasarkan nama, bila ketemu maka return true
int searchmurid(Listsekolah LS, char namamurid[50]);
// searchmurid: mencari murid berdasarkan nama, yang pertama ketemu langsung direturn noSK sekolahnya, bila tidak ketemu maka return -1
int nbmurid(Listsekolah LS); //menghitung banyaknya murid dari semua sekolah di dalam Listsekolah
int nbMan(Listsekolah LS); //menghitung banyaknya murid laki-laki dari semua sekolah di dalam ListSekolah
int nbDaughter(Listsekolah LS); //menghitung banyaknya murid perempuan dari semua sekolah di dalam Listsekolah

#endif