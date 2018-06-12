/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "multilist1.h"

int main()
{
	ListPeg lpeg;
	createListPeg(&lpeg);

	adrPeg pp0 = alokasiPeg(110001,"Naruto",9000000);
	adrPeg pp1 = alokasiPeg(110002,"Sasuke",10000000);
	adrPeg pp2 = alokasiPeg(110003,"Tarno",500000);
	adrPeg pp3 = alokasiPeg(110004,"Aang",950000);

	printf("nbElmtPeg(lpeg) = %i\n",nbElmtPeg(lpeg));
	printf("maxGajiPeg(lpeg) = %i\n",maxGajiPeg(lpeg));

	adrAnak pa0 = alokasiAnak("boruto",true);
	adrAnak pa1 = alokasiAnak("himawari",true);
	adrAnak pa2 = alokasiAnak("sarada",false);
	adrAnak pa3 = alokasiAnak("babe",true);
	adrAnak pa4 = alokasiAnak("guntur",true);
	adrAnak pa5 = alokasiAnak("nunung",false);
	adrAnak pa6 = alokasiAnak("tenzin",true);
	adrAnak pa7 = alokasiAnak("bumi",true);
	adrAnak pa8 = alokasiAnak("kaya",false);

	insertFirstPeg(&lpeg,pp0);
	insertLastPeg(&lpeg,pp1);
	insertAfterPeg(ListPeg &lpeg, adrPeg pp1, adrPeg pp0);
	insertAfterPeg(ListPeg &lpeg, adrPeg pp2, adrPeg pp3);

	tambahAnak(&lpeg,pa0,"Naruto");
	tambahAnak(&lpeg,pa1,"Naruto");
	tambahAnak(&lpeg,pa2,"Sasuke");
	tambahAnak(&lpeg,pa3,"Tarno");
	tambahAnak(&lpeg,pa4,"Tarno");
	tambahAnak(&lpeg,pa5,"Tarno");
	tambahAnak(&lpeg,pa6,"Aang");
	tambahAnak(&lpeg,pa7,"Aang");
	tambahAnak(&lpeg,pa8,"Aang");


    printf("kondisi awal : \n");
	cetakPegAnak(lpeg); // mencetak data seluruh pegawai dan anak-anaknya
	printf("Banyaknya total anak = %i\n",nbAnak(lpeg));
	printf("Banyaknya anak laki-laki = %i\n",nbSon(lpeg));
	printf("Banyaknya anak perempuan = %i\n",nbDaughter(lpeg));

	printf("kondisi akhir : \n");
    deleteFirstPeg(ListPeg *LP);
    deleteLastPeg(ListPeg *LP);
	cetakPegAnak(lpeg);
	printf("Banyaknya total anak = %i\n",nbAnak(lpeg));
	printf("Banyaknya anak laki-laki = %i\n",nbSon(lpeg));
	printf("Banyaknya anak perempuan = %i\n",nbDaughter(lpeg));

    return 0;
}
