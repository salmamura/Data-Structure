void createEmpty(Stack *S){ //create stack kosong
    (*S).top=NULL;
}

address alokasi(int noPegX, char* namaX, int gajiX){
    address p=(address)malloc(sizeof(b1));
    if(p!=NULL){
        (*p).noPeg=noPegX;
        (*p).nama=namaX;
        (*p).gaji=gaji.X;
    }
    return p;
}
void dealokasi(address p){
    free (p);
}
boolean isEmpty(Stack S){
    if((S).top==NULL){
        return true;
    }else{
        return false;
    }
}
void pushAddress(Stack *S, address p){
    (*p).next=(*S).top;
    (*S).top=p;
}
void push(Stack *S, int noPegX, char* namaX, int gajiX){
    address p=alokasi(noPegX,namaX,gajiX);
    if(p==NULL){
        printf("alokasi gagal");
    }else{
    pushAddress(S,p);
    }
}
void pop(Stack *S, int *noPegX, char* namaX, int *gajiX){
    address p=(*S).top;
    *noPegX=(*p).noPeg;
    strcpy(namaX,(*p).nama);
    *gajiX=(*p).gaji;
    (*S).top=(*p).next;
    dealokasi(p);
}
