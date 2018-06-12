/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "boolean.h"
#include "garis.h"

int main()
{
    Point pa = makePoint(2,1);
    Point pb = makePoint(8,9);
    Garis ga = makeGaris(pa,pb);
	tulisGaris(ga);

	printf("panjangGaris(ga) = %f\n",panjangGaris(ga));
	printf("gradien(ga) = %f\n",gradien(ga));
	printf("titikTengah(ga) = %f\n",titikTengah(ga));
	printf("titikPotongSbX(ga) = %f\n",titikPotongSbX(ga));
	printf("titikPotongSbY(ga) = %f\n",titikPotongSbY(ga));
	printf("sudutSbX(ga) = %f\n",sudutSbX(ga));

	Garis gb = gMirrorSbX(ga);
	Garis gc = gMirrorSbY(ga);
	Garis gd = gTranslasi(ga,20,10);
	Garis ge = gRotasi(ga,1.57);
	tulisGaris(gb);
	tulisGaris(gc);
	tulisGaris(gd);
	tulisGaris(ge);

    return 0;
}
