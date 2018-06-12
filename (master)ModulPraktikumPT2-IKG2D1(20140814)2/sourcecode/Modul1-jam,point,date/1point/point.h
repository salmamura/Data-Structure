
#include <stdio.h>
#include <math.h>
#include "boolean.h"


#ifndef point_H
#define point_H

typedef struct {
	float x;
	float y;
} Point;




// FUNGSI KONSTRUKTOR
Point makePoint(int x, int y);
/* Fungsi makePoint:
I.S.: x, y adalah masukan integer sebarang
F.S.: terbentuk sebuah Point dari komponen x, y
*/

// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
Point bacaPoint();
void tulisPoint(Point p);
// Prosedur tulisPoint: menampilkan point ke layar dengan format (x,y)


// OPERASI ARITMETIK
Point pTambah(Point p1, Point p2);
Point pKurang(Point p1, Point p2);
float pDotProduct(Point p1, Point p2);
Point pCrossProduct(Point p1, Point p2);


// FUNGSI POSISI KOORDINAT
boolean isOrigin(Point p);
boolean isOnSbX(Point p);
boolean isOnSbY(Point p);
int kuadran(Point p);
// Fungsi kuadran: menghasilkan nilai kuadran dari titik p (kuadran 1, 2, 3, 4) dengan syarat P bukan di titik origin atau sumbu X-Y


// OPERASI LAIN: PENCERMINAN, ROTASI, TRANSLASI
float jarakOrigin(Point p);
Point pMirrorSbX(Point p);
Point pMirrorSbY(Point p);
Point pTranslasi(Point p, int dx, int dy);
Point pRotasi(Point p, float angle);



#endif
