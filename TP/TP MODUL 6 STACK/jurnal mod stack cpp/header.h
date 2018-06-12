#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct infoType{
    string id_barang;
    string nama_barang;
    int berat;
};

struct Node{
    infoType info;
    Node *next;
};

typedef struct {
    Node *top;
    int count;
    int weight;
}Stack;

void createStack(Stack *s);
Node* createNode(infoType info);
Node* searchNode(Stack *s, string searchID);
void push(Stack *s, Node *newNode);
void pop(Stack *s, int tipe);
void display(Stack s);

#endif // HEADER_H_INCLUDED
