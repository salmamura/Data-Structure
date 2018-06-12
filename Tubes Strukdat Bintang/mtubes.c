#include <stdio.h>
#include "tubes.c"

void main(){
    lMeja ListMe; createListMeja(&ListMe);
    lMakanan ListMa; createListMakanan(&ListMa);
    QTunggu QueueT; createQueueTunggu(&QueueT);
    int i,banyakMeja=1;
    for(i=1;i<=banyakMeja;i++){
        isiListMeja(&ListMe,i,0);
    }
    isiMenuMakanan(&ListMa,1,"Gudeg\t",8);
    isiMenuMakanan(&ListMa,2,"Sate\t",12);
    isiMenuMakanan(&ListMa,3,"Ayam goreng",3);
    isiMenuMakanan(&ListMa,4,"Sup\t",3);
    isiMenuMakanan(&ListMa,5,"Bala-Bala",3);
    isiMenuMakanan(&ListMa,6,"Es Teh\t",3);
    isiMenuMakanan(&ListMa,7,"Jus Jeruk",3);

    char pilihanMenuUtama;
    boolean tutup=false;
    adrMe mejaCetak=ListMe.firstMe;
    int noPelMasuk=0;
    while(!tutup){
        system("cls");
        printf("\nSELAMAT DATANG DI RESTORAN TUBES STRUKDAT\n=====================================\n");
        printf("Silahkan ketik nomor pilihan\n");
        printf("1 Pengisian Meja\n2 Pengosongan Meja\n3 Tutup restoran\n");
        printf("PILIHAN: ");
        pilihanMenuUtama=getche();
        if(pilihanMenuUtama=='1'){
            system("cls");
            noPelMasuk++;
            printf("\nNo. Antrian: %d",noPelMasuk);

            adrMe mejaKosong=ListMe.firstMe;
            boolean adaKosong=false;
            while((mejaKosong!=NULL)&&(!adaKosong)){
                if(mejaKosong->noPelanggan==0){
                    adaKosong=true;
                }else{
                    mejaKosong=mejaKosong->next;
                }
            }
            if(mejaKosong==NULL){
                printf("\nMeja penuh. Ingin dimasukkan ke Waiting List?\n");
                boolean inginTunggu;
                yaTidak(&inginTunggu);
                if(inginTunggu){
                    system("cls");
                    masukQueueTunggu(&QueueT,noPelMasuk);
                    printf("No. Antrian %d sudah dimasukkan ke Waiting Queue",(QueueT.tailT)->noPelanggan);
                    tekanSembarang();
                }else{
                    printf("Terima kasih\n");
                }
            }else if(adaKosong==true){
                mejaKosong->noPelanggan=noPelMasuk;
                pesanMakanan(&mejaKosong,ListMa);
            }
        }else if(pilihanMenuUtama=='2'){
            boolean pindahkan=false;
            adrMe mejaKosong;
            pengosonganMeja(&ListMe,&QueueT,&mejaKosong);
            if(QueueT.headT!=NULL){
                printf("\nPelanggan dengan nomor %d berada di awal antrian tunggu. Masukkan ke dalam meja %d?\n",QueueT.headT->noPelanggan,mejaKosong->noMeja);
                yaTidak(&pindahkan);
                if(pindahkan){
                    int pelangganMasuk;
                    keluarQueueTunggu(&QueueT,&pelangganMasuk);
                    mejaKosong->noPelanggan=pelangganMasuk;
                    pesanMakanan(&mejaKosong,ListMa);
                }
            }else{
                tekanSembarang();
            }
        }else if(pilihanMenuUtama=='3'){
            boolean statusMejaKosong=true;
            boolean antrianKosong=false;
            adrMe cekMeja=ListMe.firstMe;
            while((cekMeja!=NULL)&&(statusMejaKosong)){
                if(cekMeja->noPelanggan!=0){
                    statusMejaKosong=false;
                }else{
                    cekMeja=cekMeja->next;
                }
            }
            if(QueueT.tailT==NULL){
                    antrianKosong=true;
            }

            if((statusMejaKosong)&&(antrianKosong)){
                printf("\nTUTUP");
                delAllMakanan(&ListMa);
                delAllMeja(&ListMe);
                tutup=true;
            }else{
                printf("Restoran masih belum bisa ditutup. Masih terdapat orang di antrian tunggu dan/atau Meja\n");
                cekMeja=ListMe.firstMe;
                printf("MEJA\nNo. Meja\tNo. Antrian\n======================\n");
                while(cekMeja!=NULL){
                    printf("%d\t\t%d\n",cekMeja->noMeja,cekMeja->noPelanggan);
                    cekMeja=cekMeja->next;
                }
                adrT cekAntrian=QueueT.headT;
                printf("ANTRIAN TUNGGU:\n|");
                while(cekAntrian!=NULL){
                    printf(" %d |",cekAntrian->noPelanggan);
                    cekAntrian=cekAntrian->next;
                }
                tekanSembarang();
                system("cls");
            }
        }
    }
}
