#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"

typedef struct {
    int dd;
    int mm;
    int yy;
} Date;

boolean isValidDate(int d, int m, int y);
Date makeDate(int d, int m, int y);
Date bacaDate();
void tulisDate(Date d);

void konversiBulan (int n);


#endif // DATE_H_INCLUDED
