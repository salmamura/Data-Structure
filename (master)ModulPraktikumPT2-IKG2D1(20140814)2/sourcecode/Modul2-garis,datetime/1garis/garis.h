/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/IntroToAdt.pdf (hal.9-10)
*/


#include <stdio.h>
#include "boolean.h"
#include "point.h"

#ifndef garis_H
#define garis_H


typedef struct{
	Point pa;
	Point pb;
} Garis;




// FUNGSI KONSTRUKTOR
Garis makeGaris(Point p1, Point p2);

// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
Garis bacaGaris();
void tulisGaris(Garis g);
// Prosedur tulisGaris: menampilkan garis ke layar dengan format [(x,y),(x,y)]


// FUNGSI POSISI KOORDINAT
float panjangGaris(Garis g);
float gradien(Garis g);
float titikTengah(Garis g);
float titikPotongSbY(Garis g);
float titikPotongSbX(Garis g);
float sudutSbX(Garis g);
// Fungsi sudutSbX: menghitung sudut (dalam radian, 0..PI rad) yang dibentuk oleh garis g dengan sumbu X positif


// FUNGSI POSISI DUA GARIS
boolean isSejajar(Garis g1, Garis g2);
boolean isTegakLurus(Garis g1, Garis g2);
float sudutPotong(Garis g1, Garis g2);

// OPERASI LAIN: PENCERMINAN, ROTASI, TRANSLASI
Garis gMirrorSbX(Garis g);
Garis gMirrorSbY(Garis g);
Garis gTranslasi(Garis g, int dx, int dy);
Garis gRotasi(Garis g, float angle);
// Fungsi rotasi: merotasikan titik pa dan titik pb sebesar sudut angle (dalam radian)


#endif