#include <stdio.h>
#include <stdio.h>
#include "stack.c"

int main()
{
	Stack st;
	createEmpty(&st);
	address p0 = alokasi(118129990,"Hasbi",  500000);
	address p1 = alokasi(118129991,"Irul",   450000);
	address p2 = alokasi(118129992,"Makoto", 400000);
	pushAddress(&st,p0);
	pushAddress(&st,p1);
	pushAddress(&st,p2);
    push(&st,118129993,"Bayu",     350000);
	push(&st,118129994,"Wisnu",    300000);

	int noPegTop;
	char namaTop[50];
	int gajiTop;
	while(!isEmpty(st)){
		pop(&st,&noPegTop,&namaTop,&gajiTop);
		printf("TOP YANG DI-POP: %i, %s, %i\n",noPegTop,namaTop,gajiTop);
	}

    return 0;
}
