
#include <stdio.h>
#include "bonus.c"

int main()
{
	Stack st;
	createEmpty(&st);
	address p0 = alokasi("s");
	address p1 = alokasi("a");
	address p2 = alokasi("l");
	address p3 = alokasi("m");
	address p4 = alokasi("a");
	address p5 = alokasi(" ");
	address p6 = alokasi("c");
	address p7 = alokasi("a");
	address p8 = alokasi("n");
	pushAddress(&st,p0);
	pushAddress(&st,p1);
	pushAddress(&st,p2);
	pushAddress(&st,p3);
	pushAddress(&st,p4);
	pushAddress(&st,p5);
	pushAddress(&st,p6);
	pushAddress(&st,p7);
    pushAddress(&st,p8);

	push(&st,"t");
    push(&st,"i");
    push(&st,"k");

	char kasurTop[50];
	printf("Kalimat sebelum dibalik : salma cantik\n");
    printf("Kalimat setelah dibalik : ");
	while(!isEmpty(st)){
        pop(&st,&kasurTop);
        printf("%s",kasurTop);
	}
    return 0;
}
