/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/Adtqv2C.pdf (hal.7-8)
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef queue_H
#define queue_H


typedef struct tElmtMahasiswa *address;
typedef struct tElmtMahasiswa {
	int nim; // NIM mahasiswa bersifat unik (tidak ada yang sama)
	char* nama;
	int nilai;
	address next;
} m1;

typedef struct {
	address head;
	address tail;
} Queue;




// HEADER PROSEDUR DAN FUNGSI

void createEmpty(Queue *Q); //create queue kosong
address alokasi(int nimX, char* namaX, int nilaiX);
void dealokasi(address p);
boolean isEmpty(Queue Q);

void addAddress(Queue *Q, address p);
void add(Queue *Q, int nimX, char* namaX, int nilaiX);
void del(Queue *Q, int *nimX, char* namaX, int *nilaiX);


#endif