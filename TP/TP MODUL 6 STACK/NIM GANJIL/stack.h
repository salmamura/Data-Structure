#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef stack_H
#define stack_H

typedef struct tElmtBuku *address;
typedef struct tElmtBuku {
    int NISBN; // NISBN buku bersifat unik (tidak ada yang sama)
    char* judul;
    char* author;
    address next;
} b1;

typedef struct {
    address top;
} Stack;

// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S); //create stack kosong
address alokasi(int nisbnX, char* judulX, char* authorX);
void dealokasi(address p);
boolean isEmpty(Stack S);
void pushAddress(Stack *S, address p);
void push(Stack *S, int nisbnX, char* judulX, char* authorX);
void pop(Stack *S, int *nisbnX, char* judulX, char* authorX);

#endif
