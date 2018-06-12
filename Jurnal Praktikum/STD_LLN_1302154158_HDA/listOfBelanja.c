#include <stdio.h>
#include "listOfBelanja.h"

void createListBel(ListOfBelanja *LB){ //create list kosong
    (*LB).first=NULL;
}
address alokasi(char* itemX, int hargaSatX, int qtyX){
//ketika mengisikan nilai ke field subTotal, isilah dengan nilai 0 (nol), karena akan diupdate oleh procedure processSubTotal
    address p=(address)malloc(sizeof(ElmtList));
    if(p!=NULL){
        (p)->namaItem=itemX;
        (p)->hargaSatuan=hargaSatX;
        (p)->quantity=qtyX;
        (p)->next=NULL;
    }
    return p;
}
void dealokasi(address p){
    free(p);
}
void insertFirstBel(ListOfBelanja *LB, address p){
    (p)->next=(*LB).first;
    (*LB).first=p;
}

void insertLastBel(ListOfBelanja *LB, address p){
    address last=(*LB).first;
    if(last!=NULL){
        while((last)->next!=NULL){
            last=(last)->next;
        }
        (last)->next=p;
    }else{
        insertFirstBel(&*LB,p);
    }
}
void deleteFirstBel(ListOfBelanja *LB){
    address p=(*LB).first;
    if(p!=NULL){
        if((p)->next!=NULL){
            (*LB).first=((*LB).first)->next;
            (p)->next=NULL;
        }else{
            ((*LB).first)->next=NULL;
        }
    }
}
void deleteLastBel(ListOfBelanja *LB){
    address last=(*LB).first;
    if(last!=NULL){
        if((last)->next==NULL){
            deleteFirstBel(LB);
        }else{
            while(((last)->next)->next!=NULL){
                last=(last)->next;
            }
           address p=(last)->next;
           (last)->next=NULL;
           dealokasi(p);
        }
    }
}
void prosesSubTotal(ListOfBelanja *LB){ //mengisi field subTotal sebagai hasil perkalian dari hargaSatuan * quantity
    address p=(*LB).first;
    while(p!=NULL){
        p->subTotal=p->hargaSatuan*p->quantity;
        p=p->next;
    }
}
void cetakListBel(ListOfBelanja LB){ // mencetak namaItem, hargaSatuan, quantity, dan subTotal dari setiap elemen list
    address p;
    p=LB.first;
    while(p!=NULL){
        printf("\nNama Item: %s\n",p->namaItem);
        printf("Harga Satuan: %d\n",p->hargaSatuan);
        printf("Quantity: %d\n",p->quantity);
        printf("Sub Total: %d\n",p->subTotal);
        p=p->next;
    }
}
address searchBel(ListOfBelanja LB, char* namaX){
/* melakukan pencarian berdasarkan nama item, bila ketemu maka return-lah address-nya, bila tidak ketemu maka return NULL
   nama item diasumsikan unik (tidak ada yang sama)
*/
    address p;
    p=LB.first;
    while(p!=NULL&&strcmp(p->namaItem,namaX)!=0){
        p=p->next;
    }
    if(p->namaItem==namaX){
        return p;
    }else{
        return NULL;
    }
}
int nbElmt(ListOfBelanja LB){ //menghitung banyaknya elemen di dalam list
    address p;
    p=LB.first;
    int n=1;
    while(p->next!=NULL){
        n++;
        p=p->next;
    }
    return n;
}
int maxHargaSatuan(ListOfBelanja LB){ //mencari nilai tertinggi dari field hargaSatuan
    int max;
    address p;
    p=LB.first;
    max=p->hargaSatuan;
    while(p->next!=NULL){
        if(max<p->hargaSatuan){
            max=p->hargaSatuan;
        }
        p=p->next;
    }
    return max;
    }
int minHargaSatuan(ListOfBelanja LB){ //mencari nilai terendah dari field hargaSatuan
    int min;
    address p;
    p=LB.first;
    min=p->hargaSatuan;
    while(p->next!=NULL){
        if(min>p->hargaSatuan){
            min=p->hargaSatuan;
        }
        p=p->next;
    }
    return min;
    }
int totalHarga(ListOfBelanja LB){ //menjumlahkan subTotal seluruh elemen list
    int jumlah=0;
    address p;
    p=LB.first;
    while(p->next!=NULL){
        jumlah=jumlah+p->hargaSatuan;
        p=p->next;
    }
    return jumlah;
}
float avgHargaSatuan(ListOfBelanja LB){ //mencari nilai rata-rata subTotal seluruh item
    return totalHarga(LB)/nbElmt(LB);
}
