#include <stdio.h>
#include "date.h"
#include <math.h>
#include "boolean.h"


// FUNGSI VALIDASI
boolean isValidDate(int d, int m, int y){
    if((d>0)&&(d<=31)&&(m>0)&&(m<=12)&&(y>0)){
        return true;
    } else {
        return false;
    }
}
/* Fungsi isValidDate:
I.S.: h, m, s adalah masukan integer sebarang
F.S.: return true bila h, m, s berada dalam range yang benar untuk Date (day 1..31, month 1..12, untuk tahun tidak dibatasi)
*/


// FUNGSI KONSTRUKTOR
Date makeDate(int d, int m, int y){
    Date tgl;
    if (isValidDate(d,m,y)==true){
        tgl.dd = d;
        tgl.mm = m;
        tgl.yy = y;
    }else{
        tgl.dd = 0;
        tgl.mm = 0;
        tgl.yy = 0;
    }
    return tgl;
}

Date bacaDate(){
    int d,m,y;
    boolean b;
    Date tgl;

    b = false;
    while(b==false){
        printf("Masukkan Tanggal :"); scanf("%d",&d);
        printf("Masukkan Bulan :"); scanf("%d",&m);
        printf("Masukkan Tahun :"); scanf("%d",&y);
        if(isValidDate(d,m,y)==true){
            tgl.dd = d;
            tgl.mm = m;
            tgl.yy = y;
            b==true;
        } else{
            printf("Format tanggal yang anda masukkan salah !!! ");
            b==false;
        }

    }
    return tgl;
}
void tulisDate(Date d){
    printf("%d : %d : %d \n",d.dd,d.mm,d.yy);
}
// Prosedur tulisDate: menampilkan tanggal ke layar dengan format [dd/mm/yy]



// OPERASI PENGECEKAN SESUAI ATURAN KALENDER
boolean isKabisat(Date d){
    if(((d.yy%400==0)&&(d.yy%100!=0)) || (d.yy%4==0)){
        return true;
    } else {
        return false;
    }
}
int jumlahHari(int month){
    if(month==2){
        return 28;
    } else if((month==4)||(month==6)||(month==9)||(month==11)){
        return 30;
    }else{
        return 31;
    }
}
boolean isValidDDMMYY(Date d){
    int jmlhHari;

    if((isKabisat(d)==true) && (d.mm==2)){
        if((d.dd>0) && (d.dd<=29)){
            return true;
        }
    } else if(jmlhHari==jumlahHari(d.mm)){
        if((d.dd>0) && (d.dd <= jmlhHari)){
            return true;
        }
    }
}

// OPERASI ARITMETIK
int selisihHari(Date d1, Date d2){
    int selisih;
    selisih=((d2.yy-d1.yy)*365+(d2.mm-d1.mm)*30+(d2.dd-d1.dd));
    if(selisih<0){
        selisih=selisih*(-1);
    }
    return selisih;

}

Date nextDay(Date d){
    Date d1;
    d1=d;
    d1.dd=d1.dd+1;
    if (d1.dd>jumlahHari(d1.mm)){
        d1.dd=1;
        d1.mm=d1.mm+1;
        if(d1.mm>12){
            d1.yy=d1.yy+1;
            d1.mm=1;
        }
    }
    return d1;
}

Date nextNDay(Date d, int n){
    Date d1;
    d1=d;
    d1.dd=d1.dd+n;
    if (d1.dd>jumlahHari(d1.mm)){
        d1.dd=d1.dd-jumlahHari(d1.mm);
        d1.mm=d1.mm+1;
        if(d1.mm>12){
            d1.yy=d1.yy+1;
            d1.mm=1;
        }
    }
    return d1;
}

Date prevDay(Date d){
    Date d1;
    d1=d;
    d1.dd=d1.dd-1;
    if (d1.dd==0){
        d1.mm=d1.mm-1;
        if(d1.mm<0){
            d1.yy=d1.yy-1;
            d1.mm=12;
            d1.dd=jumlahHari(d1.mm);
        }
    }
    return d1;
}

Date prevNDay(Date d, int n){
    Date d1;
    d1=d;
    d1.dd=d1.dd-n;

    if (d1.dd<0){
        d1.mm=d1.mm-1;
        if(d1.mm<0){
            d1.yy=d1.yy-1;
            d1.mm=12;
            d1.dd=d1.dd+jumlahHari(d1.mm);
        }
    }
    return d1;
}


// OPERASI RELATIONAL (PERBANDINGAN)
boolean dEqual(Date d1, Date d2){
    if((d1.dd==d2.dd)&&(d1.mm==d2.mm)&&(d1.yy==d2.yy)){
        return true;
    }else{
        return false;
    }
}

boolean dNotEqual(Date d1, Date d2){
    if(!dEqual(d1,d2)){
        return true;
    } else {
        return false;
    }
}

boolean dLessThan(Date d1, Date d2){
    if(selisihHari(d1,d2)>0){
        return true;
    } else {
        return false;
    }
}

boolean dGreaterThan(Date d1, Date d2){
    if(selisihHari(d1,d2)<0){
        return true;
    } else {
        return false;
    }
}
