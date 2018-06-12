#include <stdio.h>
#include "stack.c"

int main()
{
	Stack st;
	createEmpty(&st);
	address p0 = alokasi("lagu1","Luar Biasa Kalian","NAOH",2016);
	address p1 = alokasi("lagu2","Hidup dengan tenang","The Hasbi's",2003);
	address p2 = alokasi("lagu3","TA gak kelar kelar","Budi",2020);
	pushAddress(&st,p0);
	pushAddress(&st,p1);
	pushAddress(&st,p2);
    push(&st,"lagu4","Cintaku Datang Kembali","Bayu and The Gangs",2015);
	push(&st,"lagu5","Sahabat Dunia","Makoto with the band",1994);

	char kodeTop[50];
	char judulTop[50];
	char penciptaTop[50];
	int tahunTop;
	while(!isEmpty(st)){
		pop(&st,&kodeTop,judulTop,&penciptaTop,&tahunTop);
		printf("LAGU TOP YANG DI-POP\n\nKode Lagu\t: %s\nJudul\t\t: %s\nPencipta\t: %s\nTahun\t\t: %i\n\n\n",kodeTop,judulTop,penciptaTop,tahunTop);
	}

    return 0;
}
