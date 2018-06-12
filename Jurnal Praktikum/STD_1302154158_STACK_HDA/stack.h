#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef stack_H
#define stack_H

typedef struct tElmtLagu *address;
typedef struct tElmtLagu {
    char* kodeLagu; // kodeLagu bersifat unik (tidak ada yang sama)
    char* judul;
    char* pencipta;
    int tahun;
    address next;
} lagu;

typedef struct {
    address top;
} Stack;

// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S); //create stack kosong
address alokasi(char* kodeX, char* judulX, char* penciptaX, int yearX);
void dealokasi(address p);
boolean isEmpty(Stack S);
void pushAddress(Stack *S, address p);
void push(Stack *S, char* kodeX, char* judulX, char* penciptaX, int yearX);
void pop(Stack *S, char* kodeX, char* judulX, char* penciptaX, int *yearX);

#endif
