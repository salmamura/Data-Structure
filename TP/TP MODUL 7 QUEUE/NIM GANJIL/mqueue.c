/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "queue.c"

int main()
{
	Queue qm;
	createEmpty(&qm);
	add(&qm,"nasabah1","Upin",800000);
	add(&qm,"nasabah2","Ipin",700000);
	address p0 = alokasi("nasabah3","Doraemon",650000);
	address p1 = alokasi("nasabah4","Nobita",770000);
	address p2 = alokasi("nasabah5","Shizuka",600000);
	addAddress(&qm,p0);
	addAddress(&qm,p1);
	addAddress(&qm,p2);
	dequeue(&qm);

	char kodeHead[50];
	char namaHead[50];
	int jumHead;
	while(!isEmpty(qm)){
		del(&qm,&kodeHead,&namaHead,&jumHead);
		printf("HEAD YANG DI-DELETE: %s, %s, %d\n",kodeHead,namaHead,jumHead);
	}
    return 0;
}
