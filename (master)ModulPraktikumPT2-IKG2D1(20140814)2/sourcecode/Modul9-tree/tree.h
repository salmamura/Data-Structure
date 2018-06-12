/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/IF_2181Pohon.pdf (hal.6-13 dan hal.16)
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


#ifndef tree_H
#define tree_H




typedef struct tElmtMahasiswa *address;
typedef struct tElmtMahasiswa {
	int nim; // NIM mahasiswa bersifat unik (tidak ada yang sama)
	char* nama;
	int nilai;
	address left;
	address right;
} m1;

typedef address BinTree;



// HEADER PROSEDUR DAN FUNGSI

void makeTree(BinTree *p, int nimX, char* namaX, int nilaiX, address leftX, address rightX); //create root untuk pohon
void insertNode(BinTree *p, int nimX, char* namaX, int nilaiX); // insert node terurut (cek agar NIM yang masuk ke tree tidak double)

void cetakPreOrder(BinTree p);
void cetakInOrder(BinTree p);
void cetakPostOrder(BinTree p);

boolean search(BinTree p, int nimX);

int nbNode(BinTree p);
int sumNilai(BinTree p);
int maxNilai(BinTree p);
int minNilai(BinTree p);

int nbDaun(BinTree p);
int nbParent(BinTree p);

int levelOfNode(BinTree p, int nimX); // nimX ada di level berapa (level root = 0, dst...)
int depthOfTree(BinTree p);

#endif
