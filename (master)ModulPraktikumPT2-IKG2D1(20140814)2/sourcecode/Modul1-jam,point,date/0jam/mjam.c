/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "jam.h"

int main()
{
    Jam ja = makeJam(6,30,45);
	tulisJam(ja);
	
	Jam jb = makeJam(17,59,59);
	tulisJam(jb);
	
	printf("ja diubah ke detik = %i\n",jamToDetik(ja));
	printf("jb diubah ke detik = %i\n",jamToDetik(jb));
	
	Jam jc = detikToJam(7285);
	tulisJam(jc);
	
	printf("Durasi atau selisih dari ja-jb= %i\n",durasi(ja,jb));
	
	printf("[0=No,1=Yes] jEqual(ja,jb) = %i\n",jEqual(ja,jb));
	printf("[0=No,1=Yes] jNotEqual(ja,jb) = %i\n",jNotEqual(ja,jb));
	printf("[0=No,1=Yes] jLessThan(ja,jb) = %i\n",jLessThan(ja,jb));
	printf("[0=No,1=Yes] jGreaterThan(ja,jb) = %i\n",jGreaterThan(ja,jb));

    return 0;
}
