/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "latihan.c"

int main()
{
	Queue qm;
	createEmpty(&qm);
	add(&qm,"pasien1","Upin","Dokter Gio");
	add(&qm,"pasien2","Ipin","Dokter Kartika");
	address p0 = alokasi("pasien3","Doraemon","Dokter Edo");
	address p1 = alokasi("pasien4","Nobita","Dokter Arlan");
	address p2 = alokasi("pasien5","Shizuka","Dokter Wisnu");
	addAddress(&qm,p0);
	addAddress(&qm,p1);
	addAddress(&qm,p2);
    dequeue(&qm);

	char kodeHead[50];
	char namaHead[50];
	char dokterHead[50];
	while(!isEmpty(qm)){
		del(&qm,&kodeHead,&namaHead,&dokterHead);
		printf("HEAD YANG DI-DELETE: %s, %s, %s\n",kodeHead,namaHead,dokterHead);
	}
    return 0;
}
