#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include "boolean.h"

typedef struct {
	int x;
	int y;
} Point;

// FUNGSI KONSTRUKTOR
Point makePoint(int x, int y);


// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR

Point bacaPoint(); //fungsi untuk membaca input dari keyboard dan menulis ke layar
void tulisPoint(Point p); //prosedur untuk menampilkan point ke layar dengan format (x,y)

// OPERASI ARITMETIK
Point pTambah(Point p1, Point p2); //penjumlahan masing-masing atribut p1 dan p2
Point pKurang(Point p1, Point p2); //pengurangan masing-masing atribut p1 dan p2
float pDotProduct(Point p1, Point p2); //rumus dot product: x1*x2 + y1*y2
Point pCrossProduct(Point p1, Point p2); //pengalian masing-masing atribut p1 dan p2

// OPERASI RELATIONAL (PERBANDINGAN)
boolean pEqual(Point p1, Point p2); //memeriksa apakah p1 sama dengan p2
boolean pNotEqual(Point p1, Point p2); //memeriksa apakah p1 tidak sama dengan p2
boolean pLessThan(Point p1, Point p2); //memeriksa apakah p1 berada di sebelah kiri-bawah dari p2
boolean pGreatherThan(Point p1, Point p2); //memeriksa apakah p1 berada di sebelah kanan-atas dari p2


// FUNGSI POSISI KOORDINAT
boolean isOrigin(Point p); //memeriksa apakah p berada pada sumbu x dan y (0,0)
boolean isOnSbX(Point p); //memeriksa apakah p berada pada sumbu x
boolean isOnSbY(Point p); //memeriksa apakah p berada pada sumbu y
int kuadran(Point p); //menghasilkan nilai kuadran dari titik p (kuadran 1, 2, 3, 4) dengan syarat P bukan di titik origin atau sumbu X-Y


// OPERASI LAIN: PENCERMINAN, ROTASI, TRANSLASI
float jarakOrigin(Point p); //hitung jarak antara titik p ke pusat koordinat (0,0)
Point pMirrorSbX(Point p); //pencerminan terhadap sumbu x
Point pMirrorSbY(Point p); //pencerminan terhadap sumbu x
Point pTranslasi(Point p, int dx, int dy); //translasi sebesar dx dan dy
Point pRotasi(Point p, float angle); /* merotasikan titik p sebesar sudut angle (dalam radian)
 rumus:
    xRot = x*cos(theta) - y*sin(theta)
    yRot = x*sin(theta) + y*cos(theta)
*/

#endif // POINT_H_INCLUDED
