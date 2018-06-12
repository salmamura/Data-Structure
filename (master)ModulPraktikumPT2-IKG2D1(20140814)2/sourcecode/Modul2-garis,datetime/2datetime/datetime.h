#include <stdio.h>
#include "boolean.h"
#include "jam.h"
#include "date.h"

#ifndef datetime_H
#define datetime_H


typedef struct {
	Jam jm;
	Date dt;
} Datetime;



// FUNGSI VALIDASI
boolean isValidDatetime(int hh, int mm, int ss, int tgl, int bln, int thn);
// Fungsi isValidDatetime: memanggil fungsi isValidJam dan isValidDate


// FUNGSI KONSTRUKTOR
Datetime makeDatetime(Jam j, Date d);

// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
Datetime bacaDatetime();
void tulisDatetime(Datetime d);
// Prosedur tulisDatetime: menampilkan datetime ke layar dengan format [dd/mm/yy]-[hh:mm:ss]



// OPERASI ARITMETIK
int dtSelisihDetik(Datetime d1, Datetime d2);
int dtSelisihHari(Datetime d1, Datetime d2);

// OPERASI RELATIONAL (PERBANDINGAN)
boolean dtEqual(Datetime d1, Datetime d2);
boolean dtNotEqual(Datetime d1, Datetime d2);
boolean dtLessThan(Datetime d1, Datetime d2);
boolean dtGreatherThan(Datetime d1, Datetime d2);


#endif
