#include <stdio.h>
#include <time.h>
#include "body.c"
#include "string.h"

int main()
{
    int pilihMenu;
    int pilihan;
    int size = 1000,i=1;
    char pilih = 'Y';
    int cariMeja;
    char namaX[size][100];
    char namaMenuX[10];
    char alamatX[size][100];
    int nomorMejaX;
    ListMenu lmkd;
    createListMenu(&lmkd);
    ListData ld;
    createListData(&ld);
    ListDP ldp;
    createListDataMenu(&ldp);
    ListDatabatal ldpb;
    createListDataBatal(&ldpb);
    ListDatajadi ldpj;
    createListDataMenuJadi(&ldpj);
    ListMeja lmj;
    createListMeja(&lmj);

    adrMenu pmk0 = alokasiMenu("2","Udang Saos Telor Asin ",25000);
    adrMenu pmk1 = alokasiMenu("3","Kepiting Saos Padang  ",30000);
    adrMenu pmk2 = alokasiMenu("4","Cumi-Cumi Asam Manis  ",25000);
    adrMenu pmk3 = alokasiMenu("5","Kerang Saos Tiram     ",27000);
    adrMenu pmk4 = alokasiMenu("6","Ice Lemon Tea         ",8000);
    adrMenu pmk5 = alokasiMenu("7","Ice Mojito            ",10000);
    adrMenu pmk6 = alokasiMenu("1","Nasi Rempah           ",5000);
    insertMenu(&lmkd,pmk6);
    insertMenu(&lmkd,pmk5);
    insertMenu(&lmkd,pmk4);
    insertMenu(&lmkd,pmk3);
    insertMenu(&lmkd,pmk2);
    insertMenu(&lmkd,pmk1);
    insertMenu(&lmkd,pmk0);

    adrMeja pmj0 = alokasiMeja(1,false);
    adrMeja pmj1 = alokasiMeja(2,false);
    adrMeja pmj2 = alokasiMeja(3,false);
    adrMeja pmj3 = alokasiMeja(4,false);
    adrMeja pmj4 = alokasiMeja(5,false);
    adrMeja pmj5 = alokasiMeja(6,false);
    adrMeja pmj6 = alokasiMeja(7,false);
    adrMeja pmj7 = alokasiMeja(8,false);
    adrMeja pmj8 = alokasiMeja(9,false);
    adrMeja pmj9 = alokasiMeja(10,false);
    insertLastMeja(&lmj,pmj0);
    insertLastMeja(&lmj,pmj1);
    insertLastMeja(&lmj,pmj2);
    insertLastMeja(&lmj,pmj3);
    insertLastMeja(&lmj,pmj4);
    insertLastMeja(&lmj,pmj5);
    insertLastMeja(&lmj,pmj6);
    insertLastMeja(&lmj,pmj7);
    insertLastMeja(&lmj,pmj8);
    insertLastMeja(&lmj,pmj9);

    while(true){
        time_t waktu;
        waktu=time(NULL);
        printf(ctime(&waktu));
        printf("\n");
        printf("\t   ============================ \n");
        printf("\t            SEAFOOD SADIS       \n");
        printf("\t   =========================== \n");
        printf("\t  |  1. INPUT DATA PEMESAN     |\n");
        printf("\t  |  2. DATA - DATA PEMESAN    |\n");
        printf("\t  |  3. PEMBAYARAN PEMESANAN   |\n");
        printf("\t  |  4. DATA PENJUALAN         |\n");
        printf("\t  |  5. LIHAT STATUS MEJA      |\n");
        printf("\t  |  6. EXIT                   |\n");
        printf("\t   ============================\n\n\n");
        printf("Silakan Pilih No : ");scanf("%d",&pilihMenu);
        if(pilihMenu == 1){
            pilih = 'Y';
            while(inputLagi(pilih)){
                system("cls");
                cetakListMenu(lmkd);
                printf("\nNama Pemesan = ");gets(namaX[i]);gets(namaX[i]);//scanf("%s",&namaX);
                printf("Alamat       = ");gets(alamatX[i]);//scanf("%s",&alamatX);
                cetakListMeja(lmj);
                printf("No meja      = ");scanf("%d",&nomorMejaX);
                ubahStatus(&lmj,nomorMejaX);
                insertLastData(&ld,alokasiData(namaX[i],alamatX[i],nomorMejaX));
                while(inputLagi(pilih)){
                    gets(namaMenuX);
                    printf("Input menu   = ");gets(namaMenuX);
                    if(searchMenubool(lmkd,namaMenuX)){
                        insertDataMenu(&ldp,alokasiDataMenu(ld,lmkd,nomorMejaX,namaMenuX));
                        printf("Input menu lagi (Y/N)? ");scanf("%s",&pilih);
                    }else{
                        printf("hanya terdapat menu 1-7, silahkan input lagi\n");
                        break;
                    }
                }
                i = i + 1;
            }
        }else if(pilihMenu == 2){
            system("cls");
            cetakListDataMenu(ldp);
            getch();
        }else if(pilihMenu == 3){
            printf("masukkan nomor meja pemesan =  ");scanf("%d",&cariMeja);
            if(searchDP(ldp,cariMeja)){
                while(searchDP(ldp,cariMeja)){
                    insertDataMenuJadi(&ldpj,alokasiDataMenuJadi(searchDPadr(ldp,cariMeja)));
                    deleteDP(&ldp,cariMeja);
                }
                printf("nomor meja pemesan sudah di konfirmasi\n");
                ubahStatus(&lmj,cariMeja);
            }
            getch();
        }else if(pilihMenu == 4){
            system("cls");
            printf("DATA-DATA PENJUALAN\n");
            cetakListDataMenuJadi(ldpj);
            getch();
        }else if(pilihMenu == 5){
            system("cls");
            cetakListMeja(lmj);
            getch();
        }else if(pilihMenu == 6){
            break;
        }else{
            printf("pilihan dari 1-5 saja\n");
            getch();
        }
        system("cls");
    }
    return 0;
}
