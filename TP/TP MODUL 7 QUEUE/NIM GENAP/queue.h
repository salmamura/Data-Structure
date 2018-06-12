/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/Adtqv2C.pdf (hal.7-8)
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include <string.h>

#ifndef queue_H
#define queue_H


typedef struct tElmtPasien *address;
typedef struct tElmtPasien {
	char* kodePasien;
	char* nama;
	char* dokter;
	address next;
} pasien;

typedef struct {
	address head;
	address tail;
} Queue;




// HEADER PROSEDUR DAN FUNGSI

void createEmpty(Queue *Q); //create queue kosong
address alokasi(char* kode, char* nama, char* dokter);
void dealokasi(address p);
boolean isEmpty(Queue Q);

void addAddress(Queue *Q, address p);
void add(Queue *Q, char* kode, char* nama, char* dokter);
void del(Queue *Q, char kode[50], char nama[50], char dokter[50]);
void dequeue(Queue *Q);//membuat head queue terhapus , didalam fungsi harus ada kondisi jika
//1.List kosong
//2.Isi List cuma 1
//3.Isi list banyak
#endif
