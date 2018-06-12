#include "body_ktp.c"

int main () {
    KTP ktp;
    Date Tanggallahir,Now;

    Tanggallahir= makeDate(20,7,1996);
    Now = makeDate(11,9,2016);
    ktp = NewKTP(1302144074440741,"Defri Hidayat","Mahasiswa",Tanggallahir,2013);
    TulisKTP(ktp, Now);
}
