#include "body nim.c"

int main () {

    NIM nim;
    Date Tanggallahir,Now,Masuk;

    Tanggallahir= makeDate(22,11,1997);
    Now = makeDate(13,9,2016);
    Masuk = makeDate(22,08,2015);

    nim = NewNIM(1302154158,"1302154158", "Ilmu Komputasi", Tanggallahir, Masuk);
    TulisNIM(nim, Now);





}

