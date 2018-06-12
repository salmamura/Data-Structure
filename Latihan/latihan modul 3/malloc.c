#include<stdio.h>
#include<malloc.h>
int main(){
    int *p;
    p=(int*)malloc(4*sizeof(int));
    if(!p){
        printf("Memory tidak tersedia lagi, silakan update RAM Anda. \n");
    }else{
        printf("Address p=%p\n",p);
        *p=135;
        printf("Nilai int yang sebenarnya dari p adalah = %i \n",*p);
    int *q;
    q=(int*)malloc(sizeof(int));
    printf("Address q=%p\n",q);
    *q=237;
    printf("Nilai int yang sebenarnya dari q adalah = %i \n",*q);
    q++;
    printf("Address q setelah diincrement ++ = %p\n",q);
    free(q);
    double *r;
    r=(double*)malloc(sizeof(double));
    printf("Address r=%p\n",r);
    *r=23729834.89234;
    printf("Nilai double yang sebenarnya dari address r adalah = %f \n",*r);
    free(r);
    }
}
