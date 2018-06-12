/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "date.h"

int main()
{
    Date da = makeDate(30,11,2009);
	tulisDate(da);

    Date db = makeDate(25,1,2010);
	tulisDate(db);

	printf("Mencetak boolean [0=No, 1=Yes]\n");
	printf("isKabisat(da) = %i\n",isKabisat(da));
	printf("isKabisat(db) = %i\n",isKabisat(db));

	printf("jumlahHari(2) = %i\n",jumlahHari(2));
	printf("jumlahHari(8) = %i\n",jumlahHari(8));

	printf("selisihHari(da,db) = %i\n",selisihHari(da,db));

	printf("[0=No,1=Yes] dEqual(da,db) = %i\n",dEqual(da,db));
	printf("[0=No,1=Yes] dNotEqual(da,db) = %i\n",dNotEqual(da,db));
	printf("[0=No,1=Yes] dLessThan(da,db) = %i\n",dLessThan(da,db));
	printf("[0=No,1=Yes] dGreaterThan(da,db) = %i\n",dGreaterThan(da,db));

    return 0;
}
