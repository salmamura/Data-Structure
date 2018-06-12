#include <stdio.h>
#include "stack.c"

int main()
{
	Stack st;
	createEmpty(&st);
	address p0 = alokasi(118129990,"Doraemon mencari Nobita","Irul");
	address p1 = alokasi(118129991,"Nobita mencari Doraemon","Hasbi");
	address p2 = alokasi(118129992,"Catur 1 langkah","Makoto");
	pushAddress(&st,p0);
	pushAddress(&st,p1);
	pushAddress(&st,p2);
    push(&st,118129993,"Upin mencari Ipin","Wisnu");
	push(&st,118129994,"Cinta itu apa???","Bayu");

	int nisbnTop;
	char judulTop[50];
	char authorTop[50];
	while(!isEmpty(st)){
		pop(&st,&nisbnTop,&judulTop,&authorTop);
		printf("TOP YANG DI-POP: %i, %s, %s\n",nisbnTop,judulTop,authorTop);
	}

    return 0;
}
