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


#include "travelagi.c"

int main()
{
    listPesawat lp;
    listKota lk;
    listJadwal lj;
    isiDataProgram(&lp,&lk,&lj);

    mulai:
    system("cls");

    printf("===================================\n"
           "          TRAVELAGI.COM\n"
           "   Pesan Tiket Jadi Lebih Mudah\n"
           "===================================\n"
           "\nMENU:\n"
           "1. Pesan Tiket\n"
           "2. Lihat Jadwal\n"
           "3. Lihat Daftar Kota\n"
           "4. Lihat Daftar Maskapai\n"
           "5. Keluar\n"
           "------------------------\n"
           "Pilih menu: ");

    int m;
    scanf("%i",&m);

    switch(m)
    {
        case 1 : pesanTiket(lj,lk); goto mulai; break;
        case 2 : lihatJadwal(lj,lk); goto mulai; break;
        case 3 : lihatListKota(lk); system("pause"); goto mulai; break;
        case 4 : lihatListPesawat(lp); goto mulai; break;
        case 5 : goto selesai; break;
        default: printf("Input salah!\n"); system("pause"); goto mulai; break;
    }

    char j;
    selesai:
    printf("Anda yakin (y/t)?"); j=getche();
    if(j=='t')
        goto mulai;

    return 0;
}
