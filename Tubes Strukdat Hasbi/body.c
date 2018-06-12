#include <stdio.h>
#include "header.h"

boolean inputLagi(char pilih){
    if(pilih == 'Y'){
        return true;
    }else{
        return false;
    }
}
void dealokasi(adrDP p){
    free(p);
}
void createListData(ListData *LD){
    LD->firstData = NULL;
} //create list kosong
adrData alokasiData(char* namaX,char* alamatX,char* noTelpX){

    adrData p=(adrData)malloc(sizeof(data1));
    if(p!=NULL){
        p->nama = namaX;
        p->alamat = alamatX;
        p->nomorTelp = noTelpX;
        p->nextData = NULL;
    }
    return p;
}
adrData alokasiDataAlamat(adrData q){

    adrData p = (adrData)malloc(sizeof(data1));
    if(p!=NULL){
        p->nama = q->nama;
        p->alamat = q->alamat;
        p->nomorTelp = q->nomorTelp;
        p->nextData = NULL;
    }
    return p;
}
void insertFirstData(ListData *LD, adrData d){

    d->nextData = LD->firstData;
    LD->firstData = d;
}
void insertLastData(ListData *LD, adrData d){


    adrData p=LD->firstData;

    if(LD->firstData==NULL){
        insertFirstData(LD,d);
    }else{
        while(p->nextData != NULL){
            p = p->nextData;
        }
        p->nextData = d;
    }
}
void insertAfterData(ListData *LD, adrData d){

    adrData p = LD->firstData;

    while(strcmp(p->nomorTelp,d->nomorTelp)!=0){
        p = p->nextData;
    }
    if(p->nextData == NULL){
        p->nextData = d;
    }else{
        d->nextData = p->nextData;
        p->nextData = d;
    }
}
void deleteData(ListData *LD, char* noTelp){

    adrData p = LD->firstData;
    adrData q = LD->firstData;
    if(strcmp(p->nomorTelp,noTelp)==0){
        LD->firstData = p->nextData;
        free(p);
    }else{
        while(p!=NULL){
            if(strcmp(p->nomorTelp,noTelp)==0){
                break;
            }
            q = p;
            p = p->nextData;
        }
        if(p->nextData == NULL){
            q->nextData = NULL;
            free(p);
        }else{
            q->nextData = p->nextData;
            free(p);
        }
    }
}
void cetakData(ListData LD){

    adrData p = LD.firstData;
    while(p!=NULL){
        printf("Nama = %s\n",p->nama);
        printf("Alamat = %s\n",p->alamat);
        printf("No. Telepon = %s\n",p->nomorTelp);
        p = p->nextData;
    }
}
adrData searchData(ListData LD, char* noTelp){

    adrData p = LD.firstData;

    while(p!=NULL){
        if(strcmp(p->nomorTelp,noTelp)==0){
            return p;
        }
        p = p->nextData;
    }
    return p;
}
boolean searchDataBool(ListData LD, char* noTelp){
    adrData p = LD.firstData;

    while(p!=NULL){
        if(strcmp(p->nomorTelp,noTelp)==0){
            return true;
        }
        p = p->nextData;
    }
    return false;
}
void createListPaket(ListPaket *LP){
    LP->firstPaket = NULL;
} //create list kosong
adrPaket alokasiPaket(char namaPaketX[10], char makanan1X[20],
char makanan2X[20], char makanan3X[20], char makanan4X[20],
char makanan5X[20], int hargaX){

    adrPaket p = (adrPaket)malloc(sizeof(paket1));

    if(p!=NULL){
        p->namaPaket = namaPaketX;
        p->makanan1 = makanan1X;
        p->makanan2 = makanan2X;
        p->makanan3 = makanan3X;
        p->makanan4 = makanan4X;
        p->makanan5 = makanan5X;
        p->harga = hargaX;
        p->nextPaket = NULL;
    }
    return p;
}
void insertPaket(ListPaket *LP, adrPaket md){
    adrPaket p = LP->firstPaket;

    if(LP->firstPaket==NULL){
        LP->firstPaket = md;
    }else{
        md->nextPaket = p->nextPaket;
        p->nextPaket = md;
    }
}
void cetakListPaket(ListPaket LP){

    adrPaket p = LP.firstPaket;

    while(p!=NULL){
        printf("\n%s  : %s, %s, %s, %s, %s\n",p->namaPaket,p->makanan1,p->makanan2,
               p->makanan3,p->makanan4,p->makanan5);
        printf("HARGA : RP.%d,00\n",p->harga);
        p = p->nextPaket;
    }
}
adrPaket searchPaket(ListPaket LMK, char* namaPaketX){

    adrPaket p = LMK.firstPaket;

    while(p!=NULL){
        if(strcmp(p->namaPaket,namaPaketX)==0){
            return p;
        }
        p = p->nextPaket;
    }
    return p;
}
boolean searchPaketbool(ListPaket LMK, char* namaPaketX){

    adrPaket p = LMK.firstPaket;

    while(p!=NULL){
        if(strcmp(p->namaPaket,namaPaketX)==0){
            return true;
        }
        p = p->nextPaket;
    }
    return false;

}
void insertDataPaket(ListDP *LDP, adrDP md){

    adrDP p = LDP->firstDP;

    if(p==NULL){
        LDP->firstDP = md;
    }else{
        while(p->nextDP != NULL){
            p = p->nextDP;
        }
        p->nextDP = md;
    }
}
void insertAfterDataPaket(ListDP *LDP, adrDP d){

    adrDP p = LDP->firstDP;

    while((p->dataPemesan)->nomorTelp != (d->dataPemesan)->nomorTelp){
        p = p->nextDP;
    }
    if(p->nextDP == NULL){
        p->nextDP = d;
    }else{
        d->nextDP = p->nextDP;
        p->nextDP = d;
    }
}
void createListDataPaket(ListDP *LDP){
    LDP->firstDP = NULL;
} //create list kosong
adrDP alokasiDataPaket(ListData LD,ListPaket LP,char* noTelp,char namaPaketX[10]){

    adrDP p = (adrDP)malloc(sizeof(dp1));
    if(p!=NULL){
        p->dataPemesan= searchData(LD,noTelp);
        p->PaketMakan = searchPaket(LP,namaPaketX);
        p->nextDP = NULL;
    }
    return p;
}
void cetakListDataPaket(ListDP LDP){

    adrDP p;
    int j=1;

    if(LDP.firstDP == NULL){
        printf("List kosong\n");
    }else{
        p = LDP.firstDP;
        printf("\tTABEL DATA PEMESAN\n");
        printf("NO.\tNAMA PEMESAN\tALAMAT\t\tNOMOR TELP\tPAKET\n");
        while(p != NULL){
            printf("%d\t%p\t\t%s\t\t%s\t\t%s\n",j,p->dataPemesan,(p->dataPemesan)->alamat,(p->dataPemesan)->nomorTelp
                   ,(p->PaketMakan)->namaPaket);
            j = j+1;
            p = p->nextDP;
        }
    }
}
void deleteDPPaket(ListDP *LDP,char* noTelp, char namaPaketX[10]){
    adrDP p = LDP->firstDP;
    adrDP q = LDP->firstDP;
    while(p!=NULL){
        if(strcmp((p->dataPemesan)->nomorTelp,noTelp)==0 && strcmp(namaPaketX,(p->PaketMakan)->namaPaket)==0){
            break;
        }
        q = p;
        p = p->nextDP;
    }
    if(p->nextDP == NULL){
        LDP->firstDP = NULL;
        dealokasi(p);
    }else if(p == LDP->firstDP){
        LDP->firstDP = p->nextDP;
        dealokasi(p);
    }else{
        q->nextDP = p->nextDP;
        dealokasi(p);
    }
}
void deleteDP(ListDP *LDP,char* noTelp){
    adrDP p = LDP->firstDP;
    adrDP q = LDP->firstDP;
    if(p->nextDP == NULL){
        LDP->firstDP = NULL;
        dealokasi(p);
    }else{
        while(p!=NULL){
            if(strcmp((p->dataPemesan)->nomorTelp,noTelp)==0){
                break;
            }
            q = p;
            p = p->nextDP;
        }if(p->nextDP == NULL){
            q->nextDP = NULL;
            dealokasi(p);
        }else if(p == LDP->firstDP){
            LDP->firstDP = p->nextDP;
            dealokasi(p);
        }else{
            q->nextDP = p->nextDP;
            dealokasi(p);
        }
    }
}
boolean searchDP(ListDP LDP,char* noTelp){

    adrDP p = LDP.firstDP;
    while(p!=NULL){
        if(strcmp((p->dataPemesan)->nomorTelp,noTelp)==0){
            return true;
        }
        p = p->nextDP;
    }
    return false;
}
adrDP searchDPadr(ListDP LDP,char* noTelp){
    adrDP p = LDP.firstDP;
    while(p!=NULL){
        if(strcmp((p->dataPemesan)->nomorTelp,noTelp)==0){
            return p;
        }
        p = p->nextDP;
    }
    return p;
}
boolean cekPaket(ListDP LDP){
    adrDP p = LDP.firstDP;
    adrDP q = p->nextDP;
    int counter = 0;
    if(q == NULL){
        return false;
    }else{
        while(p!=NULL){
            if(strcmp((p->dataPemesan)->nomorTelp,(q->dataPemesan)->nomorTelp)==0){
                counter = counter + 1;
            }
            q = p;
            p = p->nextDP;
        }
        if(counter > 1){
            return true;
        }else{
            return false;
        }
    }
}

