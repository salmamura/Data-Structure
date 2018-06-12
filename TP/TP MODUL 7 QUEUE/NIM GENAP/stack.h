#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef stack_H
#define stack_H

typedef struct tElmtPeg *address;
typedef struct tElmtPeg {
    int noPeg; // noPeg Pegawai bersifat unik (tidak ada yang sama)
    char* nama;
    int gaji;
    address next;
} b1;

typedef struct {
    address top;
} Stack;

// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S); //create stack kosong
address alokasi(int noPegX, char* namaX, int gajiX);
void dealokasi(address p);
boolean isEmpty(Stack S);
void pushAddress(Stack *S, address p);
void push(Stack *S, int noPegX, char* namaX, int gajiX);
void pop(Stack *S, int *noPegX, char* namaX, int *gajiX);

#endif
