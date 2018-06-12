#include "multilist_nm.h"

void createListDosen(ListDosen *LD){
    (*LD).firstDosen=NULL;
} //create list kosong

adrDosen alokasiDosen(char* kodeX, char* namaX, int gajiX){
    adrDosen d=(adrDosen)malloc(sizeof(dos1));
    if (d!=NULL){
        d->kodeDosen=kodeX;
        d->namaDosen=namaX;
        d->gajiPokok=gajiX;
        d->nextDosen=NULL;
    }
    return d;
}
void insertFirstDosen(ListDosen *LD, adrDosen d){
    d->nextDosen=(*LD).firstDosen;
    (*LD).firstDosen=d;
}
void insertLastDosen(ListDosen *LD, adrDosen d){
    adrDosen last=(*LD).firstDosen;
    while(last->nextDosen!=NULL){
        last=last->nextDosen;
    }
    last->nextDosen=d;
}

void createListMK(ListMK *LMK){
    (*LMK).firstMK=NULL;
} //create list kosong


adrMK alokasiMK(char* kodeX, char* namaX, int sksX){
    adrMK m= (adrMK)malloc(sizeof(mk1));
    if(m!=NULL){
        m->kodeMK=kodeX;
        m->namaMK=namaX;
        m->sks=sksX;
        m->nextMK=NULL;
    }
    return m;
}
void insertFirstMK(ListMK *LMK, adrMK m){
    m->nextMK=(*LMK).firstMK;
    (*LMK).firstMK=m;
}
void insertLastMK(ListMK *LMK, adrMK m){
    adrMK last=(*LMK).firstMK;
    while(last->nextMK!=NULL){
        last=last->nextMK;
    }
    last->nextMK=m;
}

void createListMKDOS(ListMKDOS *LMKDOS){
    (*LMKDOS).firstMKDOS=NULL;
} //create list kosong
adrMKDOS alokasiMKDOS(ListDosen LD, ListMK LMK, char kodeDosen[3], char kodeMK[6]){
    adrMKDOS n = (adrMKDOS)malloc(sizeof(mkd1));
    if(n!=NULL){
        n->dosenPengajar=searchDosen(LD,kodeDosen);
        n->matkul=searchMK(LMK,kodeMK);
        n->nextMKDOS=NULL;
    }
    return n;
}

void insertFirstMKDOS(ListMKDOS *LMKDOS, adrMKDOS md){
    md->nextMKDOS=(*LMKDOS).firstMKDOS;
    (*LMKDOS).firstMKDOS=md;
}
void insertLastMKDOS(ListMKDOS *LMKDOS, adrMKDOS md){
    adrMKDOS last=(*LMKDOS).firstMKDOS;
    while(last->nextMKDOS!=NULL){
        last=last->nextMKDOS;
    }
    last->nextMKDOS=md;
}
void cetakListMKDOS(ListMKDOS LMKDOS){
    adrMKDOS n=(LMKDOS).firstMKDOS;
    if(n==NULL){
        printf("List Kosong\n");
    }else{
        while(n!=NULL){
                printf("Kode Mata Kuliah : %s\n",n->matkul->kodeMK);
                printf("Kode Dosen: %s \n\n",n->dosenPengajar->kodeDosen);
                n=n->nextMKDOS;
        }
    }
} // mencetak pasangan data kode matakuliah dan kode dosen yang mengajar matakuliah tersebut
boolean searchDosenBool(ListDosen LD, char* kodeX){ // search dosen berdasarkan kode, bila ketemu maka return true
    adrDosen d=(LD).firstDosen;
    while((d!=NULL)&&(kodeX!=d->kodeDosen)){
        d=d->nextDosen;
    }
    if(d==NULL){
        return false;
    }else{
        return true;
    }
}
adrDosen searchDosen(ListDosen LD, char* kodeX){
    adrDosen d=(LD).firstDosen;
    while((d!=NULL)&&(kodeX!=d->kodeDosen)){
        d=d->nextDosen;
    }
    return d;
}
// searchDosen: search dosen berdasarkan kode, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
boolean searchMKBool(ListMK LMK, char* kodeX){ // search matakuliah berdasarkan kode, bila ketemu maka return true
    adrMK n=(LMK).firstMK;
    while((n!=NULL)&&(kodeX!=n->kodeMK)){
        n=n->nextMK;
    }
    if(n==NULL){
        return false;
    }else{
        return true;
    }
}
adrMK searchMK(ListMK LMK, char* kodeX){
// searchMK: search matakuliah berdasarkan kode, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
    adrMK n=(LMK).firstMK;
    while((n!=NULL)&&(kodeX!=n->kodeMK)){
        n=n->nextMK;
    }
    if(n==NULL){
        return NULL;
    }else{
        return n;
    }
}
void cetakMKbyDosen(ListDosen LD, ListMKDOS LMKDOS, char* kodeDosenX){
    adrMKDOS n=(LMKDOS).firstMKDOS;
    if(n==NULL){
        printf("List Kosong\n");
    }else{
        while(n!=NULL){
                if(kodeDosenX=(n->dosenPengajar)->kodeDosen){
                    printf("Kode Mata Kuliah: %s \n",n->matkul->kodeMK);
                }
                n=n->nextMKDOS;
        }
    }
}

// cetakMKbyDosen: mencetak semua kode matakuliah yang pernah/sedang diajar oleh kodedosenX
void cetakDosenbyMK(ListMK LMK, ListMKDOS LMKDOS, char* kodeMKX){
    adrMKDOS n=(LMKDOS).firstMKDOS;
    if(n==NULL){
        printf("List Kosong\n");
    }else{
        while(n!=NULL){
                if(kodeMKX=(n->matkul)->kodeMK){
                    printf("Kode Dosen: %s \n",(n->dosenPengajar)->kodeDosen);
                }
                n=n->nextMKDOS;
        }
    }
}

// cetakDosenbyMK: mencetak semua kode dosen yang pernah/sedang mengajar matakuliah kodeMKX

boolean isRelated(ListDosen LD, char* kodeDosenX, ListMK LMK, char* kodeMKX, ListMKDOS LMKDOS){
    adrMKDOS n=(LMKDOS).firstMKDOS;
    while((n!=NULL)&&(kodeDosenX==(n->matkul)->kodeMK)&&(kodeDosenX==(n->dosenPengajar)->kodeDosen)){
        n=n->nextMKDOS;
    }
    if(n==NULL){
        return false;
    }else{
        return true;
    }
}
// isRelated: mereturn true bila ada hubungan/relasi antara kodeDosenX tertentu dengan kodeMKX tertentu
// atau dengan kata lain, pernah atau sedang mengajar matakuliah tsb

int totalSKSDosen(ListDosen LD, char* kodeDosenX, ListMKDOS LMKDOS){
// totalSKSDosen: mereturn total SKS dari semua matakuliah yang pernah/sedang diajar oleh kodeDosenX
    adrMKDOS n=(LMKDOS).firstMKDOS;
    int total=0;
    while(n!=NULL){
        if(kodeDosenX==(n->dosenPengajar)->kodeDosen){
            total=total+(n->matkul)->sks;
        }
        n=n->nextMKDOS;
    }
    return total;
}
