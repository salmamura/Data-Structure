/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "multilist2.h"

int main()
{
	ListPeg lpeg;
	createListPeg(&lpeg);

	adrPeg pp0 = alokasiPeg(13840000,"Bapaknya_Nobita",15000000);
	adrPeg pp1 = alokasiPeg(13840001,"Naruto",12500000);
	adrPeg pp2 = alokasiPeg(13840002,"Bapaknya_UpinIpin",13000000);
	adrPeg pp3 = alokasiPeg(13840003,"Bapaknya_Shizuka",10000000);
	insertFirstPeg(&lpeg,pp0);
	insertLastPeg(&lpeg,pp1);
	insertLastPeg(&lpeg,pp2);
	insertLastPeg(&lpeg,pp3);
	printf("nbElmtPeg(lpeg) = %i\n",nbElmtPeg(lpeg));
	printf("maxGajiPeg(lpeg) = %i\n",maxGajiPeg(lpeg));

	ListAnak lan; //diubah jadi ListAnak
	createListAnak(&lan);
	adrAnak pa0 = alokasiAnak("Doraemon",true,pp0);
	adrAnak pa1 = alokasiAnak("Nobita",true,pp0);
	adrAnak pa2 = alokasiAnak("Shizuka",false,pp3);
	adrAnak pa3 = alokasiAnak("Upin",true,pp2);
	adrAnak pa4 = alokasiAnak("Ipin",true,pp2);
	adrAnak pa5 = alokasiAnak("Aminah",false,pp2);
	insertFirstAnak(&lan,pa0);
	insertLastAnak(&lan,pa1);
	insertLastAnak(&lan,pa2);
	insertLastAnak(&lan,pa3);
	insertLastAnak(&lan,pa4);
	insertLastAnak(&lan,pa5);

	cetakPegAnak(lpeg,lan);

	printf("[0=No,1=Yes] searchPegBool(lpeg,13840002) = %i\n",searchPegBool(lpeg,13840002));
	printf("searchPeg(lpeg,13840002) = %p\n",searchPeg(lpeg,13840002));

	cetakAnak(lpeg,lan,13840002);
	printf("[0=No,1=Yes] searchAnakBool(lan,Nobita) = %i\n",searchAnakBool(lan,"Nobita"));
	printf("NIP orangtua Nobita adalah = %i\n",searchAnak(lan,"Nobita"));

	printf("Banyaknya total anak = %i\n",nbAnak(lan)); //diganti jadi lan
	printf("Banyaknya anak laki-laki = %i\n",nbSon(lan)); //diganti jadi lan
	printf("Banyaknya anak perempuan = %i\n",nbDaughter(lan)); //diganti jadi lan

    return 0;
}