void createListDataBatal(ListDatabatal *LDPB){
    LDPB->firstDatabatal = NULL;
}
adrDatabatal alokasiDataBatal(adrData q){
    adrDatabatal p = (adrDatabatal)malloc(sizeof(data2));

    if(p!=NULL){
        p->namaBatal = q->nama;
        p->alamatBatal = q->alamat;
        p->nomorTelpBatal = q->nomorTelp;
        p->nextDatabatal = NULL;
    }
    return p;
}
void insertDatabatal(ListDatabatal *LDPB, adrDatabatal d){

    if(LDPB->firstDatabatal == NULL){
        LDPB->firstDatabatal = d;
    }else{
        adrDatabatal p = LDPB->firstDatabatal;
        while(p->nextDatabatal != NULL){
            p = p->nextDatabatal;
        }
        p->nextDatabatal = d;
    }
}
void cetakListDataBatal(ListDatabatal LDPB){

    if(LDPB.firstDatabatal == NULL){
        printf("List kosong\n");
    }else{
        adrDatabatal p = LDPB.firstDatabatal;
        int j=1;
        printf("\tDATA-DATA PEMESAN YANG BATAL\n");
        printf("NO. NAMA PEMESAN\tALAMAT\t\tNOMOR TELP\n");
        while(p!=NULL){
            printf("%d %s\t\t%s\t\t%s\n",j,p->namaBatal,p->alamatBatal,
                    p->nomorTelpBatal);
            j = j + 1;
            p = p->nextDatabatal;
        }
    }
}

