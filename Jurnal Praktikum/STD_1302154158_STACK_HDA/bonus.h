#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef stack_H
#define stack_H

typedef struct tElmtKasur *address;
typedef struct tElmtKasur {
    char* kasur; // kodeLagu bersifat unik (tidak ada yang sama)
    address next;
} rusak;

typedef struct {
    address top;
} Stack;

// HEADER PROSEDUR DAN FUNGSI
void createEmpty(Stack *S); //create stack kosong
address alokasi(char* kasurX);
void dealokasi(address p);
boolean isEmpty(Stack S);
void pushAddress(Stack *S, address p);
void push(Stack *S, char* kasurX);
void pop(Stack *S, char* kasurX);

#endif
