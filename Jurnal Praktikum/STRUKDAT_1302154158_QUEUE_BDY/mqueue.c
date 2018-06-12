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
	add(&qm,1010,"Upin","Dokter Gio");
	add(&qm,1212,"Ipin","Dokter Kartika");
	address p0 = alokasi(1313,"Doraemon","Dokter Edo");
	address p1 = alokasi(1414,"Nobita","Dokter Arlan");
	address p2 = alokasi(1515,"Shizuka","Dokter Wisnu");
	addAddress(&qm,p0);
	addAddress(&qm,p1);
	addAddress(&qm,p2);
	printfInfo(qm);
    printf("cariPasien(qm,1313) = %p\n",cariPasien(&qm,1313));
    dequeue(&qm);
	int kodeHead;
	char namaHead[50];
	char dokterHead[50];
	while(!isEmpty(qm)){
		del(&qm,&kodeHead,&namaHead,&dokterHead);
		printf("HEAD YANG DI-DELETE: %i, %s, %s\n",kodeHead,namaHead,dokterHead);
	}
    return 0;
   // split(&qm,q1,q2);
    //printf()
}
