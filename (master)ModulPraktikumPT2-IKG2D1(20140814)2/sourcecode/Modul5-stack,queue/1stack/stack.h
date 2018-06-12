/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
Reference: http://kur2003.if.itb.ac.id/file/Adtstakv2.pdf (hal.7-10)
*/


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef stack_H
#define stack_H


typedef struct tElmtMahasiswa *address;
typedef struct tElmtMahasiswa {
	int nim; // NIM mahasiswa bersifat unik (tidak ada yang sama)
	char* nama;
	int nilai;
	address next;
} m1;

typedef struct {
	address top;
} Stack;




// HEADER PROSEDUR DAN FUNGSI

void createEmpty(Stack *S); //create stack kosong
address alokasi(int nimX, char* namaX, int nilaiX);
void dealokasi(address p);
boolean isEmpty(Stack S);

void pushAddress(Stack *S, address p);

void push(Stack *S, int nimX, char* namaX, int nilaiX);
void pop(Stack *S, int *nimX, char* namaX, int *nilaiX);


#endif
