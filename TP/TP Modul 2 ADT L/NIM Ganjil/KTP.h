#ifndef KTP_H_INCLUDED
#define KTP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "date.c"
#include <math.h>
#include <conio.h>

typedef struct {
    long long int NoKTP;
    char* Nama;
    char* Pekerjaan;
    Date TanggalLahir;
    int Tahun_terbit;
} KTP;

// Konstruktor
KTP NewKTP(long int NoX, char* NamaX, char* JobX, Date TanggalX, int Tahun_terbitX );
KTP BacaKTP();
void TulisKTP(KTP ktp,Date Sekarang);

// Tulis ke layar
///         Kartu Tanda Penduduk
///          Republik Indonesia
/// NIK             : 11111111
/// Nama            : Nama Seseorang
/// Tanggal Lahir   : 9 July 1996
/// Usia            : 20
/// Pekerjaan       : PNS
/// Tahun Terbit    : 2014
/// Berlaku Hingga  : 9 July 2019
///

boolean ValiditasKTP(long long int NoX);
/// cek validitas KTP dapat dilakukan dengan cara mengghitung digit KPT
/// Jika digit KTP 16 maka KTP valid
/// maka selain dari itu tidak Valid
/// Jika bingung silahkan lihat video berikut ini  https://www.youtube.com/watch?v=orTHv--gFDM

// Method

int Usia(KTP ktp, Date Sekarang);
/// Untuk menentukan usia dari operasi tanggal lahir dan tanggal sekarang
Date MasaAktif(KTP ktp); /// Berlaku Hingga
/// Masa aktif berlaku terhitung 5 tahun dari tahun penerbitan KTP dan dihitung 5 tahun berdasarkan tanggal lahir misal KTP terbit pada tanggal 21 Maret 2014 Maka Masa
/// Sampai tanggal 9 July 2019
/// Bingung ??? silahkan lihat KTP Masing Masing [" jangan lihat photo KTP masing masing ^-^ "]











#endif // KTP_H_INCLUDED