void createListDataPaketJadi(ListDatajadi *LDPJ){
    LDPJ->firstDatajadi = NULL;
} //create list kosong
adrDatajadi alokasiDataPaketJadi(adrDP q){

    adrDatajadi p = (adrDatajadi)malloc(sizeof(data3));

    if(p!=NULL){
        p->dataPemesanJadi = q->dataPemesan;
        p->PaketMakanJadi = q->PaketMakan;
        p->nextDJ = NULL;
    }
    return p;
}
void insertDataPaketJadi(ListDatajadi *LDPJ, adrDatajadi md){

    if(LDPJ->firstDatajadi == NULL){
        LDPJ->firstDatajadi = md;
    }else{
        adrDatajadi p = LDPJ->firstDatajadi;
        while(strcmp((p->dataPemesanJadi)->nomorTelp,(md->dataPemesanJadi)->nomorTelp)!=0 && p->nextDJ!=NULL){
            p = p->nextDJ;
        }
        if(p->nextDJ == NULL){
            p->nextDJ = md;
        }else{
            md->nextDJ = p->nextDJ;
            p->nextDJ = md;
        }
    }
}
int hitungTotal(ListDatajadi LDPJ){

    adrDatajadi p = LDPJ.firstDatajadi;
    int total = 0;

    while(p!=NULL){
        total = total + (p->PaketMakanJadi)->harga;
        p = p->nextDJ;
    }
    return total;
}
int hitungPaket(ListDatajadi LDPJ,char* namaPaketX){

    adrDatajadi p = LDPJ.firstDatajadi;
    int counter = 0;

    while(p!=NULL){
        if(strcmp((p->PaketMakanJadi)->namaPaket,namaPaketX)==0){
            counter = counter + 1;
        }
        p = p->nextDJ;
    }
    return counter;
}
void cetakListDataPaketJadi(ListDatajadi LDPJ){

    if(LDPJ.firstDatajadi == NULL){
        printf("list kosong\n");
    }else{
        adrDatajadi p = LDPJ.firstDatajadi;
        adrDatajadi q = p->nextDJ;
        int i = 1;
        printf("\tLAPORAN PEMESANAN\n");
        printf("NO. NAMA PEMESAN\tALAMAT\tNOMOR TELP\n");
        if(q==NULL){
            printf("%d. %s\t\t%s\t%s\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                    (p->dataPemesanJadi)->nomorTelp);
        }else{
            while(q!=NULL){
                if(strcmp((p->dataPemesanJadi)->nomorTelp,(q->dataPemesanJadi)->nomorTelp)!=0){
                    printf("%d. %s\t\t%s\t%s\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorTelp);
                        i = i+1;
                }
                q = q->nextDJ;
                p = p->nextDJ;
            }
            printf("%d. %s\t\t%s\t%s\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorTelp);
        }
        printf("\n\n\nTOTAL HARGA = RP%d,00\n",hitungTotal(LDPJ));
        printf("PAKET YANG TERJUAL\n");
        printf("PAKET\tJUMLAH YANG TERJUAL\n");
        printf("PAKET 1 =\t%d\n",hitungPaket(LDPJ,"PAKET 1"));
        printf("PAKET 2 =\t%d\n",hitungPaket(LDPJ,"PAKET 2"));
        printf("PAKET 3 =\t%d\n",hitungPaket(LDPJ,"PAKET 3"));
        printf("PAKET 4 =\t%d\n",hitungPaket(LDPJ,"PAKET 4"));
        printf("PAKET 5 =\t%d\n",hitungPaket(LDPJ,"PAKET 5"));
        printf("PAKET 6 =\t%d\n",hitungPaket(LDPJ,"PAKET 6"));
        printf("PAKET 7 =\t%d\n",hitungPaket(LDPJ,"PAKET 7"));
        printf("PAKET 8 =\t%d\n",hitungPaket(LDPJ,"PAKET 8"));
        printf("PAKET 9 =\t%d\n",hitungPaket(LDPJ,"PAKET 9"));
    }
}


