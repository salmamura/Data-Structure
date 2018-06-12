#include "header.h"


void createStack(Stack *s){
    s->top = NULL;
    s->count=0;
}

Node* createNode(infoType info){
    Node *newNode = new Node;
    newNode->info=info;
    newNode->next=NULL;
    return newNode;
}

Node* searchNode(Stack *s, string searchID){
    Node *searchTemp = NULL, *temp = s->top;
    while(temp!=NULL){
        if(temp->info.id_barang==searchID){
            searchTemp=temp;
            break;
        }
        temp=temp->next;
    }
    return searchTemp;
}
void push(Stack *s, Node *newNode){

    // jika stack sudah memiliki 10 barang
    if(s->count>=10){
        cout << "Maksimal tumpukan sebanyak 10 barang!";
    }
    else{
        // jika stacknya kosong atau bagian top dari barang lebih berat / sama dengan barang baru
        if(s->top==NULL || s->top->info.berat >= newNode->info.berat){

            newNode->next=s->top;
            s->top=newNode;
            cout << "barang dengan ID : "<<newNode->info.id_barang<<" berhasil di-push!"<<endl;
            s->count++;
            return;
        }
        else{
            //buat stack penampung barang
            Stack tempStack;
            createStack(&tempStack);
            Node *temp1 = s->top, *temp2;



            //memindahkan barang yang lebih berat ke stack penampung
            while(temp1!=NULL && temp1->info.berat < newNode->info.berat){
                temp2=temp1;
                temp1=temp1->next;
                pop(s,0);
                temp2->next=tempStack.top;
                tempStack.top=temp2;
            }

            //memasukkan node baru ke stack asli
            push(s,newNode);


            // memanumpuk ulang barang dari stack
            temp1=tempStack.top;
            while(temp1!=NULL){
                temp2=temp1;
                temp1=temp1->next;
                push(s,temp2);
            }
        }

    }
}
void pop(Stack *s, int tipe){
    if(s->top==NULL){
        cout << "Tumpukan kosong!";
    }
    else{
        Node *temp=s->top;
        s->top=s->top->next;
        cout << "barang dengan ID : "<<temp->info.id_barang<<" berhasil di-pop!"<<endl;

        if(tipe==1) // tipe 1 artinya node top dari stack benar" dihapus, sedangkan selain itu top "hanya" dipindahkan
            delete temp;
        s->count--;
    }
}
void display(Stack s){
    if(s.top==NULL){
        cout << "Tumpukan kosong!";
    }
    else{
        cout << "Jumlah barang pada tumpukan : "<<s.count<<endl<<endl;
        Node *temp=s.top;
        while(temp!=NULL){
            cout << "ID barang    : "<<temp->info.id_barang<<endl;
            cout << "Nama barang  : "<<temp->info.nama_barang<<endl;
            cout << "Berat barang : "<<temp->info.berat<<endl;
            cout << "----------------------------"<<endl;
            temp=temp->next;
        }
    }
}
