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


typedef struct tElmtNasabah *address;
typedef struct tElmtNasabah {
	char* kodeNasabah;
	char* nama;
	int jumlah;
	address next;
} n1;

typedef struct {
	address head;
	address tail;
} Queue;




// HEADER PROSEDUR DAN FUNGSI

void createEmpty(Queue *Q); //create queue kosong
address alokasi(char* kodeX, char* namaX, int jumlah);
void dealokasi(address p);
boolean isEmpty(Queue Q);

void addAddress(Queue *Q, address p);
void add(Queue *Q, char* kodeX, char* namaX, int jumlah);
void del(Queue *Q, char kodeX[50], char namaX[50], int *jumlah);
void dequeue(Queue *Q);//membuat head queue terhapus didalam fungsi harus ada kondisi jika
//1.List kosong
//2.Isi List cuma 1
//3.Isi list banyak
#endif
