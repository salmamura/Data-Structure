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
    char cariMeja[100];
    char namaX[size][100];
    char namaMenuX[10];
    char alamatX[size][100];
    char nomorMejaX[size][100];
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

    while(true){
        time_t waktu;
        waktu=time(NULL);
        printf(ctime(&waktu));
        printf("\n");
        printf("\t   ============================ \n");
        printf("\t            SEAFOOD SADIS       \n");
        printf("\t   =========================== \n");
        printf("\t  |  1. INPUT DATA PELANGGAN   |\n");
        printf("\t  |  2. DATA - DATA PELANGGAN  |\n");
        printf("\t  |  3. KONFIRMASI PEMESANAN   |\n");
        printf("\t  |  4. DATA PENJUALAN         |\n");
        printf("\t  |  5. EXIT                   |\n");
        printf("\t   ============================\n\n\n");
        printf("Silakan Pilih No : ");scanf("%d",&pilihMenu);
        if(pilihMenu == 1){
            pilih = 'Y';
            while(inputLagi(pilih)){
                system("cls");

                adrMe mejaAda=lMeja.firstMe;
                boolean status=false;
                cetakListMenu(lmkd);
                while(mejaAda!=NULL){
                    if(nomorMejaX[i]!=NULL){
                        status=true;
                    }else{
                        mejaAda=mejaAda->next;
                    }
                }
                for(i=1;i<=10;i++){
                    printf("\t%d = ",nomorMejaX[i]);
                    if(status){
                        printf("Isi\n");

                    }else{
                        printf("Kosong\n");
                    }
                }
                printf("\nNama Pemesan = ");gets(namaX[i]);gets(namaX[i]);//scanf("%s",&namaX);
                printf("Alamat       = ");gets(alamatX[i]);//scanf("%s",&alamatX);
                printf("No meja      = ");gets(nomorMejaX[i]);
                insertLastData(&ld,alokasiData(namaX[i],alamatX[i],nomorMejaX[i]));
                while(inputLagi(pilih)){
                    gets(namaMenuX);
                    printf("Input menu   = ");gets(namaMenuX);
                    if(searchMenubool(lmkd,namaMenuX)){
                        insertDataMenu(&ldp,alokasiDataMenu(ld,lmkd,nomorMejaX[i],namaMenuX));
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
            printf("masukkan nomor meja pemesan =  ");scanf("%s",&cariMeja);
            if(searchDP(ldp,cariMeja)){
                while(searchDP(ldp,cariMeja)){
                    insertDataMenuJadi(&ldpj,alokasiDataMenuJadi(searchDPadr(ldp,cariMeja)));
                    deleteDP(&ldp,cariMeja);
                }
                printf("nomor meja pemesan sudah di konfirmasi\n");
            }
            getch();
        }else if(pilihMenu == 4){
            system("cls");
            printf("DATA-DATA PENJUALAN\n");
            cetakListDataMenuJadi(ldpj);
            getch();
        }else if(pilihMenu == 5){
            break;
        }else{
            printf("pilihan dari 1-5 saja\n");
            getch();
        }
        system("cls");
    }
    return 0;
}
