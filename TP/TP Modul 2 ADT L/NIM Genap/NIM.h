#ifndef NIM_H_INCLUDED
#define NIM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef struct {
    long int NIM;
    char* Nama;
    char* Jurusan;
    Date TanggalLahir;
    Date TanggalMasuk;
} NIM;

// Fungsi Konstruktor
NIM MahasiswaBaru(long int nimX, char* namaX, char* jurusanX, Date tglLahirX, Date tglMasukX);
NIM BacaNIM();
void TulisNIM(NIM nim, Date Sekarang);

// Tulis ke layar
///         Telkom University
///          Ilmu Komputasi
/// NIM             : 11111111
/// Nama            : Nama Seseorang
/// Tanggal Lahir   : 9 July 1996
/// Usia            : 20
/// Tanggal Masuk   : 1 July 2014
/// Semester Aktif  : Semester Ganjil / Semester 5

boolean validasiNIM(long int nimX);
/// cek validitas NIM dapat dilakukan dengan cara mengghitung digit NIM
/// Jika digit KTP 10 maka NIM valid
/// maka selain dari itu tidak Valid
/// Jika bingung silahkan lihat video berikut ini  https://www.youtube.com/watch?v=orTHv--gFDM


// Method
int Usia(NIM nim,Date Sekarang);
/// Untuk menentukan usia dari operasi tanggal lahir dan tanggal sekarang
void SemesterAktif(NIM nim,Date Sekarang);
/// Untuk menentukan semester aktif dengan cara melakukan operasi tanggal sekarang dengan tanggal masuk dengan ketentuan bulan 7-12 adalah semester ganjil
/// dan bulan 1-6 adalah semester ganjil
/// Contoh :
/// Tanggal masuk 1 July 2015 maka semeter aktifnya adalah semester 3






#endif // NIM_H_INCLUDED
