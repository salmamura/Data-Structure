#include <stdio.h>
#include "body.c"
#include "string.h"

int main()
{
    int pilihMenu;
    int pilihan;
    int size = 1000,i=1;
    char pilih = 'Y';
    char cariTelp[100];
    char namaX[size][100];
    char namaPaketX[10];
    char alamatX[size][100];
    char nomorTelpX[size][100];
    ListPaket lmkd;
    createListPaket(&lmkd);
    ListData ld;
    createListData(&ld);
    ListDP ldp;
    createListDataPaket(&ldp);
    ListDatabatal ldpb;
    createListDataBatal(&ldpb);
    ListDatajadi ldpj;
    createListDataPaketJadi(&ldpj);

    adrPaket pmk0 = alokasiPaket("PAKET 2","Nasi Goreng","Telur Mata Sapi","Air mineral",
                                "irisan baso & sosis","irisan timun + kerupuk",15000);
    adrPaket pmk1 = alokasiPaket("PAKET 3","Teh_panas","Nasi Goreng",
                                "Telur Mata Sapi","Ayam Goreng","irisan timun + kerupuk",30000);
    adrPaket pmk2 = alokasiPaket("PAKET 4","Nasi Kuning","Telur Dadar","Sambel kacang",
                                "irisan timun + kerupuk","Teh panas",13000);
    adrPaket pmk3 = alokasiPaket("PAKET 5","Nasi Uduk","Telur Rendang","Perkedel Kentang",
                                "irisan timun + kerupuk","Air mineral",15000);
    adrPaket pmk4 = alokasiPaket("PAKET 6","Nasi Kuning","Telur Dadar","Perkedel Kentang",
                                "Ayam Goreng","Air mineral",13000);
    adrPaket pmk5 = alokasiPaket("PAKET 7","Nasi Liwet Special","Ayam","Perkedel Kentang,tahu,&tempe",
                                "Air mineral","Teri Medan",34000);
    adrPaket pmk6 = alokasiPaket("PAKET 8","Nasi Liwet Special","Gepuk","Perkedel Kentang",
                                "Air mineral","Ikan Asin",28000);
    adrPaket pmk7 = alokasiPaket("PAKET 9","Nasi Putih","Ayam","Perkedel Jagung","Ikan Asin",
                                "Sayur Lodeh + Air Mineral",32000);
    adrPaket pmk8 = alokasiPaket("PAKET 1","Nasi Putih","Ayam","Perkedel Jagung","Soto Bandung",
                                "Air Mineral",36000);
    insertPaket(&lmkd,pmk8);
    insertPaket(&lmkd,pmk7);
    insertPaket(&lmkd,pmk6);
    insertPaket(&lmkd,pmk5);
    insertPaket(&lmkd,pmk4);
    insertPaket(&lmkd,pmk3);
    insertPaket(&lmkd,pmk2);
    insertPaket(&lmkd,pmk1);
    insertPaket(&lmkd,pmk0);

    while(true){
        printf(" MENU PROGRAM \n");
        printf("\t1.MENU MAKANAN\n");
        printf("\t2.INPUT DATA PEMESAN\n");
        printf("\t3.DATA - DATA PEMESAN\n");
        printf("\t4.KONFIRMASI PEMESANAN\n");
        printf("\t5.ARSIP-ARSIP\n");
        printf("\t6.EXIT\n");
        printf("PILIH NO : ");scanf("%d",&pilihMenu);
        if(pilihMenu == 1){
            system("cls");
            cetakListPaket(lmkd);
            getch();
        }else if(pilihMenu == 2){
            pilih = 'Y';
            while(inputLagi(pilih)){
                system("cls");
                printf("masukkan nama = ");gets(namaX[i]);gets(namaX[i]);//scanf("%s",&namaX);
                printf("masukkan alamat = ");gets(alamatX[i]);//scanf("%s",&alamatX);
                printf("masukkan nomor telepon = ");gets(nomorTelpX[i]);
                insertLastData(&ld,alokasiData(namaX[i],alamatX[i],nomorTelpX[i]));
                while(inputLagi(pilih)){
                    gets(namaPaketX);
                    printf("masukkan paket = ");gets(namaPaketX);
                    if(searchPaketbool(lmkd,namaPaketX)){
                        insertDataPaket(&ldp,alokasiDataPaket(ld,lmkd,nomorTelpX[i],namaPaketX));
                        printf("Input Paket lagi (Y/N)? ");scanf("%s",&pilih);
                    }else{
                        printf("hanya terdapat paket 1-9, silahkan input lagi\n");
                        break;
                    }
                }
                printf("Input data pemesan lagi (Y/N)? ");scanf("%s",&pilih);
                i = i + 1;
            }
        }else if(pilihMenu == 3){
            system("cls");
            printf("1. LIHAT PESANAN\n");
            printf("2. EDIT PESANAN\n");
            printf("3. MENU UTAMA\n");
            printf("PILIH NO : ");scanf("%d",&pilihan);
            if(pilihan == 1){
                system("cls");
                cetakListDataPaket(ldp);
                getch();
            }else if(pilihan == 2){
                system("cls");
                printf("1. TAMBAH PAKET\n");
                printf("2. PEMBATALAN PAKET\n");
                printf("3. PEMBATALAN PESANAN \n");
                printf("4. KEMBALI KE MENU UTAMA\n");
                printf("PILIH NO : ");scanf("%d",&pilihan);
                char cariPaket[10];
                if(pilihan == 1){
                    pilih = 'Y';
                    printf("masukkan no telepon pemesan = ");scanf("%s",&cariTelp);
                    if(searchDataBool(ld,cariTelp)){
                        insertAfterData(&ld,alokasiDataAlamat(searchData(ld,cariTelp)));
                        while(inputLagi(pilih)){
                            printf("masukkan paket = ");gets(namaPaketX);gets(namaPaketX);
                            if(searchPaketbool(lmkd,namaPaketX)){
                                insertAfterDataPaket(&ldp,alokasiDataPaket(ld,lmkd,cariTelp,namaPaketX));
                                printf("Input Paket lagi (Y/N)? ");scanf("%s",&pilih);
                            }else{
                                printf("hanya terdapat paket 1-9, silahkan input lagi\n");
                                break;
                            }
                        }
                    }else{
                        printf("nomor telepon tidak terdaftar\n");
                        getch();
                    }
                }else if(pilihan == 2){
                    printf("masukkan no telepon pemesan = ");gets(cariTelp);gets(cariTelp);
                    if(searchDataBool(ld,cariTelp)){
                        printf("masukkan paket yang ingin di batalkan = ");gets(cariPaket);
                        if(searchPaketbool(lmkd,namaPaketX)){
                            if(cekPaket(ldp)){
                                deleteDPPaket(&ldp,cariTelp,cariPaket);
                                printf("penghapusan paket berhasil\n");
                            }else{
                                printf("pemesan hanya memesan 1 paket\n");
                            }
                        }else{
                            printf("hanya terdapat paket 1-9, silahkan input lagi\n");
                            break;
                        }
                    }else{
                        printf("nomor telepon tidak terdaftar\n");
                    }
                    getch();
                }else if(pilihan == 3){
                    printf("masukkan no telepon pemesan yang ingin dibatalkan = ");scanf("%s",&cariTelp);
                    if(searchDP(ldp,cariTelp)){
                        while(searchDP(ldp,cariTelp)){
                            deleteDP(&ldp,cariTelp);
                        }
                        printf("pembatalan pemesanan berhasil\n");
                        insertDatabatal(&ldpb,alokasiDataBatal(searchData(ld,cariTelp)));
                    }else{
                       printf("nomor telepon tidak terdaftar\n");
                    }
                    getch();
                }
            }
            system("cls");
        }else if(pilihMenu == 4){
            printf("masukkan nomor telepon pemesan =  ");scanf("%s",&cariTelp);
            if(searchDP(ldp,cariTelp)){
                while(searchDP(ldp,cariTelp)){
                    insertDataPaketJadi(&ldpj,alokasiDataPaketJadi(searchDPadr(ldp,cariTelp)));
                    deleteDP(&ldp,cariTelp);
                }
                printf("nomor telepon pemesan sudah di konfirmasi\n");
            }
            getch();
        }else if(pilihMenu == 5){
            system("cls");
            printf("1.DATA-DATA PENJUALAN\n2.DATA-DATA PEMBATALAN\nPILIH NO : ");scanf("%d",&pilihan);
            if(pilihan == 1){
                cetakListDataPaketJadi(ldpj);
                getch();
            }else if(pilihan == 2){
                cetakListDataBatal(ldpb);
                getch();
            }
        }else if(pilihMenu == 6){
            break;
        }else{
            printf("pilihan dari 1-6 saja\n");
            getch();
        }
        system("cls");
    }
    return 0;
}

