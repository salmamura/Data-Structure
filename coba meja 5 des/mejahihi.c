#include <stdio.h>

int main(){
    int x[10];
    x[1]=1,x[2]=1,x[3]=0,x[4]=0,x[5]=1,x[6]=1;
    int i;
    for(i=1;i<=6;i++){
        printf("%d = ",i);
        if(x[i]==0){
            printf("Kosong\n");
        }else{
            printf("Isi\n");
        }
    }
}
