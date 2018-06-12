#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef stack_H
#define stack_H

typedef struct tElmtPutar *address;
typedef struct tElmtPutar {
    char* huruf;
    address next;
} p1;

typedef struct {
    address top;
} Stack;

// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S); //create stack kosong
address alokasi(char* hurufX);
void dealokasi(address p);
boolean isEmpty(Stack S);
void pushAddress(Stack *S, address p);
void push(Stack *S, char*namaX);
void pop(Stack *S, char*namaX);

#endif
