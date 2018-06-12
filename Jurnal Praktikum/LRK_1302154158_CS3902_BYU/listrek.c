#include "listrek.h"

void makeList(List *L, int nimX, char* namaX, int nilaiX){ //create list dengan satu elemen
    address p=(address)malloc(sizeof(m1));
    if(p!=NULL){
        p->nim=nimX;
        p->nama=namaX;
        p->nilai=nilaiX;
        p->next=NULL;
    }
    (*L)=p;
}
void insertLast(List *L, int nimX, char* namaX, int nilaiX){
    List q=(*L);
    if((*L)->next!=NULL){
        insertLast(&((*L)->next),nimX,namaX,nilaiX);
    }else{
        makeList(&q,nimX,namaX,nilaiX);
        (*L)->next=q;
    }
}

void cetakList(List L){ // secara rekursif mencetak nim, nama, nilai dari semua mahasiswa
    if((L)!=NULL){
        printf("NIM : %d\n",L->nim);
        printf("Nama : %s\n",L->nama);
        printf("Nilai : %d\n\n",L->nilai);
        cetakList(L->next);
    }
}
boolean cariNim(List L, int nimX){
// melakukan pencarian rekursif berdasarkan NIM, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
    if(L==NULL){
        return false;
    }else{
        if(L->nim=nimX){
            return true;
        }else{
            cariNim(L->next,nimX);
            }
    }
}
int nbElmt(List L){//menghitung banyaknya elemen di dalam list, secara rekursif
    if(L==NULL){
        return 0;
    }else{
        return (1+nbElmt(L->next));
    }
}
int sumNilai(List L){ //menjumlahkan nilai seluruh mahasiswa, secara rekursif
    if(L==NULL){
        return 0;
    }else{
        return L->nilai+sumNilai(L->next);
    }
}
int maxNilai(List L){ //mencari yang tertinggi dari field nilai, secara rekursif
    if(L->next==NULL){
        return (L->nilai);
    }else{
        if(L->nilai > maxNilai(L->next)){
            return (L->nilai);
        }else{
            maxNilai(L->next);
        }
    }
}
int minNilai(List L){ //mencari yang terendah dari field nilai, secara rekursif
    if(L->next==NULL){
        return (L->nilai);
    }else{
        if(L->nilai < minNilai(L->next)){
            return (L->nilai);
        }else{
            minNilai(L->next);
        }
    }
}

int avgNilai(List L){ //mengembalikan rata-rata nilai dari seluruh mahasiswa
    return sumNilai(L)/nbElmt(L);
}

/*void del(List *L){
    if((*L)!=NULL){
        List p=(*L)->next;
        free(*L);
        del(p);
    }
}*/
