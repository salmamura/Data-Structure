/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "list.c"

int main()
{
	List li;
	createList(&li);

    char a[50][50];
    strcpy(a[0],"doraemon");
	address p0 = alokasi(118129990,a[0],65);

    strcpy(a[1],"hasbi");
	address p1 = alokasi(118129991,a[1],77);

	address p2 = alokasi(118129992,"Shizuka",60);
	address p3 = alokasi(118129993,"Upin",80);
	address p4 = alokasi(118129994,"Ipin",70);
	insertFirst(&li,p0);
	insertLast(&li,p1);
	insertLast(&li,p2);
	insertLast(&li,p3);
	insertLast(&li,p4);
	cetakList(li);

	printf("[0=No,1=Yes] searchBool(li,118129991) = %i\n",searchBool(li,118129991));
	printf("search(li,118129991) = %p\n",search(li,118129991));

	printf("nbElmt = %i\n",nbElmt(li));
	printf("max = %i\n",maxNilai(li));
	printf("min = %i\n",minNilai(li));
	printf("sum = %i\n",sumNilai(li));
	printf("avg = %.1f\n",avgNilai(li));


	deleteFirst(&li);
	deleteLast(&li);
	cetakList(li);

    return 0;
}
