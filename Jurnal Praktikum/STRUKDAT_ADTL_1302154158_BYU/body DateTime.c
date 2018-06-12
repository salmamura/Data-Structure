#include"datetime.h"





    // FUNGSI VALIDASI
    boolean isValidDatetime(int hh, int mm, int ss, int tgl, int bln, int thn){
    // Fungsi isValidDatetime: memanggil fungsi isValidJam dan isValidDate
        if((isValidJam(hh,mm,ss))&&(isValidDate(tgl,bln,thn))){
            return true;
        }
    }



    // FUNGSI KONSTRUKTOR
    Datetime makeDatetime(Jam j, Date d){
        Datetime DT;
        DT.jm=j;
        return DT;
    }

    // FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
    Datetime bacaDatetime(){
        Date d;
        Jam j;
        d=bacaDate();
        j=bacaJam();
        return makeDatetime(j,d);
    }
    void tulisDatetime(Datetime d){
    // Prosedur tulisDatetime: menampilkan datetime ke layar dengan format [dd/mm/yy]-[hh:mm:ss]
        tulisJam(d.jm);
        tulisDate(d.dt);
    }


    // OPERASI ARITMETIK
    int dtSelisihDetik(Datetime d1, Datetime d2){
        int s1,s2;
        s1=jamToDetik(d1.jm);
        s2=jamToDetik(d2.jm);
        return abs(s1-s2);
    }

    int dtSelisihHari(Datetime d1, Datetime d2){
        return selisihHari(d1.dt,d2.dt);
    }

    // OPERASI RELATIONAL (PERBANDINGAN)
    boolean dtEqual(Datetime d1, Datetime d2){
        if((dEqual(d1.dt,d2.dt)==true)&&(jEqual(d1.jm,d2.jm)==true)){
            return true;
        }
    }

    boolean dtNotEqual(Datetime d1, Datetime d2){
        if(dNotEqual(d1.dt,d2.dt)==true && jNotEqual(d1.jm,d2.jm)==true){
            return true;
        }
    }

    boolean dtLessThan(Datetime d1, Datetime d2){
        if(dLessThan(d1.dt,d2.dt)==true){
            return true;
        }else{
            if(dEqual(d1.dt,d2.dt)==true&&jLessThan(d1.jm,d2.jm)==true){
                return true;
            }
        }
    }
    boolean dtGreatherThan(Datetime d1, Datetime d2){
        if(dGreaterThan(d1.dt,d2.dt)==true){
           return true;
        }else{
            if(dEqual(d1.dt,d2.dt)==true&&jGreaterThan(d1.jm,d2.jm)==true){
                return true;
            }
        }
    }
