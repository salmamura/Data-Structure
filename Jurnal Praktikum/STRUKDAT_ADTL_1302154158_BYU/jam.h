/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/IntroToAdt.pdf (hal.4-6)
*/


#include <stdio.h>
#include "boolean.h"


#ifndef jam_H
#define jam_H

typedef struct {
	int hh;
	int mm;
	int ss;
} Jam;



// FUNGSI VALIDASI
boolean isValidJam(int h, int m, int s);
/* Fungsi isValidJam:
I.S.: h, m, s adalah masukan integer sebarang
F.S.: return true bila h, m, s berada dalam range yang benar untuk jam (0..23, 0..59, 0..59)
*/


// FUNGSI KONSTRUKTOR
Jam makeJam(int h, int m, int s);
/* Fungsi makeJam:
I.S.: h, m, s adalah masukan integer sebarang
F.S.: lakukan pengecekan dengan memanggil fungsi isValid, kemudian bentuklah sebuah Jam dari komponen h, m, s
*/

// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
Jam bacaJam();
void tulisJam(Jam j);
// Prosedur tulisJam: menampilkan jam ke layar dengan format [hh:mm:ss]


// FUNGSI KONVERSI
int jamToDetik(Jam j);
Jam detikToJam(int s);

// OPERASI ARITMETIK
int durasi(Jam jaw, Jam jakh);
Jam jMinus(Jam j1, Jam j2);
// Fungsi jMinus: mengecek j1<=j2, lalu menghitung j2-j1, outputnya berupa Jam juga
Jam jPlus(Jam j1, Jam j2);
// Fungsi jPlus: menjumlahkan j1+j2, outputnya berupa Jam juga
Jam nextDetik(Jam j);
Jam nextNDetik(Jam j, int n);
Jam prevDetik(Jam j);
Jam prevNDetik(Jam j, int n);


// OPERASI RELATIONAL (PERBANDINGAN)
boolean jEqual(Jam j1, Jam j2);
boolean jNotEqual(Jam j1, Jam j2);
boolean jLessThan(Jam j1, Jam j2);
boolean jGreaterThan(Jam j1, Jam j2);


#endif