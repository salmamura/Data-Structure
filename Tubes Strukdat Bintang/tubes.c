#include "tubes.h"

void createListMeja(lMeja *LMe){
    (*LMe).firstMe=NULL;
}
void createListMakanan(lMakanan *LMa){
    (*LMa).firstMa=NULL;
}
void createQueueTunggu(QTunggu *QT){
    (*QT).headT=NULL;
    (*QT).tailT=NULL;
}

adrMe alokasiMeja(int noMejaX, int noPelangganX){
    adrMe p=(adrMe)malloc(sizeof(Meja));
    if(p!=NULL){
        p->noMeja=noMejaX;
        p->noPelanggan=noPelangganX;
        p->firstP=NULL;
        p->next=NULL;
    }
    return p;
}
adrP alokasiPesanan(char* namaPesananX, int banyakX, int hargaX){
    adrP p=(adrP)malloc(sizeof(Pesanan));
    if(p!=NULL){
        p->namaPesanan=namaPesananX;
        p->banyak=banyakX;
        p->harga=hargaX;
        p->next=NULL;
    }
    return p;
}
adrMa alokasiMakanan(int noX,char* namaX, int hargaX){
    adrMa p=(adrMa)malloc(sizeof(Makanan));
    if(p!=NULL){
        p->noMakanan=noX;
        p->namaMakanan=namaX;
        p->harga=hargaX;
        p->next=NULL;
    }
    return p;
}
adrT alokasiTunggu(int noPelangganX){
    adrT p=(adrT)malloc(sizeof(Tunggu));
    if(p!=NULL){
        p->noPelanggan=noPelangganX;
        p->next=NULL;
    }
    return p;
}

void dealokasiMeja(adrMe p){
    free(p);
}
void dealokasiPesanan(adrP p){
    free(p);
}
void dealokasiMakanan(adrMa p){
    free(p);
}
void dealokasiTunggu(adrT p){
    free(p);
}

void isiMenuMakanan(lMakanan *LM,int noX, char* namaX, int hargaX){
    adrMa p=alokasiMakanan(noX,namaX,hargaX);
    if((*LM).firstMa==NULL){
        (*LM).firstMa=p;
    }else{
        adrMa last=(*LM).firstMa;
        while((last->next)!=NULL){
            last=last->next;
        }
        last->next=p;
    }
}
void isiListMeja(lMeja *LM, int noMejaX, int noPelangganX){
    adrMe p=alokasiMeja(noMejaX,noPelangganX);
    if((*LM).firstMe==NULL){
        p->next=(*LM).firstMe;
        (*LM).firstMe=p;
    }else{
        adrMe last=(*LM).firstMe;
        while((last->next)!=NULL){
            last=last->next;
        }
        last->next=p;
    }
}

void masukQueueTunggu(QTunggu *QT,int noPelX){
    adrT p=alokasiTunggu(noPelX);
    if((*QT).headT==NULL){
        (*QT).headT=p;
        (*QT).tailT=p;
    }else{
        ((*QT).tailT)->next=p;
        (*QT).tailT=p;
    }
    adrT cetak=(*QT).headT;
}
void keluarQueueTunggu(QTunggu *QT,int* noPelangganKeluar){
    adrT p=(*QT).headT;
    (*noPelangganKeluar)=p->noPelanggan;
    (*QT).headT=p->next;
    if((*QT).headT==NULL){
        (*QT).tailT=NULL;
    }
    dealokasiTunggu(p);
}

void insertPesanan(adrP *p, char* namaMakananX, int hargaX, int q){
    adrP pesananMasuk=alokasiPesanan(namaMakananX,q,hargaX);
    if((*p)==NULL){
        (*p)=pesananMasuk;
    }else{
        adrP firstPesanan=(*p);
        while(firstPesanan->next!=NULL){
            firstPesanan=firstPesanan->next;
        }
        firstPesanan->next=pesananMasuk;
    }
}
void hitungPesanan(adrP p){
    int sum=0;
    printf("\nITEM\t\tQTY\t\tHARGA\n----------------------------------------\n");
    while(p!=NULL){
        int hargaTotal=p->harga*p->banyak;
        printf("%s\t%d\t\t%d\n",p->namaPesanan,p->banyak,hargaTotal);
        sum=sum+hargaTotal;
        p=p->next;
    }
    printf("----------------------------------------\nTOTAL:\t\t\t\t%d",sum);
}
void hapusSemuaPesanan(adrMe *p){
    adrP hapus;
    while((*p)->firstP!=NULL){
        if(((*p)->firstP)->next!=NULL){
            hapus=(*p)->firstP;
            (*p)->firstP=((*p)->firstP)->next;
            hapus->next=NULL;
        }else{
            hapus=(*p)->firstP;
            (*p)->firstP=NULL;
        }
        dealokasiPesanan(hapus);
    }
}

