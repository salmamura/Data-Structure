/*
 *KELAS CS 38-03
 *
 *NAMA: MUHAMMAD NAHLU ALVIN ALAMSYAH
 *NIM : 1302141018
 *
 *NAMA: VENIA RESTREVA DANESTIARA
 *NIM : 1302144093
 *
 *NAMA: ANJAR PRATIWI
 *NIM : 1302144188
 *
 *NB: masih terjadi stop working di prosedur searchJadwal, mungkin karena terdapat sedikit kesalahan pada paramater I/O nya
 */


#include "travelagi.h"

void buatListPesawat(listPesawat *LP)
{
    (*LP).first=NULL;
}
void buatListKota(listKota *LK)
{
    (*LK).first=NULL;
}
void buatListJadwal(listJadwal *LJ)
{
    (*LJ).first=NULL;
}
void buatListPemesan(listPemesan *LPM)
{
    (*LPM).first=NULL;
}

adrPesawat alokasiPesawat(char* namaX, char* kelasX)
{
    adrPesawat p=(adrPesawat)malloc(sizeof(p1));
    p->nama=namaX;
    p->kelas=kelasX;
    p->next=NULL;

    return p;
}
adrKota alokasiKota(char* namaX, char kodeX[3])
{
    adrKota p=(adrKota)malloc(sizeof(k1));
    p->nama=namaX;
    strcpy(p->kode,kodeX);
    p->next=NULL;

    return p;
}
adrJadwal alokasiJadwal(adrKota asalX, adrKota tujuanX, adrPesawat pesawatX, jam berangkatX, jam datangX, int hargaX)
{
    adrJadwal p=(adrJadwal)malloc(sizeof(j1));
    p->asal=asalX;
    p->tujuan=tujuanX;
    p->pesawat=pesawatX;
    p->berangkat=berangkatX;
    p->datang=datangX;
    p->harga=hargaX;
    p->next=NULL;

    return p;
}
adrPemesan alokasiPemesan(char* namaX, char* genderX, char* IDX)
{
    adrPemesan p=(adrPemesan)malloc(sizeof(pm1));
    p->nama=namaX;
    p->gender=genderX;
    p->ID=IDX;
    p->next=NULL;

    return p;
}

void insertPesawat(listPesawat *LP, adrPesawat p)
{
    adrPesawat t;
    if((*LP).first!=NULL){
        t=(*LP).first;
        while(t->next!=NULL)
            t=t->next;
        t->next=p;
    }
    else{
        p->next=(*LP).first;
        (*LP).first=p;
    }
}
void insertKota(listKota *LK, adrKota k)
{
    adrKota t;
    if((*LK).first!=NULL){
        t=(*LK).first;
        while(t->next!=NULL)
            t=t->next;
        t->next=k;
    }
    else{
        k->next=(*LK).first;
        (*LK).first=k;
    }
}
void insertJadwal(listJadwal *LJ, adrJadwal j)
{
    adrJadwal t;
    if((*LJ).first!=NULL){
        t=(*LJ).first;
        while(t->next!=NULL)
            t=t->next;
        t->next=j;
    }
    else{
        j->next=(*LJ).first;
        (*LJ).first=j;
    }
}
void insertPemesan(listPemesan *LPM, adrPemesan pm)
{
    adrPemesan t;
    if((*LPM).first!=NULL){
        t=(*LPM).first;
        while(t->next!=NULL)
            t=t->next;
        t->next=pm;
    }
    else{
        pm->next=(*LPM).first;
        (*LPM).first=pm;
    }
}

