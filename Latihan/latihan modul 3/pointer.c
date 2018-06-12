#include<stdio.h>
int main (){
    int x;
    x=135;
    printf("x=%i\n",x);
    int *p;
    p=&x;
    printf("p=%p\n",p);
    printf("Nilai variabel pada memory dengan address %p adalah %i\n\n",&x,x);
    x++;
    p++;
    printf("Setelah penambahan : \n");
    printf("x=%i\n",x);
    printf("p=%p\n",p);
    x--;
    p--;
    printf("\nSetelah pengurangan : \n");
    printf("x=%i\n",x);
    printf("p=%p\n",p);
}
