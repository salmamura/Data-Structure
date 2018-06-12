#include <stdio.h>
#include "header.h"

boolean inputLagi(char pilih){
    if(pilih == 'Y'||pilih == 'y'){
        return true;
    }else{
        return false;
    }
}
void dealokasi(adrDP p){
    free(p);
}
void dealokasiMeja(adrMe p){
    free(p);
}
void createListData(ListData *LD){
    LD->firstData = NULL;
} //create list kosong
void createListMeja(lMeja *LMe){
    (*LMe).firstMe=NULL;
}
adrData alokasiData(char* namaX,char* alamatX,char* noMejaX){

    adrData p=(adrData)malloc(sizeof(data1));
    if(p!=NULL){
        p->nama = namaX;
        p->alamat = alamatX;
        p->nomorMeja = noMejaX;
        p->nextData = NULL;
    }
    return p;
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

adrData searchData(ListData LD, char* noMeja){

    adrData p = LD.firstData;

    while(p!=NULL){
        if(strcmp(p->nomorMeja,noMeja)==0){
            return p;
        }
        p = p->nextData;
    }
    return p;
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
void createListMenu(ListMenu *LP){
    LP->firstMenu = NULL;
} //create list kosong
adrMenu alokasiMenu(int namaMenuX, char makanan1X[30],int hargaX){

    adrMenu p = (adrMenu)malloc(sizeof(Menu1));

    if(p!=NULL){
        p->namaMenu = namaMenuX;
        p->makanan1 = makanan1X;
        p->harga = hargaX;
        p->nextMenu = NULL;
    }
    return p;
}
void insertMenu(ListMenu *LP, adrMenu md){
    adrMenu p = LP->firstMenu;

    if(LP->firstMenu==NULL){
        LP->firstMenu = md;
    }else{
        md->nextMenu = p->nextMenu;
        p->nextMenu = md;
    }
}
void cetakListMenu(ListMenu LP){

    adrMenu p = LP.firstMenu;

    while(p!=NULL){
        printf("%s  : %s \tRP.%d,00\n",p->namaMenu,p->makanan1,p->harga);
        p = p->nextMenu;
    }
}
adrMenu searchMenu(ListMenu LMK, char* namaMenuX){

    adrMenu p = LMK.firstMenu;

    while(p!=NULL){
        if(strcmp(p->namaMenu,namaMenuX)==0){
            return p;
        }
        p = p->nextMenu;
    }
    return p;
}
boolean searchMenubool(ListMenu LMK, char* namaMenuX){

    adrMenu p = LMK.firstMenu;

    while(p!=NULL){
        if(strcmp(p->namaMenu,namaMenuX)==0){
            return true;
        }
        p = p->nextMenu;
    }
    return false;

}
void insertDataMenu(ListDP *LDP, adrDP md){

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

void createListDataMenu(ListDP *LDP){
    LDP->firstDP = NULL;
} //create list kosong
adrDP alokasiDataMenu(ListData LD,ListMenu LP,char* noMeja,char namaMenuX[10]){

    adrDP p = (adrDP)malloc(sizeof(dp1));
    if(p!=NULL){
        p->dataPemesan= searchData(LD,noMeja);
        p->MenuMakan = searchMenu(LP,namaMenuX);
        p->nextDP = NULL;
    }
    return p;
}
void cetakListDataMenu(ListDP LDP){
    adrDP p;
    int j=1;
    FILE *pesan;
    time_t waktu;
    waktu=time(NULL);
    pesan=fopen("Pemesanan.txt","w+");
    if(LDP.firstDP == NULL){
        printf("List kosong\n");
        fprintf(pesan,"List kosong\n");
    }else{
        p = LDP.firstDP;
        printf("|\t\t\t\tTABEL DATA PEMESAN\t\t\t    |\n");
        fprintf(pesan,"\tTABEL DATA PEMESAN\n\n");
        //fprintf(pesan,"NO.\tNAMA PEMESAN\t  ALAMAT\t\t  NOMOR MEJA\t   Menu\n");
        printf("|---------------------------------------------------------------------------|\n");
        printf("| No |\tNama pemesan\t|\tNo meja\t|\tNo menu\t|\n");
        while(p != NULL){
           // printf("%d\t %s\t\t %s\t\t %s\t\t %s\n",j,(p->dataPemesan)->nama,(p->dataPemesan)->alamat,(p->dataPemesan)->nomorMeja
                   //,(p->MenuMakan)->namaMenu);
            //fprintf(pesan,"%d\t %s\t\t %s\t\t %s\t\t %s\n",j,(p->dataPemesan)->nama,(p->dataPemesan)->alamat,(p->dataPemesan)->nomorMeja
                   //,(p->MenuMakan)->namaMenu);
            printf("| %d  ",j);
            printf("|\t%s\t|\t%s\t|\t%s\t|",(p->dataPemesan)->nama,(p->dataPemesan)->nomorMeja,(p->MenuMakan)->namaMenu);
            printf("\n     | Waktu pesan : ");printf("%s",ctime(&waktu));
            fprintf(pesan,"No transaksi   = %d\n",j);
            fprintf(pesan,"Waktu pesan    = ");fprintf(pesan,(ctime(&waktu)));
            fprintf(pesan,"Nama pemesan   = %s\n",(p->dataPemesan)->nama);
            fprintf(pesan,"Nomor meja     = %s\n",(p->dataPemesan)->nomorMeja);
            fprintf(pesan,"Nomor menu     = %s\n",(p->MenuMakan)->namaMenu);
            fprintf(pesan,"=========================================\n");
            j = j+1;
            p = p->nextDP;
        }
        printf("\n|---------------------------------------------------------------------------|\n");
    }
    fclose(pesan);
}
void deleteDP(ListDP *LDP,char* noMeja){
    adrDP p = LDP->firstDP;
    adrDP q = LDP->firstDP;
    if(p->nextDP == NULL){
        LDP->firstDP = NULL;
        dealokasi(p);
    }else{
        while(p!=NULL){
            if(strcmp((p->dataPemesan)->nomorMeja,noMeja)==0){
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
boolean searchDP(ListDP LDP,char* noMeja){

    adrDP p = LDP.firstDP;
    while(p!=NULL){
        if(strcmp((p->dataPemesan)->nomorMeja,noMeja)==0){
            return true;
        }
        p = p->nextDP;
    }
    return false;
}
adrDP searchDPadr(ListDP LDP,char* noMeja){
    adrDP p = LDP.firstDP;
    while(p!=NULL){
        if(strcmp((p->dataPemesan)->nomorMeja,noMeja)==0){
            return p;
        }
        p = p->nextDP;
    }
    return p;
}


void createListDataBatal(ListDatabatal *LDPB){
    LDPB->firstDatabatal = NULL;
}

void cetakListDataBatal(ListDatabatal LDPB){

    if(LDPB.firstDatabatal == NULL){
        printf("List kosong\n");
    }else{
        adrDatabatal p = LDPB.firstDatabatal;
        int j=1;
        printf("\tDATA-DATA PEMESAN YANG BATAL\n");
        printf("NO. NAMA PEMESAN\tALAMAT\t\tNOMOR Meja\n");
        while(p!=NULL){
            printf("%d %s\t\t%s\t\t%s\n",j,p->namaBatal,p->alamatBatal,
                    p->nomorMejaBatal);
            j = j + 1;
            p = p->nextDatabatal;
        }
    }
}
void createListDataMenuJadi(ListDatajadi *LDPJ){
    LDPJ->firstDatajadi = NULL;
} //create list kosong
adrDatajadi alokasiDataMenuJadi(adrDP q){

    adrDatajadi p = (adrDatajadi)malloc(sizeof(data3));

    if(p!=NULL){
        p->dataPemesanJadi = q->dataPemesan;
        p->MenuMakanJadi = q->MenuMakan;
        p->nextDJ = NULL;
    }
    return p;
}
void insertDataMenuJadi(ListDatajadi *LDPJ, adrDatajadi md){

    if(LDPJ->firstDatajadi == NULL){
        LDPJ->firstDatajadi = md;
    }else{
        adrDatajadi p = LDPJ->firstDatajadi;
        while(strcmp((p->dataPemesanJadi)->nomorMeja,(md->dataPemesanJadi)->nomorMeja)!=0 && p->nextDJ!=NULL){
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
        total = total + (p->MenuMakanJadi)->harga;
        p = p->nextDJ;
    }
    return total;
}
void cetakListDataMenuJadi(ListDatajadi LDPJ){

    if(LDPJ.firstDatajadi == NULL){
        printf("list kosong\n");
    }else{
        adrDatajadi p = LDPJ.firstDatajadi;
        adrDatajadi q = p->nextDJ;
        int i = 1;
        printf("\tLAPORAN PENJUALAN\n");
        printf("NO. NAMA PEMESAN\tALAMAT\tNOMOR Meja\n");
        if(q==NULL){
            printf("%d. %s\t\t%s\t%s\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                    (p->dataPemesanJadi)->nomorMeja);
        }else{
            while(q!=NULL){
                if(strcmp((p->dataPemesanJadi)->nomorMeja,(q->dataPemesanJadi)->nomorMeja)!=0){
                    printf("%d. %s\t\t%s\t%s\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorMeja);
                        i = i+1;
                }
                q = q->nextDJ;
                p = p->nextDJ;
            }
            printf("%d. %s\t\t%s\t%s\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorMeja);
        }
        printf("\n\n\nTOTAL HARGA = RP%d,00\n",hitungTotal(LDPJ));
    }
}


