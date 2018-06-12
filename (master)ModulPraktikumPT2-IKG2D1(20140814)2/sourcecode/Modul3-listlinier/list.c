#include <stdio.h>
#include "list.h"

void createList(List *L){
    L->first = NULL;
}
address alokasi(int nimX, char* namaX, int nilaiX){
    address p=(address)malloc(sizeof(mhs1));

    if(p!=NULL){
        p->nim = nimX;
        p->nama = namaX;
        p->nilai = nilaiX;
        p->next = NULL;
    }
    return p;
}
void dealokasi(address p){
    free(p);
}

void insertFirst(List *L, address p){
    p->next = L->first;
    L->first = p;
}
void insertLast(List *L, address p){
    address last=L->first;

    if(last!=NULL){
        while(last->next!=NULL){
            last = last->next;
        }
        last->next = p;
    }else{
        insertFirst(L,last);
    }

}

void deleteFirst(List *L){
    address p;

    p = L->first;

    if(p!=NULL){
        if(p->next!=NULL){
            L->first = (L->first)->next;
            p->next = NULL;
        }
    }else{
        (L->first)->next = NULL;
    }
    dealokasi(p);
}
void deleteLast(List *L){
    address last,p;

    last = L->first;

    if(last!= NULL){
        if(last->next==NULL){
            deleteFirst(L);
        }else{
            while((last->next)->next!= NULL){
            last = last->next;
            }
        p = last->next;
        last->next = NULL;
        last = NULL;
        dealokasi(p);
        }
    }
}

void cetakList(List L){
    address p;

    p = L.first;
    while(p!=NULL){
        printf("%d || %s || %d\n",p->nim,p->nama,p->nilai);
        p=p->next;
    }
}
boolean searchBool(List L, int nimX){
    address p;

    p = L.first;

    while(p!=NULL){
        if(p->nim != nimX){
            return true;
        }else{
            return false;
        }
        p=p->next;
    }
}// melakukan pencarian berdasarkan NIM, bila ketemu maka return true
address search(List L, int nimX){
    address p;

    p=L.first;

    while(p!=NULL){
        if(p->nim != nimX ){
            return p;
        }else{
            return NULL;
        }
        p=p->next;
    }

}
// melakukan pencarian berdasarkan NIM, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL

int nbElmt(List L){
    address p;
    int jml=0;

    p=L.first;

    while(p!=NULL){
        jml = jml + 1;
        p =p->next;
    }
    return jml;
} //menghitung banyaknya elemen di dalam list
int maxNilai(List L){
    address p=L.first;

    int max=0;

    while(p!=NULL){
        if(max < p->nilai){
            max = p->nilai;
        }
        p=p->next;
    }
    return max;
} //mencari yang tertinggi dari field nilai
int minNilai(List L){
    address p=L.first;
    int min = p->nilai;

    while(p!=NULL){
        if(min > p->nilai){
            min = p->nilai;
        }
        p=p->next;
    }
    return min;
} //mencari yang terendah dari field nilai
int sumNilai(List L){
    address p=L.first;
    int sum=0;

    while(p!=NULL){
        sum = sum + p->nilai;
        p=p->next;
    }
    return sum;
} //menjumlahkan nilai seluruh mahasiswa
float avgNilai(List L){
    float a=sumNilai(L);
    float b=nbElmt(L);
    return a/b;
} //mencari rata-rata nilai seluruh mahasiswa
