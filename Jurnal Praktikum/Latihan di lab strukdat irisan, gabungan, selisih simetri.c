#include<stdio.h>

typedef struct tnode* Address;//type address: ^Node
typedef int InfoType;//type InfoType:integer
typedef struct tNode{//type Node : <Info : InfoType, Next : Address>
    InfoType info;
    Address Next;
    //procedure khususu=konstruktor
    //tNode(){Info=0; Next=0;}//konstruktor kalau tidak diset NULL nodenya
    //tNode()(InfoType x){Info=x; Next=0;}
}Node;
typedef struct tList{
    Addree First;
    tList(){First=0;}
}List;

void Append(List*L, InfoType Info){
    Address p=malloc(sizeof(Node));
    P->Info=Info;
    P->next=NULL;
    if(pFIRST(L)==0){
        pFIRST(l)=p;
    }else{
        Address pred=pFIRST(L);
        while(NEXT(pred)){//*while pred not null*/ //digunakan untuk menggeser ke posisi belakang
            pred=NEXT(pred);
        }
    }
}

List MergeList(List L1, List L2){
    List L3;
    Address p1=
    Address p2=
    }


    while(p1){
        Append(&L3, info)
    }

#define FIRST(L) L.First
#define pFIRST(L) L->First
#define NEXT(P) P->Next
#define INFO(P) P->Info

/*operasi*'/
//Function MergeList(INPUT L1,L2:List)->List
//Kamus:
P1,p2:address
L3:List
Algoritma:
P1<-First(L1)
P2<-First(L2)
While(P1<>NULL and P1<>NULL)
    if info(P1)<Info(P2) then
        Append(L3,(Info(p1))
        P1<-next(P1)
    else if Info(P1)>Info(P2) then
        Append(L3,(Info(p2))
        P1<-next(P2)
    else Append(L3,(Info(p1)) P1<-temp..(P);P2(...),
