#include<stdio.h>
#include"point.h"
#include"boolean.h"



// FUNGSI KONSTRUKTOR
Point makePoint(int x, int y){
    Point p;
    p.x=x;
    p.y=y;
    return p;

}


// FUNGSI UNTUK MEMBACA INPUT DARI KEYBOARD DAN MENULIS KE LAYAR

Point bacaPoint(){ //fungsi untuk membaca input dari keyboard dan menulis ke layar
    int x;
    int y;
    Point p;
    printf("\nMasukkan x = %d ",p.x);
    scanf("%d",&x);
    printf("\nMasukkan y = %d \n",p.y);
    scanf("%d",&y);
    p=makePoint(x,y);
return p;
}


void tulisPoint(Point p){ //prosedur untuk menampilkan point ke layar dengan format (x,y)
    printf("\n %d %d ",p.x,p.y);
}

// OPERASI ARITMETIK
Point pTambah(Point p1, Point p2){ //penjumlahan masing-masing atribut p1 dan p2
    Point hasil;
    hasil.x=p1.x+p2.x;
    hasil.y=p1.y+p2.y;
return hasil;
}


Point pKurang(Point p1, Point p2){ //pengurangan masing-masing atribut p1 dan p2
    Point hasil;
    hasil.x=p1.x-p2.x;
    hasil.y=p1.y-p2.y;
return hasil;
}


float pDotProduct(Point p1, Point p2){ //rumus dot product: x1*x2 + y1*y2
    float hasil;
    hasil=(p1.x*p2.x)+(p1.y*p2.y);
    return hasil;
}


Point pCrossProduct(Point p1, Point p2){ //pengalian masing-masing atribut p1 dan p2
    Point hasil;
    hasil.x=p1.x*p2.x;
    hasil.y=p1.y*p2.y;
    return hasil;
}



// OPERASI RELATIONAL (PERBANDINGAN)
boolean pEqual(Point p1, Point p2){ //memeriksa apakah p1 sama dengan p2
    if((p1.x==p2.x) && (p1.y==p2.y)){
        return true;
    }else{
        return false;
    }
}



boolean pNotEqual(Point p1, Point p2){ //memeriksa apakah p1 tidak sama dengan p2
    if((p1.x!=p2.x) && (p1.y!=p2.y)){
        return true;
    }else{
        return false;
    }
}



boolean pLessThan(Point p1, Point p2){ //memeriksa apakah p1 berada di sebelah kiri-bawah dari p2
    if((p1.x<p2.x) && (p1.y<p2.y)){
        return true;
    }else{
        return false;
    }
}



boolean pGreatherThan(Point p1, Point p2){//memeriksa apakah p1 berada di sebelah kanan-atas dari p2
    if((p1.x>p2.x)&&(p1.y>p2.y)){
        return true;
    }else{
        return false;
    }
}




// FUNGSI POSISI KOORDINAT
boolean isOrigin(Point p){ //memeriksa apakah p berada pada sumbu x dan y (0,0)
    if((p.x==0) && (p.y==0)){
        return true;
    }else{
        return false;
    }
}


boolean isOnSbX(Point p){ //memeriksa apakah p berada pada sumbu x
    if(p.y==0){
        return true;
    }else{
        return false;
    }
}


boolean isOnSbY(Point p){ //memeriksa apakah p berada pada sumbu y
    if(p.x=0){
        return true;
    }else{
        return false;
    }
}


int kuadran(Point p){ //menghasilkan nilai kuadran dari titik p (kuadran 1, 2, 3, 4) dengan syarat P bukan di titik origin atau sumbu X-Y
    if((p.x>0)&&(p.y>0)){
        return 1;
    }else{
        if((p.x<0)&&(p.y>0)){
            return 2;
        }else{
            if((p.x<0)&&(p.y<0)){
                return 3;
            }else{
            if((p.x<0)&&(p.y<0)){
                return 3;
            }else{
                if((p.x>0)&&(p.y<0)){
                    return 4;
                }else{
                    return 0;
                    }
                }
            }
        }
    }
}

// OPERASI LAIN: PENCERMINAN, ROTASI, TRANSLASI
float jarakOrigin(Point p){ //hitung jarak antara titik p ke pusat koordinat (0,0)
    return sqrt(p.x*p.x+p.y*p.y);
}


Point pMirrorSbX(Point p){//pencerminan terhadap sumbu x
    Point mir;
    mir.x=p.x;
    mir.y=p.y*-1;
    return mir;
}


Point pMirrorSbY(Point p){ //pencerminan terhadap sumbu y
    Point mir;
    mir.y=p.y;
    mir.x=p.x*-1;
    return mir;
}


Point pTranslasi(Point p, int dx, int dy){ //translasi sebesar dx dan dy
    Point Tr;
    Tr.x=p.x+dx;
    Tr.y=p.y+dy;
    return Tr;
}


Point pRotasi(Point p, float angle){ /* merotasikan titik p sebesar sudut angle (dalam radian)
 rumus:
    xRot = x*cos(theta) - y*sin(theta)
    yRot = x*sin(theta) + y*cos(theta)
*/  int x;
    int y;
    Point Rot;
    Rot.x=x*cos(angle) - y*sin(angle);
    Rot.y=x*sin(angle) + y*cos(angle);
}
