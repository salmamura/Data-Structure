/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/IntroToAdt.pdf (hal.11-12)
*/


#include <stdio.h>
#include "boolean.h"

#ifndef date_H
#define date_H

typedef struct {
	int dd;
	int mm;
	int yy;
} Date;



// FUNGSI VALIDASI
boolean isValidDate(int d, int m, int y);
/* Fungsi isValidDate:
I.S.: h, m, s adalah masukan integer sebarang
F.S.: return true bila h, m, s berada dalam range yang benar untuk Date (day 1..31, month 1..12, untuk tahun tidak dibatasi)
*/


// FUNGSI KONSTRUKTOR
Date makeDate(int d, int m, int y);
/* Fungsi makeDate:
I.S.: d, m, y adalah masukan integer sebarang
F.S.: lakukan pengecekan dengan memanggil fungsi isValid, kemudian bentuklah sebuah Date dari komponen d, m, y
*/

// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
Date bacaDate();
void tulisDate(Date d);
// Prosedur tulisDate: menampilkan tanggal ke layar dengan format [dd/mm/yy]



// OPERASI PENGECEKAN SESUAI ATURAN KALENDER
boolean isKabisat(Date d);
int jumlahHari(int month);
boolean isValidDDMMYY(Date d);


// OPERASI ARITMETIK
int selisihHari(Date d1, Date d2);
Date nextDay(Date d);
Date nextNDay(Date d, int n);
Date prevDay(Date d);
Date prevNDay(Date d, int n);


// OPERASI RELATIONAL (PERBANDINGAN)
boolean dEqual(Date d1, Date d2);
boolean dNotEqual(Date d1, Date d2);
boolean dLessThan(Date d1, Date d2);
boolean dGreaterThan(Date d1, Date d2);


#endif