void isiDataProgram(listPesawat *LP, listKota *LK, listJadwal *LJ)
{
    buatListPesawat(&(*LP));
    buatListKota(&(*LK));
    buatListJadwal(&(*LJ));

    jam shift[14];
    int i;
    for(i=1;i<14;i++){
        shift[i].jj=i+5;
        if(i%2==0)
            shift[i].mm=30;
        else
            shift[i].mm=15;
    }

    adrPesawat psw[14];
    psw[0]=alokasiPesawat("Garuda_Indonesia","ekonomi");
    psw[1]=alokasiPesawat("Garuda_Indonesia","bisnis");
    psw[2]=alokasiPesawat("Lion_Air","ekonomi");
    psw[3]=alokasiPesawat("Lion_Air","bisnis");
    psw[4]=alokasiPesawat("Air_Asia","ekonomi");
    psw[5]=alokasiPesawat("Air_Asia","bisnis");
    psw[6]=alokasiPesawat("Batik_Air","bisnis");
    psw[7]=alokasiPesawat("Citilink","ekonomi");
    psw[8]=alokasiPesawat("Wings_Air","ekonomi");
    psw[9]=alokasiPesawat("Susi_Air","ekonomi");
    psw[10]=alokasiPesawat("Trigana_Air","ekonomi");
    psw[11]=alokasiPesawat("Trigana_Air","bisnis");
    psw[12]=alokasiPesawat("Sriwijaya_Air","ekonomi");
    psw[13]=alokasiPesawat("Sriwijaya_Air","bisnis");

    for(i=0;i<14;i++)
        insertPesawat(&(*LP),psw[i]);

    adrKota kota[10];
    kota[0]=alokasiKota("Medan","KNO");
    kota[1]=alokasiKota("Padang","PDG");
    kota[2]=alokasiKota("Jakarta","CGK");
    kota[3]=alokasiKota("Yogyakarta","JOG");
    kota[4]=alokasiKota("Surabaya","SUB");
    kota[5]=alokasiKota("Balikpapan","BPN");
    kota[6]=alokasiKota("Banjarmasin","BDJ");
    kota[7]=alokasiKota("Denpasar","DPS");
    kota[8]=alokasiKota("Mataram","LOP");
    kota[9]=alokasiKota("Makassar","UPG");

    for(i=0;i<10;i++)
        insertKota(&(*LK),kota[i]);

    adrJadwal rute[48];
    rute[0]=alokasiJadwal(kota[2],kota[0],psw[0],shift[2],shift[5],1487000);
    rute[1]=alokasiJadwal(kota[2],kota[4],psw[0],shift[3],shift[4],700000);
    rute[2]=alokasiJadwal(kota[2],kota[1],psw[0],shift[6],shift[8],551000);
    rute[3]=alokasiJadwal(kota[2],kota[3],psw[1],shift[2],shift[3],992000);
    rute[4]=alokasiJadwal(kota[3],kota[4],psw[1],shift[9],shift[10],831000);
    rute[5]=alokasiJadwal(kota[2],kota[3],psw[2],shift[1],shift[2],421000);
    rute[6]=alokasiJadwal(kota[4],kota[7],psw[2],shift[5],shift[6],432000);
    rute[7]=alokasiJadwal(kota[7],kota[8],psw[2],shift[10],shift[11],351000);
    rute[8]=alokasiJadwal(kota[2],kota[0],psw[3],shift[11],shift[13],933000);
    rute[9]=alokasiJadwal(kota[5],kota[9],psw[3],shift[5],shift[8],892000);
    rute[10]=alokasiJadwal(kota[9],kota[8],psw[3],shift[7],shift[9],1105000);
    rute[11]=alokasiJadwal(kota[5],kota[6],psw[4],shift[2],shift[3],498000);
    rute[12]=alokasiJadwal(kota[6],kota[8],psw[4],shift[4],shift[5],715000);
    rute[13]=alokasiJadwal(kota[4],kota[8],psw[4],shift[3],shift[8],650000);
    rute[14]=alokasiJadwal(kota[2],kota[6],psw[5],shift[8],shift[12],1358000);
    rute[15]=alokasiJadwal(kota[4],kota[5],psw[5],shift[4],shift[7],1025000);
    rute[16]=alokasiJadwal(kota[0],kota[1],psw[6],shift[11],shift[13],784000);
    rute[17]=alokasiJadwal(kota[5],kota[6],psw[6],shift[6],shift[8],719000);
    rute[18]=alokasiJadwal(kota[3],kota[2],psw[6],shift[4],shift[5],795000);
    rute[19]=alokasiJadwal(kota[2],kota[0],psw[6],shift[5],shift[9],987000);
    rute[20]=alokasiJadwal(kota[2],kota[4],psw[7],shift[2],shift[3],584000);
    rute[21]=alokasiJadwal(kota[2],kota[6],psw[7],shift[3],shift[6],692000);
    rute[22]=alokasiJadwal(kota[2],kota[3],psw[7],shift[7],shift[9],681000);
    rute[23]=alokasiJadwal(kota[7],kota[3],psw[7],shift[3],shift[4],511000);
    rute[24]=alokasiJadwal(kota[4],kota[3],psw[8],shift[4],shift[5],486000);
    rute[25]=alokasiJadwal(kota[2],kota[1],psw[8],shift[6],shift[8],620000);
    rute[26]=alokasiJadwal(kota[8],kota[9],psw[8],shift[2],shift[5],721000);
    rute[27]=alokasiJadwal(kota[9],kota[6],psw[8],shift[8],shift[10],571000);
    rute[28]=alokasiJadwal(kota[2],kota[3],psw[9],shift[2],shift[3],557000);
    rute[29]=alokasiJadwal(kota[3],kota[4],psw[9],shift[3],shift[4],656000);
    rute[30]=alokasiJadwal(kota[9],kota[5],psw[9],shift[6],shift[8],700000);
    rute[31]=alokasiJadwal(kota[6],kota[1],psw[9],shift[9],shift[12],821000);
    rute[32]=alokasiJadwal(kota[2],kota[3],psw[10],shift[1],shift[2],700000);
    rute[33]=alokasiJadwal(kota[2],kota[4],psw[10],shift[7],shift[8],876000);
    rute[34]=alokasiJadwal(kota[9],kota[6],psw[10],shift[9],shift[12],700000);
    rute[35]=alokasiJadwal(kota[8],kota[5],psw[10],shift[8],shift[9],899000);
    rute[36]=alokasiJadwal(kota[1],kota[2],psw[11],shift[2],shift[4],1050000);
    rute[37]=alokasiJadwal(kota[0],kota[9],psw[11],shift[1],shift[4],1667000);
    rute[38]=alokasiJadwal(kota[0],kota[2],psw[11],shift[6],shift[9],1557000);
    rute[39]=alokasiJadwal(kota[8],kota[4],psw[11],shift[4],shift[6],850000);
    rute[40]=alokasiJadwal(kota[7],kota[8],psw[12],shift[4],shift[5],680000);
    rute[41]=alokasiJadwal(kota[5],kota[7],psw[12],shift[8],shift[10],1058000);
    rute[42]=alokasiJadwal(kota[6],kota[0],psw[12],shift[6],shift[9],884000);
    rute[43]=alokasiJadwal(kota[0],kota[4],psw[12],shift[3],shift[7],1300000);
    rute[44]=alokasiJadwal(kota[1],kota[0],psw[13],shift[8],shift[9],757000);
    rute[45]=alokasiJadwal(kota[7],kota[9],psw[13],shift[4],shift[7],954000);
    rute[46]=alokasiJadwal(kota[3],kota[4],psw[13],shift[1],shift[2],899000);
    rute[47]=alokasiJadwal(kota[8],kota[4],psw[13],shift[2],shift[3],794000);

    for(i=0;i<48;i++)
        insertJadwal(&(*LJ),rute[i]);
}

