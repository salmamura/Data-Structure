#include <stdio.h>


void tukar(int *x,int *y){
    int w;

    w=*x;
    *x=*y;
    *y=w;
}
int main(){

    int x,y;
    char* p[50];
    printf("nama = ");scanf("%s",&p);
    printf("x = ");scanf("%i",&x);
    printf("y = ");scanf("%i",&y);

    tukar(&x,&y);
    printf("x = %i dan y = %i",x,y);
    if(p == "kali"){
        printf("\ncoba");
    }
    return 0;
}
