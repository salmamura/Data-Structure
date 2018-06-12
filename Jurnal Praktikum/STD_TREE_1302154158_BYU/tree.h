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
int nbNode(BinTree p); //banyaknya node
int sumNilai(BinTree p); //Penjumlahan nilai semua node
int maxNilai(BinTree p); //untuk semua rentang nilai -tak hingga sampai tak hingga
int minNilai(BinTree p); //untuk semua rentang nilai -tak hingga sampai tak hingga
int nbDaun(BinTree p); //Daun = tidak memiliki cabang
int nbParent(BinTree p); //Parent = memiliki cabang
int levelOfNode(BinTree p, int nimX);
// nimX ada di level berapa (level root = 0, dst...)
// nimX dijamin ada di tree
int depthOfTree(BinTree p); // kedalaman maksimal tree
void reverseTree(BinTree *p);
//lihat contoh berikut
/*
      Tampak Depan            Tampak Belakang
           5                        5
         /   \                    /   \
        2     8                  8     2
       / \   / \    MENJADI     / \   / \
      1   4 6   9              9   6 4   1
         /   \                    /   \
        3     7                  7     3
*/
void cetakOnLevel(BinTree p, int level);//mencetak semua nama/nim yang berada di level tertentu ( level root = 0 )
int maxNilaiOnLevel(BinTree p,int level); //mengembalikan nilai max pada level tertentu, jika tidak terdapat node di level tersebut return -1
int minNilaiOnLevel(BinTree p,int level); //mengembalikan nilai max pada level tertentu, jika tidak terdapat node di level tersebut return 101

#endif