adrKota searchKota(listKota LK, char kodeX[3])
{
    adrKota p=LK.first;
    while(p!=NULL){
        if(strcmp(p->kode,kodeX)==0)
            break;
        else
            p=p->next;
    }
    return p;
}
void searchJadwal(data *tiket[], listJadwal LJ, adrKota asalX, adrKota tujuanX, int *n)
{
    adrJadwal p=LJ.first;
    int i=0; //*n=0;
    while(p!=NULL){
        if(p->asal==asalX&&p->tujuan==tujuanX){
            (*tiket[i]).asal=p->asal->nama;
            printf("yee");
            (*tiket[i]).tujuan=p->tujuan->nama;
            (*tiket[i]).pesawat=p->pesawat->nama;
            (*tiket[i]).kelas=p->pesawat->kelas;
            (*tiket[i]).berangkat=p->berangkat;
            (*tiket[i]).datang=p->datang;
            (*tiket[i]).harga=p->harga;

            i++;
        }
        p=p->next;
    }
    *n=i;
}

void lihatListKota(listKota LK)
{
    system("cls");
    adrKota p=LK.first;
    printf("===================================\n"
           "          TRAVELAGI.COM\n"
           "   Pesan Tiket Jadi Lebih Mudah\n"
           "===================================\n"
           "\nKOTA\t\t\tKODE KOTA\n"
           "------------------------------------\n");
    while(p!=NULL){
        printf("%s\t\t\t%s\n",p->nama,p->kode);
        p=p->next;
    }
    printf("------------------------------------\n");
}

