/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "bqueue.c"

int main()
{
	Queue qm;
	createEmpty(&qm);
	add(&qm,118129993,"Upin",80);
	add(&qm,118129994,"Ipin",70);
	address p0 = alokasi(118129990,"Doraemon",65);
	address p1 = alokasi(118129991,"Nobita",77);
	address p2 = alokasi(118129992,"Shizuka",60);
	addAddress(&qm,p0);
	addAddress(&qm,p1);
	addAddress(&qm,p2);

	int nimHead;
	char namaHead[50];
	int nilaiHead;
	while(!isEmpty(qm)){
		del(&qm,&nimHead,&namaHead,&nilaiHead);
		printf("HEAD YANG DI-DELETE: %d, %s, %d\n",nimHead,namaHead,nilaiHead);
	}
    return 0;
}
