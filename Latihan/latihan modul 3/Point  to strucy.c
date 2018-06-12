#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct tPoint{
    int x;
    int y;
}Point;
int main(){
    Point *q;
    q=(Point*)malloc(sizeof(Point));
    printf("Address q = %p\n",q);
    (*q).x=7;
    (*q).y=4;
    printf(("Nilai yang sebenarnya dari address q adalah = (%i,%i)\n"),(*q).x,(*q).y);
    free(q);
}
