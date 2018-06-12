/*
 *KELAS CS 38-03
 *
 *NAMA: MUHAMMAD NAHLU ALVIN ALAMSYAH
 *NIM : 1302141018
 *
 *NAMA: VENIA RESTREVA DANESTIARA
 *NIM : 1302144093
 *
 *NAMA: ANJAR PRATIWI
 *NIM : 1302144188
 *
 *NB: masih terjadi stop working di prosedur searchJadwal, mungkin karena terdapat sedikit kesalahan pada paramater I/O nya
 */


#include <stdio.h>
#include <malloc.h>
#include <string.h>

#ifndef travelagi_H
#define travelagi_H

typedef struct{
    int jj;
    int mm;
} jam;

typedef struct{
    char* asal;
    char* tujuan;
    char* pesawat;
    char* kelas;
    jam berangkat;
    jam datang;
    int harga;
} data;

typedef struct elmtPesawat *adrPesawat;
typedef struct elmtPesawat{
    char* nama;
    char* kelas;
    adrPesawat next;
} p1;

typedef struct elmtKota *adrKota;
typedef struct elmtKota{
    char* nama;
    char kode[3];
    adrKota next;
} k1;

typedef struct elmtJadwal *adrJadwal;
typedef struct elmtJadwal{
    adrKota asal;
    adrKota tujuan;
    adrPesawat pesawat;
    jam berangkat;
    jam datang;
    int harga;
    adrJadwal next;
} j1;

typedef struct elmtPemesan *adrPemesan;
typedef struct elmtPemesan{
    char* nama;
    char* gender;
    char* ID;
    adrPemesan next;
} pm1;

typedef struct{
    adrPesawat first;
} listPesawat;

typedef struct{
    adrKota first;
} listKota;

typedef struct{
    adrJadwal first;
} listJadwal;

typedef struct{
    adrPemesan first;
} listPemesan;


//FUNGSI & PROSEDUR
void buatListPesawat(listPesawat *LP);
void buatListKota(listKota *LK);
void buatListJadwal(listJadwal *LJ);
void buatListPemesan(listPemesan *LPM);

adrPesawat alokasiPesawat(char* namaX, char* kelasX);
adrKota alokasiKota(char* namaX, char kode[3]);
adrJadwal alokasiJadwal(adrKota asalX, adrKota tujuanX, adrPesawat pesawatX, jam berangkatX, jam datangX, int hargaX);
adrPemesan alokasiPemesan(char* namaX, char* genderX, char* IDX);

void insertPesawat(listPesawat *LP, adrPesawat p);
void insertKota(listKota *LK, adrKota k);
void insertJadwal(listJadwal *LJ, adrJadwal j);
void insertPemesan(listPemesan *LPM, adrPemesan pm);

void isiDataProgram(listPesawat *LP, listKota *LK, listJadwal *LJ);

adrKota searchKota(listKota LK, char kodeX[3]);
void searchJadwal(data *tiket[], listJadwal LJ, adrKota asalX, adrKota tujuanX, int *n);

void lihatListKota(listKota LK);
void lihatListPesawat(listPesawat LP);
void lihatJadwal(listJadwal LJ, listKota LK);
void pesanTiket(listJadwal LJ, listKota LK);
void cetakTiket(data tiketX, int jumlahTiket, listPemesan LPM);
void beritaAngkasa();

#endif // travelagi_H