void yaTidak(boolean *YN){
    char i='a';
    while((i!='n')&&(i!='N')&&(i!='y')&&(i!='Y')){
        printf("JAWABAN[Ya=Y,Tidak=N]: ");
        i=getche();
        if((i=='Y')||(i=='y')){
            *YN=true;
        }else if((i=='n')||(i=='N')){
            *YN=false;
        }else{
            while((i!='n')&&(i!='N')&&(i!='y')&&(i!='Y')){
                printf("\nJAWABAN TIDAK DIMENGERTI. MASUKKAN KEMBALI JAWABAN[Ya=Y,Tidak=N]: ");
                i=getche();
                if((i=='Y')||(i=='y')){
                    *YN=true;
                }else if((i=='n')||(i=='N')){
                    *YN=false;
                }
            }
        }
    }
}
void tekanSembarang(){
    printf("\nTekan sembarang untuk melanjutkan");
    char a=getch();
}

void pesanMakanan(adrMe *mejaKosong,lMakanan LMa){
        boolean adaPesanan=true;
        while(adaPesanan){
            system("cls");
            printf("\nNo. Antrian: %d",(*mejaKosong)->noPelanggan);
            printf("\nNo. Meja: %d\n",(*mejaKosong)->noMeja);
            printf("\nSilahkan pilih menu yang anda inginkan:\nNo\tItem\t\tharga\n======================================\n");
            adrMa makanan=LMa.firstMa;
            while(makanan!=NULL){
                printf("%d\t%s\t%d\n",makanan->noMakanan,makanan->namaMakanan,makanan->harga);
                makanan=makanan->next;
            }
            int pilMakan;
            printf("PILIHAN: ");
            scanf("%d",&pilMakan);
            makanan=LMa.firstMa;
            boolean adaMenu=false;
            while((makanan!=NULL)&&(!adaMenu)){
                if(makanan->noMakanan==pilMakan){
                    adaMenu=true;
                }else{
                    makanan=makanan->next;
                }
            }
            if(adaMenu){
                int porsi;
                printf("Pesan berapa porsi: ");
                scanf("%d",&porsi);
                printf("\n%s sebanyak %d dimasukkan ke pesanan\n",makanan->namaMakanan,porsi);
                insertPesanan(&((*mejaKosong)->firstP),makanan->namaMakanan,makanan->harga,porsi);
            }else if(makanan==NULL){
                printf("Item yang anda pesan tidak ada dalam menu");
            }
            hitungPesanan((*mejaKosong)->firstP);
            printf("\nApakah anda mau memesan lagi?\n");
            yaTidak(&adaPesanan);
        }
        system("cls");
        printf("\nNo. Pelanggan: %d\nNo. Meja: %d\nPesanan:\n",(*mejaKosong)->noPelanggan,(*mejaKosong)->noMeja);
        hitungPesanan((*mejaKosong)->firstP);
        printf("\nSilahkan bayar di kasir. Makanan akan diantar ke meja anda.\n");
        tekanSembarang();
        system("cls");
}
void pengosonganMeja(lMeja *LMe, QTunggu *QT, adrMe *mejaKosong){
    system("cls");
    adrMe mejaKeluar=(*LMe).firstMe;
    printf("\nNo. Meja\tNo. Pelanggan\n-------------------\n");
    while(mejaKeluar!=NULL){
        printf("%d\t%d\n",mejaKeluar->noMeja,mejaKeluar->noPelanggan);
        adrP pesanan=mejaKeluar->firstP;
        mejaKeluar=mejaKeluar->next;
    }
    printf("Nomor meja yang akan dikosongkan: ");
    int noMejaKeluar;
    scanf("%d",&noMejaKeluar);
    boolean adaMeja=false;
    mejaKeluar=(*LMe).firstMe;
    system("cls");

    while((mejaKeluar!=NULL)&&(!adaMeja)){
        if(mejaKeluar->noMeja==noMejaKeluar){
            adaMeja=true;
        }else{
            mejaKeluar=mejaKeluar->next;
        }
    }
    if(adaMeja){
        printf("No. Pelanggan: %d\n",mejaKeluar->noPelanggan);
        printf("No. Meja: %d\n",mejaKeluar->noMeja);
        printf("Pesanan:\n");
        hitungPesanan(mejaKeluar->firstP);
        printf("\n\nAnda yakin ingin mengosongkan meja ini?\n");
        boolean kosongkan;
        yaTidak(&kosongkan);
        system("cls");
        if(kosongkan){
            mejaKeluar->noPelanggan=0;
            hapusSemuaPesanan(&mejaKeluar);
            (*mejaKosong)=mejaKeluar;
            printf("\nMeja %d sudah dikosongkan",mejaKeluar->noMeja);
        }
    }
}

void delAllMeja(lMeja *LMe){
    while((*LMe).firstMe!=NULL){
        adrMe del=(*LMe).firstMe;
        hapusSemuaPesanan(&del);
        (*LMe).firstMe=del->next;
        del->next=NULL;
        dealokasiMeja(del);
    }
}
void delAllMakanan(lMakanan *LMa){
    while((*LMa).firstMa!=NULL){
        adrMa del=(*LMa).firstMa;
        (*LMa).firstMa=del->next;
        del->next=NULL;
        dealokasiMakanan(del);
    }
}
