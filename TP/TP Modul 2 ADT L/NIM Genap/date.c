#include "Date.h"

boolean isValidDate(int d, int m, int y){
    if(d<=31&&m<=12)
        return true;
}
/* Fungsi isValidDate:
I.S.: h, m, s adalah masukan integer sebarang
F.S.: return true bila h, m, s berada dalam range yang benar untuk Date (day 1..31, month 1..12, untuk tahun tidak dibatasi)
*/


// FUNGSI KONSTRUKTOR
Date makeDate(int d, int m, int y){
    Date x;
    if(isValidDate(d,m,y) == true){
        x.dd=d;
        x.mm=m;
        x.yy=y;
    } else {
        x.dd=0;
        x.mm=0;
        x.yy=0;
    }
    return x;
}
/* Fungsi makeDate:
I.S.: d, m, y adalah masukan integer sebarang
F.S.: lakukan pengecekan dengan memanggil fungsi isValid, kemudian bentuklah sebuah Date dari komponen d, m, y
*/

// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
Date bacaDate(){
    int d,m,y; Date ds; boolean stat;

    stat = false;
    while(stat == false){
        printf("Tahun   : "); scanf("%d\n",&y);
        printf("Bulan   : "); scanf("%d\n",&m);
        printf("Tanggal : "); scanf("%d\n",&d);
        if(isValidDate(d,m,y)){
            ds.dd = d; ds.mm = m; ds.yy = y; stat = true;
        }else{
            printf("Tanggal tidak Valid. Masukkan lagi yang benar\n");
            stat = false;
        }
    }
    return ds;
}
void tulisDate(Date d){
    printf("Tanggal, Bulan, Tahun : %d, %d %d\n", d.dd, d.mm, d.yy);
}
// Prosedur tulisDate: menampilkan tanggal ke layar dengan format [dd/mm/yy]

void konversiBulan (int n){

    switch(n){
        case 1 : printf("JANUARI");break;
        case 2 : printf("FEBRUARI");break;
        case 3 : printf("MARET");break;
        case 4 : printf("APRIL");break;
        case 5 : printf("MEI");break;
        case 6 : printf("JUNI");break;
        case 7 : printf("JULY");break;
        case 8 : printf("AGUSTUS");break;
        case 9 : printf("SEPTEMBER");break;
        case 10 : printf("OKTOBER");break;
        case 11 : printf("NOVEMBER");break;
        case 12 : printf("DESEMBER");break;

    }
}
