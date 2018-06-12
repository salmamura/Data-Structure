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
void createListData(ListData *LD){
    LD->firstData = NULL;
} //create list kosong
adrData alokasiData(char* namaX,char* alamatX,int noMejaX){

    adrData p=(adrData)malloc(sizeof(data1));
    if(p!=NULL){
        p->nama = namaX;
        p->alamat = alamatX;
        p->nomorMeja = noMejaX;
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

adrData searchData(ListData LD, int noMeja){

    adrData p = LD.firstData;

    while(p!=NULL){
        if(p->nomorMeja == noMeja){
            return p;
        }
        p = p->nextData;
    }
    return p;
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
adrDP alokasiDataMenu(ListData LD,ListMenu LP,int noMeja,char namaMenuX[10]){

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
    pesan=fopen("Pemesanan.txt","a+");
    if(LDP.firstDP == NULL){
        printf("List kosong\n");
        fprintf(pesan,"List kosong\n");
    }else{
        p = LDP.firstDP;
        printf("|\t\t\t\tTABEL DATA PEMESAN\t\t\t    |\n");
        printf("|---------------------------------------------------------------------------|\n");
        printf("| No |\tNama pemesan\t|\tNo meja\t|\tNo menu\t|\n");
        fprintf(pesan,"|\t\t\t\tTABEL DATA PEMESAN\t\t\t    |\n");
        fprintf(pesan,"|---------------------------------------------------------------------------|\n");
        fprintf(pesan,"| No |\tNama pemesan\t|\tNo meja\t|\tNo menu\t|\n");
        while(p != NULL){
            printf("| %d  ",j);
            printf("|\t%s\t|\t%d\t|\t%s\t|\n",(p->dataPemesan)->nama,(p->dataPemesan)->nomorMeja,(p->MenuMakan)->namaMenu);
            fprintf(pesan,"| %d  ",j);
            fprintf(pesan,"|\t%s\t|\t%d\t|\t%s\t|\n",(p->dataPemesan)->nama,(p->dataPemesan)->nomorMeja,(p->MenuMakan)->namaMenu);
            j = j+1;
            p = p->nextDP;
        }
        printf("\n|---------------------------------------------------------------------------|\n");
        fprintf(pesan,"\n|---------------------------------------------------------------------------|\n");
    }
    fclose(pesan);
}
void deleteDP(ListDP *LDP,int noMeja){
    adrDP p = LDP->firstDP;
    adrDP q = LDP->firstDP;
    if(p->nextDP == NULL){
        LDP->firstDP = NULL;
        dealokasi(p);
    }else{
        while(p!=NULL){
            if((p->dataPemesan)->nomorMeja == noMeja){
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
boolean searchDP(ListDP LDP,int noMeja){

    adrDP p = LDP.firstDP;
    while(p!=NULL){
        if((p->dataPemesan)->nomorMeja == noMeja){
            return true;
        }
        p = p->nextDP;
    }
    return false;
}
adrDP searchDPadr(ListDP LDP,int noMeja){
    adrDP p = LDP.firstDP;
    while(p!=NULL){
        if((p->dataPemesan)->nomorMeja == noMeja){
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
            printf("%d %s\t\t%s\t\t%d\n",j,p->namaBatal,p->alamatBatal,
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
        while((p->dataPemesanJadi)->nomorMeja!=(md->dataPemesanJadi)->nomorMeja && p->nextDJ!=NULL){
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
int hitungMenu(ListDatajadi LDPJ,char* namaMenuX){

    adrDatajadi p = LDPJ.firstDatajadi;
    int counter = 0;

    while(p!=NULL){
        if(strcmp((p->MenuMakanJadi)->namaMenu,namaMenuX)==0){
            counter = counter + 1;
        }
        p = p->nextDJ;
    }
    return counter;
}

void cetakListDataMenuJadi(ListDatajadi LDPJ){
    FILE *bayar;
    bayar=fopen("Pemesanan.txt","a+");
    if(LDPJ.firstDatajadi == NULL){
        printf("list kosong\n");
    }else{
        adrDatajadi p = LDPJ.firstDatajadi;
        adrDatajadi q = p->nextDJ;
        int i = 1;
        printf("\tLAPORAN PENJUALAN\n");
        printf("NO. NAMA PEMESAN\tALAMAT\t\tNOMOR Meja\n");
        fprintf(bayar,"\tLAPORAN PENJUALAN\n");
        fprintf(bayar,"NO. NAMA PEMESAN\tALAMAT\t\tNOMOR Meja\n");
        if(q==NULL){
            printf("%d. %s\t\t%s\t\t%d\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                    (p->dataPemesanJadi)->nomorMeja);
            fprintf(bayar,"%d. %s\t\t%s\t\t%d\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                    (p->dataPemesanJadi)->nomorMeja);
        }else{
            while(q!=NULL){
                if((p->dataPemesanJadi)->nomorMeja != (q->dataPemesanJadi)->nomorMeja){
                    printf("%d. %s\t\t%s\t\t\t%d\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorMeja);
                    fprintf(bayar,"%d. %s\t\t%s\t\t\t%d\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorMeja);
                        i = i+1;
                }
                q = q->nextDJ;
                p = p->nextDJ;
            }
            printf("%d. %s\t\t%s\t\t\t%d\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorMeja);
            fprintf(bayar,"%d. %s\t\t%s\t\t\t%d\n",i,(p->dataPemesanJadi)->nama,(p->dataPemesanJadi)->alamat,
                        (p->dataPemesanJadi)->nomorMeja);
        }
        printf("\n\n\nTOTAL HARGA = RP%d,00\n",hitungTotal(LDPJ));
        printf("\n\nMENU\tJUMLAH YANG TERJUAL\n");
        printf("\t 1 =\t%d\n",hitungMenu(LDPJ,"1"));
        printf("\t 2 =\t%d\n",hitungMenu(LDPJ,"2"));
        printf("\t 3 =\t%d\n",hitungMenu(LDPJ,"3"));
        printf("\t 4 =\t%d\n",hitungMenu(LDPJ,"4"));
        printf("\t 5 =\t%d\n",hitungMenu(LDPJ,"5"));
        printf("\t 6 =\t%d\n",hitungMenu(LDPJ,"6"));
        printf("\t 7 =\t%d\n",hitungMenu(LDPJ,"7"));

        fprintf(bayar,"\n\n\nTOTAL HARGA = RP%d,00\n",hitungTotal(LDPJ));
        fprintf(bayar,"\n\nMENU\tJUMLAH YANG TERJUAL\n");
        fprintf(bayar,"\t 1 =\t%d\n",hitungMenu(LDPJ,"1"));
        fprintf(bayar,"\t 2 =\t%d\n",hitungMenu(LDPJ,"2"));
        fprintf(bayar,"\t 3 =\t%d\n",hitungMenu(LDPJ,"3"));
        fprintf(bayar,"\t 4 =\t%d\n",hitungMenu(LDPJ,"4"));
        fprintf(bayar,"\t 5 =\t%d\n",hitungMenu(LDPJ,"5"));
        fprintf(bayar,"\t 6 =\t%d\n",hitungMenu(LDPJ,"6"));
        fprintf(bayar,"\t 7 =\t%d\n",hitungMenu(LDPJ,"7"));
    }
    fclose(bayar);
}

void createListMeja(ListMeja *LD){
    LD->firstMeja = NULL;
} //create list kosong
adrMeja alokasiMeja(int noMejaX,boolean statusX){

    adrMeja p = (adrMeja)malloc(sizeof(Meja));

    if(p!=NULL){
        p->noMeja = noMejaX;
        p->status = statusX;
        p->next = NULL;
    }
    return p;
}
void insertLastMeja(ListMeja *LD, adrMeja d){

    if(LD->firstMeja == NULL){
        LD->firstMeja = d;
    }else{
        adrMeja p =LD->firstMeja;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = d;
    }
}
adrMeja searchMeja(ListMeja LD, int mejaX){

    adrMeja p = LD.firstMeja;

    while(p!=NULL){
        if(mejaX == p->noMeja){
            return p;
        }
        p = p->next;
    }
    return 0;
}
void cetakListMeja(ListMeja LDP){

    adrMeja p = LDP.firstMeja;

    while(p!=NULL){
        if(p->status == false){
            printf("\tmeja %d = kosong\n",p->noMeja);
        }else{
            printf("\tmeja %d = isi\n",p->noMeja);
        }
        p = p->next;
    }
}

void ubahStatus(ListMeja *LDP, int nomor){

    adrMeja p = LDP->firstMeja;

    while(p!=NULL){
        if(p->noMeja == nomor){
            if(p->status == true){
                p->status = false;
            }else{
                p->status = true;
            }
        }
        p = p->next;
    }
}


