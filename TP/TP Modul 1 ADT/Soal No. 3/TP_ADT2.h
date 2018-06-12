#ifndef TP_ADT2_H_INCLUDED
#define TP_ADT2_H_INCLUDED

#include<stdio.h>

typedef struct {
	char*   nama;   //nama pokemon
	int     atk;    //attack point pokemon
	int     def     //deffense point pokemon
} Pkm;


            //Fungsi dan Prosedur

Pkm pokemonBaru(char* namaX, int atkX, int defX);
//fungsi digunakan untuk input data pokemon

int cekGol(Pkm x);
// jika atk besar dari def    , maka pokemon golongan 1
// jika atk sama dengan def   , maka pokemon golongan 2
// jika atk kecil dari def   , maka pokemon golongan 3

void cekType(Pkm x);
// jika pokemon golongan 1,   maka tampilkan "menyerang"
// jika pokemon golongan 2,   maka tampilkan "stabil"
// jika pokemon golongan 3,   maka tampilkan "bertahan"

void cetakInfo(Pkm x);
// cetak info pokemon, berupa: Nama, Attack, Deffense, dan Type

void aduPokemon(Pkm serang, Pkm tahan);
// tampilkan nama pokemon yang menang dengan ketentuan:
//    - jika atk pokemon serang besar dari def pokemon tahan, maka pokemon serang menang
//    - jika atk pokemon serang kecil dari def pokemon tahan, maka pokemon tahan menang
//    - jika atk pokemon serang sama dengan def pokemon tahan, maka tampilkan "seri"


#endif // TP_ADT2_H_INCLUDED
