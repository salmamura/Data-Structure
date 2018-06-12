/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "bstack.c"

int main()
{
	Stack st;
	createEmpty(&st);
	push(&st,118129993,"Upin",80);
	push(&st,118129994,"Ipin",70);
	address p0 = alokasi(118129990,"Doraemon",65);
	address p1 = alokasi(118129991,"Nobita",77);
	address p2 = alokasi(118129992,"Shizuka",60);
	pushAddress(&st,p0);
	pushAddress(&st,p1);
	pushAddress(&st,p2);

	int nimTop;
	char namaTop[50];
	int nilaiTop;
	while(!isEmpty(st)){
		pop(&st,&nimTop,&namaTop,&nilaiTop);
		printf("TOP YANG DI-POP: %i, %s, %i\n",nimTop,namaTop,nilaiTop);
	}

    return 0;
}
