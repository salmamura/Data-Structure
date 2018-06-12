#include <stdio.h>
#include "jam.h"

// FUNGSI VALIDASI
boolean isValidJam(int h, int m, int s){
/* Fungsi isValidJam:
I.S.: h, m, s adalah masukan integer sebarang
F.S.: return true bila h, m, s berada dalam range yang benar untuk jam (0..23, 0..59, 0..59)
*/
	if((h>=0)&&(h<24)&&(m>=0)&&(m<60)&&(s>=0)&&(s<60)){
		return true;
	}else{
		return false;
	}
}


// FUNGSI KONSTRUKTOR
Jam makeJam(int h, int m, int s){
/* Fungsi makeJam:
I.S.: h, m, s adalah masukan integer sebarang
F.S.: lakukan pengecekan dengan memanggil fungsi isValid, kemudian bentuklah sebuah Jam dari komponen h, m, s
*/
	Jam j;

	if(isValidJam(h,m,s)==true){
		j.hh=h;
		j.mm=m;
		j.ss=s;		
	}else{
		j.hh=0;
		j.mm=0;
		j.ss=0;
	}
	return j;
}



// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR
Jam bacaJam(){
	int h,m,s;
	boolean stat;
	Jam j;

	stat=false;
	while(stat==false){
		printf("Jam: ");
		scanf("%d",&h);
		printf("Menit: ");
		scanf("%d",&m);
		printf("Detik: ");
		scanf("%d",&s);
		if(isValidJam(h,m,s)==true){
			j.hh=h;
			j.mm=m;
			j.ss=s;
			stat=true;
		}else{
			printf("Jam yang anda masukkan tidak valid. Silahkan masukkan kembali jam. \n");
			stat==false;
		}
	}
	return j;	
}

void tulisJam(Jam j){
// Prosedur tulisJam: menampilkan jam ke layar dengan format [hh:mm:ss]
	printf("%d : %d : %d \n",j.hh,j.mm,j.ss);	
}



// FUNGSI KONVERSI
int jamToDetik(Jam j){
	int jum;

	jum=(j.hh*3600)+(j.mm*60)+j.ss;
	return jum;
}

Jam detikToJam(int s){
	int jam, menit, detik;
	Jam j;

	jam=s/3600;
	menit=(s%3600)/60;
	detik=(s%6000)%60;
	if(isValidJam(jam,menit,detik)==true){
		j.hh=jam;
		j.mm=menit;
		j.ss=detik;
	}else{
		j.hh=0;
		j.mm=0;
		j.ss=0;
	}
	return j;
}


// OPERASI ARITMETIK
int durasi(Jam jaw, Jam jakh){
	int jam1, jam2, selisih;

	jam1=jamToDetik(jaw);
	jam2=jamToDetik(jakh);
	selisih=abs(jam1-jam2);
	return selisih;
}

Jam jMinus(Jam j1, Jam j2){
// Fungsi jMinus: mengecek j1<=j2, lalu menghitung j2-j1, outputnya berupa Jam juga
	int selisih;
	Jam j;
	if((j1.hh<j2.hh)||((j1.hh==j2.hh)&&(j1.mm<=j2.mm))){
		selisih=durasi(j2,j1);
		j=detikToJam(selisih);
	}else{
		j.hh=0;
		j.mm=0;
		j.ss=0;
	}
	return j;
}

Jam jPlus(Jam j1, Jam j2){
// Fungsi jPlus: menjumlahkan j1+j2, outputnya berupa Jam juga
	int s1, s2, jum;
	Jam j;

	s1=jamToDetik(j1);
	s2=jamToDetik(j2);
	jum=s1+s2;
	j=detikToJam(jum);
	return j;
}



Jam nextDetik(Jam j){
	if((j.ss>=0)&&(j.ss<59)){
		j.ss++;
	}else{
		if((j.mm>=0)&&(j.mm<59)){
			j.ss=0;
			j.mm++;
		}else if(j.mm==59){
			j.ss=0;
			j.mm=0;
			j.hh++;
		}
	}
	return j;
}

Jam prevDetik(Jam j){
	if(j.ss==0){
		if(j.mm==0){
			j.ss=59;
			j.mm=59;
			j.hh=j.hh-1;
		}else{
			j.ss=59;
			j.mm=j.mm-1;
		}
	}else{
		j.ss=j.ss-1;
	}
}


// OPERASI RELATIONAL (PERBANDINGAN)
boolean jEqual(Jam j1, Jam j2){
	if((j1.hh==j2.hh)&&(j1.mm==j2.mm)&&(j1.ss==j2.ss)){
		return true;
	}else{
		return false;
	}
}

boolean jNotEqual(Jam j1, Jam j2){
	if(jEqual(j1,j2)==true){
		return false;
	}else{
		return true;
	}
}

boolean jLessThan(Jam j1, Jam j2){
	int jam1,jam2;

	jam1=jamToDetik(j1);
	jam2=jamToDetik(j2);
	if(jam1<jam2){
		return true;
	}else{
		return false;
	}
}

boolean jGreaterThan(Jam j1, Jam j2){
	if(jLessThan(j1,j2)==true){
		return false;
	}else{
		return true;
	}
}
