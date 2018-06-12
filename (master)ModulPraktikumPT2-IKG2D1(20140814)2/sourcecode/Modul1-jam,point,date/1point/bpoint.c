#include <stdio.h>
#include "point.h"

Point makePoint(int x, int y){

    Point p;
    p.x = x;
    p.y = y;

    return p;
}
Point bacaPoint(){
    Point p;
    int x,y;

    printf("masukkan x : ");scanf("%d",&x);
    printf("masukkan y : ");scanf("%d",&y);
    p = makePoint(x,y);
}
void tulisPoint(Point p){

    printf(" = %d,p.x,p.y ");

}
Point pTambah(Point p1, Point p2){
    Point hasil;

    hasil.x = p1.x + p2.x;
    hasil.y = p2.y - p2.y;

    return hasil;
}
Point pKurang(Point p1, Point p2){
    Point hasil;

    hasil.x = p1.x + p2.x;
    hasil.y = p2.y - p2.y;

    return hasil;
}
float pDotProduct(Point p1, Point p2){
    float hasil;

    hasil = (p1.x*p2.x)+(p1.y*p2.y);
    return hasil;

}
Point pCrossProduct(Point p1, Point p2){
    Point hasil;

    hasil.x = p1.x*p2.x;
    hasil.y = p1.y*p2.y;

    return hasil;
}
boolean isOrigin(Point p){
    if((p.x == 0)&&(p.y == 0)){
        return true;
    }else{
        return false;
    }
}
boolean isOnSbX(Point p){
    if(p.x == 0){
        return true;
    }else{
        return false;
    }
}
boolean isOnSbY(Point p){
    if(p.x == 0){
        return true;
    }else{
        return false;
    }
}
int kuadran(Point p){
    if((p.x>0)&&(p.y>0)){
        return 1;
    }else if((p.x<0)&&(p.y>0)){
            return 2;
        }else if((p.x<0)&&(p.y<0)){
            return 3;
        }else if((p.x>0)&&(p.y<0)){
            return 4;
        }else{
            return 0;
        }
    }

float jarakOrigin(Point p){
    float Jarak;

    Jarak = sqrt(pow(p.x,2)+pow(p.y,2));
    return Jarak;

}
Point pMirrorSbX(Point p){
    Point hasil;

    hasil.x = p.x;
    hasil.y = p.y*(-1);

    return hasil;
}
Point pMirrorSbY(Point p){
    Point hasil;

    hasil.x = p.x*(-1);
    hasil.y = p.y;

    return hasil;
}
Point pTranslasi(Point p, int dx, int dy){
    Point hasil;

    hasil.x = p.x + dx;
    hasil.y = p.y + dy;

    return hasil;
}
Point pRotasi(Point p, float angle){
    Point hasil;

    hasil.x = (p.x*cos(angle)) - (p.y*sin(angle));
    hasil.y = (p.x*sin(angle)) + (p.y*cos(angle));

    return hasil;
}


