/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "listrek.c"

int main()
{
	List lr;
	makeList(&lr,118129990,"Doraemon",65);
	insertLast(&lr,118129991,"Nobita",77);
	insertLast(&lr,118129992,"Shizuka",60);
	insertLast(&lr,118129993,"Upin",80);
	insertLast(&lr,118129994,"Ipin",70);

    /*del(&lr);*/
	cetakList(lr);

	printf("\n[0=No,1=Yes] cariNim(lr,118129992) = %i\n",cariNim(lr,118129992));
	printf("nbElmt = %i\n",nbElmt(lr));
	printf("sum = %i\n",sumNilai(lr));
	printf("avg = %i\n",avgNilai(lr));
	printf("max = %i\n",maxNilai(lr));
	printf("min = %i\n",minNilai(lr));



    return 0;
}
