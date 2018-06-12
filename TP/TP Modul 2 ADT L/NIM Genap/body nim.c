#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "NIM.h"
#include "date.c"
// Fungsi Konstruktor
NIM MahasiswaBaru(long int nimX, char* namaX, char* jurusanX, Date tglLahirX, Date tglMasukX){
    NIM anyar;
        anyar.Nim=nimX;
        anyar.Nama=namaX;
        anyar.Jurusan=jurusanX;
        anyar.TanggalLahir=tglLahirX;
        anyar.TanggalMasuk=tglMasukX;
    return anyar;

}

NIM BacaNIM(){
    long int nim;
    NIM anyar;
    anyar.NIM=nim;
    return anyar;
}


void TulisNIM(NIM nim, Date Sekarang){
    int n=nim.TanggalLahir.mm;
    printf("NIM\n : %li \n",nim.NIM);
    printf("Nama : %s \n",nim.Nama);
    printf("Tanggal Lahir\n : %i ",nim.TanggalLahir.dd);
    konversiBulan(n);
    printf(" %i\n",nim.TanggalLahir.yy);
    printf("Usia : %d \n",Usia(nim,Sekarang));
    printf("Tanggal Masuk : %d \n", nim.TanggalMasuk.dd);
    printf("Semester Aktif : %d\n",SemesterAktif(nim).yy);



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
    int count=0;
	while(nimX!=0){
		nimX=nimX/10;
		count++;

		if(nimX==10){
			return true;
		}else{
			return false;
		}
		return nimX;
	}


// Method
int Usia(NIM nim,Date Sekarang);
    int m;
    return m = Sekarang.yy-nim.TanggalLahir.yy;
}

/// Untuk menentukan usia dari operasi tanggal lahir dan tanggal sekarang
void SemesterAktif(NIM nim,Date Sekarang){
/// Untuk menentukan semester aktif dengan cara melakukan operasi tanggal sekarang dengan tanggal masuk dengan ketentuan bulan 7-12 adalah semester ganjil
/// dan bulan 1-6 adalah semester ganjil
/// Contoh :
/// Tanggal masuk 1 July 2015 maka semeter aktifnya adalah semester 3
    if (TanggalSekarang.yy-TanggalMasuk.yy)
    m.dd=nim.TanggalSekarang.dd;
    m.mm=nim.TanggalMasuk.mm;
    m.yy=nim.SemesterAktif + ;
    return m;

}