void lihatListPesawat(listPesawat LP)
{
    system("cls");
    adrPesawat p=LP.first;
    printf("===================================\n"
           "          TRAVELAGI.COM\n"
           "   Pesan Tiket Jadi Lebih Mudah\n"
           "===================================\n"
           "\nPESAWAT\t\t\tKELAS\n"
           "------------------------------------\n");
    while(p!=NULL){
        printf("%s\t\t%s\n",p->nama,p->kelas);
        p=p->next;
    }
    printf("------------------------------------\n");
    system("pause");
}
void lihatJadwal(listJadwal LJ, listKota LK)
{
    system("cls");
    lihatListKota(LK);

    char kodeAsal[3];
    char kodeTujuan[3];

    printf("input kode kota asal: "); scanf("%s",&kodeAsal);
    adrKota asal=searchKota(LK,kodeAsal);
    printf("input kode kota tujuan: "); scanf("%s",&kodeTujuan);
    adrKota tujuan=searchKota(LK,kodeTujuan);

    printf("asal: %p\ntujuan: %p\n",asal,tujuan);
    data tiket[48];
    int i,n;
    searchJadwal(&tiket,LJ,asal,tujuan,&n);

    printf("ASAL\tTUJUAN\tMASKAPAI\tKELAS\tBERANGKAT\tTIBA\tHARGA\n"
           "---------------------------------------------------------------------------------------\n");
    for(i=0;i<=n;i++){
        printf("%s\t%s\t%s\t%s\t%2.i:%i\t%i2.:%i\t%i IDR\n",tiket[i].asal,tiket[i].tujuan,tiket[i].pesawat,tiket[i].kelas,tiket[i].berangkat.jj,tiket[i].berangkat.mm,tiket[i].datang.jj,tiket[i].datang.mm,tiket[i].harga);
        printf("---------------------------------------------------------------------------------------\n");
    }

    system("pause");
}
void pesanTiket(listJadwal LJ, listKota LK)
{
    system("cls");
    lihatListKota(LK);

    char kodeAsal[3];
    char kodeTujuan[3];
    printf("input kode kota asal: "); scanf("%s",&kodeAsal);
    adrKota asal=searchKota(LK,kodeAsal);
    printf("input kode kota tujuan: "); scanf("%s",&kodeTujuan);
    adrKota tujuan=searchKota(LK,kodeTujuan);
    data tiket[48];
    int i,n;
    searchJadwal(&tiket,LJ,asal,tujuan,&n);

    printf("NO.\tASAL\tTUJUAN\tMASKAPAI\tKELAS\tBERANGKAT\tTIBA\tHARGA\n"
           "---------------------------------------------------------------------------------------\n");
    for(i=0;i<=n;i++){
        printf("%s\t%s\t%s\t%s%2.i:%i\t%i2.:%i\t%i IDR\n",tiket[i].asal,tiket[i].tujuan,tiket[i].pesawat,tiket[i].kelas,tiket[i].berangkat.jj,tiket[i].berangkat.mm,tiket[i].datang.jj,tiket[i].datang.mm,tiket[i].harga);
        printf("---------------------------------------------------------------------------------------\n");
    }

    int t; char j;
    pilihTiket:
        printf("\nTiket yang dipesan (nomor): "); scanf("%i",&t);
        printf("Asal: %s\n"
               "Tujuan: %s\n"
               "Maskapai: %s\n"
               "Kelas: %s\n"
               "Berangkat: %2.i:%i\n"
               "Tiba: %2.i:%i\n"
               "Harga: %i IDR\n"
               ,tiket[t].asal,tiket[t].tujuan,tiket[t].pesawat,tiket[t].kelas,tiket[t].berangkat.jj,tiket[t].berangkat.mm,tiket[t].datang.jj,tiket[t].datang.mm,tiket[t].harga);
        printf("Anda yakin (y/t)? "); scanf("%c",&j);
        if(j=='t')
            goto pilihTiket;

    listPemesan LPM;
    buatListPemesan(&LPM);
    adrPemesan p;

    printf("\nInput jumlah penumpang: "); scanf("%i",&n);
    char* nama; char* gender; char* ID;
    for(i=1;i<=n;i++){
        printf("Penumpang %i\n",i);
        printf("Nama: "); scanf("%s",&nama);
        printf("Gender (pria/wanita): "); scanf("%s",&gender);
        printf("ID: "); scanf("%s",&ID);
        printf("-------------------------------------------\n");
        p=alokasiPemesan(nama,gender,ID);
        insertPemesan(&LPM,p);
    }
    printf("Total harga: %i IDR\n",tiket[t].harga*n);
    system("pause");

    cetakTiket(tiket[t],n,LPM);

    printf("Pemesanan Tiket berhasil!\n");
    system("pause");
}
void cetakTiket(data tiketX, int jumlahTiket, listPemesan LPM)
{
    FILE* f=fopen("tiket.txt","w");

    fprintf(f,"%s\n"
            "--------------\n",tiketX.pesawat);
    fprintf(f,"Asal/Origin: %s\n"
            "Tujuan/Destination: %s\n"
            "Kelas/Class: %s\n"
            "Berangkat/Depart: %2.i:%i\n"
            "Tiba/Arrive: %2.i:%i\n"
            "Penumpang/Passenger(s):\n"
            "---------------------------------------------\n"
            ,tiketX.asal,tiketX.tujuan,tiketX.kelas,tiketX.berangkat.jj,tiketX.berangkat.mm,tiketX.datang.jj,tiketX.datang.mm,jumlahTiket);

    adrPemesan p=LPM.first;
    while(p!=NULL){
        fprintf(f,"%s\t%s\t%s\n"
                "---------------------------------------------\n"
                ,p->nama,p->gender,p->ID);
        p=p->next;
    }

    fprintf(f,"Total harga/Total price: %i IDR\n",tiketX.harga*jumlahTiket);

    fclose(f);
}
void beritaAngkasa();
