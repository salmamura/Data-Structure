/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "datetime.h"


int main()
{
    Jam ja = makeJam(6,30,45);
    Date da = makeDate(30,11,2009);
    Datetime dt1 = makeDatetime(ja,da);
	tulisDatetime(dt1);

	Jam jb = makeJam(17,59,59);
    Date db = makeDate(25,1,2010);
    Datetime dt2 = makeDatetime(jb,db);
	tulisDatetime(dt2);

	printf("dtSelisihDetik(dt1,dt2) = %i\n",dtSelisihDetik(dt1,dt2));
	printf("dtSelisihHari(dt1,dt2) = %i\n",dtSelisihHari(dt1,dt2));

	printf("[0=No,1=Yes] dtEqual(dt1,dt2) = %i\n",dtEqual(dt1,dt2));
	printf("[0=No,1=Yes] dtNotEqual(dt1,dt2) = %i\n",dtNotEqual(dt1,dt2));
	printf("[0=No,1=Yes] dtLessThan(dt1,dt2) = %i\n",dtLessThan(dt1,dt2));
	printf("[0=No,1=Yes] dtGreaterThan(dt1,dt2) = %i\n",dtGreatherThan(dt1,dt2));

    return 0;
}
