#include <stdio.h>
#include "bm.c"

int main()
{
	ListDosen ld;
	createListDosen(&ld);
	adrDosen pd0 = alokasiDosen("IZA","Izzatul_Ummah",11000000);
	adrDosen pd1 = alokasiDosen("YLS","Yuliant_Sibaroni",12500000);
	adrDosen pd2 = alokasiDosen("MHD","Mahmud_Imrona",13000000);
	adrDosen pd3 = alokasiDosen("RFU","Rian_Umbara",12000000);
	insertFirstDosen(&ld,pd0);
	insertLastDosen(&ld,pd1);
	insertLastDosen(&ld,pd2);
	insertLastDosen(&ld,pd3);

	ListMK lmk;
	createListMK(&lmk);
	adrMK pm0 = alokasiMK("KUG1E3","Pemrograman_Terstruktur_I",3);
	adrMK pm1 = alokasiMK("IKG2A3","Pemrograman_Terstruktur_II",3);
	adrMK pm2 = alokasiMK("IKG2F4","Analisis dan Perancangan Algoritma",4);
	adrMK pm3 = alokasiMK("IKG2I4","Software_Project_I",4);
	insertFirstMK(&lmk,pm0);
	insertLastMK(&lmk,pm1);
	insertLastMK(&lmk,pm2);
	insertLastMK(&lmk,pm3);

	ListMKDOS lmkd;
	createListMKDOS(&lmkd);
	adrMKDOS pmk0 = alokasiMKDOS(ld,lmk,"IZA","IKG2A3");
	adrMKDOS pmk1 = alokasiMKDOS(ld,lmk,"IZA","IKG2F4");
	adrMKDOS pmk2 = alokasiMKDOS(ld,lmk,"IZA","IKG2I4");
	adrMKDOS pmk3 = alokasiMKDOS(ld,lmk,"YLS","KUG1E3");
	adrMKDOS pmk4 = alokasiMKDOS(ld,lmk,"YLS","IKG2A3");
	adrMKDOS pmk5 = alokasiMKDOS(ld,lmk,"MHD","KUG1E3");
	adrMKDOS pmk6 = alokasiMKDOS(ld,lmk,"MHD","IKG2A3");
	adrMKDOS pmk7 = alokasiMKDOS(ld,lmk,"MHD","IKG2I4");
	adrMKDOS pmk8 = alokasiMKDOS(ld,lmk,"RFU","IKG2I4");
	insertFirstMKDOS(&lmkd,pmk0);
	insertLastMKDOS(&lmkd,pmk1);
	insertLastMKDOS(&lmkd,pmk2);
	insertLastMKDOS(&lmkd,pmk3);
	insertLastMKDOS(&lmkd,pmk4);
	insertLastMKDOS(&lmkd,pmk5);
	insertLastMKDOS(&lmkd,pmk6);
	insertLastMKDOS(&lmkd,pmk7);
	insertLastMKDOS(&lmkd,pmk8);

	cetakListMKDOS(lmkd); // mencetak pasangan data kode matakuliah dan kode dosen yang mengajar matakuliah tersebut

	printf("[0=No,1=Yes] searchDosenBool(ld,MHD) = %i\n",searchDosenBool(ld,"MHD"));
	printf("searchDosen(ld,MHD) = %p\n",searchDosen(ld,"MHD"));
	printf("[0=No,1=Yes] searchMKBool(lmk,IKG2A3) = %i\n",searchMKBool(lmk,"IKG2A3"));
	printf("searchMK(lmk,IKG2A3) = %p\n",searchMK(lmk,"IKG2A3"));

	cetakMKbyDosen(ld,lmkd,"YLS");
	cetakDosenbyMK(lmk,lmkd,"IKG2I4");

	boolean b = isRelated(ld,"RFU",lmk,"IKG2A4",lmkd);
	printf("\n[0=No,1=Yes] isRelated(ld,RFU,IKG2A4) = %i\n",b);

	int x = totalSKSDosen(ld,"IZA",lmkd);
	printf("\ntotalSKSDosen(ld,IZA,lmkd) = %i\n",x);

    return 0;
}
