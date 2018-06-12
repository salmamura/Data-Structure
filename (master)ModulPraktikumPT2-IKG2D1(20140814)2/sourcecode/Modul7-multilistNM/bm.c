#include <stdio.h>
#include "multilist_nm.h"

void createListDosen(ListDosen *LD){
    LD->firstDosen = NULL;

} //create list kosong
adrDosen alokasiDosen(char* kodeX, char* namaX, int gajiX){

    adrDosen p = (adrDosen)malloc(sizeof(dos1));

    if(p!=NULL){
        p->kodeDosen = kodeX;
        p->namaDosen = namaX;
        p->gajiPokok = gajiX;
        p->nextDosen = NULL;
    }
    return p;
}
void insertFirstDosen(ListDosen *LD, adrDosen d){

    if(LD->firstDosen == NULL){
        LD->firstDosen = d;
    }else{
        d->nextDosen = LD->firstDosen;
        LD->firstDosen = d;
    }
}
void insertLastDosen(ListDosen *LD, adrDosen d){

    adrDosen p = LD->firstDosen;

    if(p==NULL){
        insertFirstDosen(LD,d);
    }else{
        while(p->nextDosen != NULL){
            p = p->nextDosen;
        }
        p->nextDosen = d;
    }
}

void createListMK(ListMK *LMK){

    LMK->firstMK = NULL;
} //create list kosong
adrMK alokasiMK(char* kodeX, char* namaX, int sksX){

    adrMK p = (adrMK)malloc(sizeof(mk1));

    if(p!=NULL){
        p->kodeMK = kodeX;
        p->namaMK = namaX;
        p->sks = sksX;
        p->nextMK = NULL;
    }
    return p;
}
void insertFirstMK(ListMK *LMK, adrMK m){

    if(LMK->firstMK == NULL){
        LMK->firstMK = m;
    }else{
        m->nextMK = LMK->firstMK;
        LMK->firstMK = m;
    }
}

void insertLastMK(ListMK *LMK, adrMK m){

    adrMK p;

    if(LMK->firstMK==NULL){
        insertFirstMK(LMK,m);
    }else{
        p = LMK->firstMK;
        while(p->nextMK != NULL){
            p = p->nextMK;
        }
        p->nextMK = m;
    }
}

void createListMKDOS(ListMKDOS *LMKDOS){

    LMKDOS->firstMKDOS = NULL;
} //create list kosong
adrMKDOS alokasiMKDOS(ListDosen LD, ListMK LMK, char kodeDosen[3], char kodeMK[6]){

    adrMKDOS p = (adrMKDOS)malloc(sizeof(mkd1));

    if(p!=NULL){
        p->dosenPengajar = searchDosen(LD,kodeDosen);
        p->matkul = searchMK(LMK,kodeMK);
        p->nextMKDOS = NULL;
    }
    return p;
}
void insertFirstMKDOS(ListMKDOS *LMKDOS, adrMKDOS md){

    if(LMKDOS->firstMKDOS != NULL){
        md->nextMKDOS = LMKDOS->firstMKDOS;
        LMKDOS->firstMKDOS= md;
    }else{
        LMKDOS->firstMKDOS = md;
    }
}
void insertLastMKDOS(ListMKDOS *LMKDOS, adrMKDOS md){

    adrMKDOS p = LMKDOS->firstMKDOS;

    if(p==NULL){
        insertFirstMKDOS(LMKDOS,md);
    }else{
        while(p->nextMKDOS != NULL){
            p = p->nextMKDOS;
        }
        p->nextMKDOS = md;
    }
}


void cetakListMKDOS(ListMKDOS LMKDOS){

    adrMKDOS p;

    if(LMKDOS.firstMKDOS == NULL){
        printf("List kosong\n");
    }else{
        p = LMKDOS.firstMKDOS;
        while(p != NULL){
            printf("kode dosen = %s\n",(p->dosenPengajar)->kodeDosen);
            printf("kode matakuliah = %s\n\n",(p->matkul)->kodeMK);
            p = p->nextMKDOS;
        }
    }
} // mencetak pasangan data kode matakuliah dan kode dosen yang mengajar matakuliah tersebut
boolean searchDosenBool(ListDosen LD, char* kodeX){

    adrDosen p = LD.firstDosen;

    while(p!=NULL){
        if(strcmp(p->kodeDosen,kodeX)==0){
            return true;
        }
        p = p->nextDosen;
    }
    return false;
} // search dosen berdasarkan kode, bila ketemu maka return true
adrDosen searchDosen(ListDosen LD, char* kodeX){

    adrDosen p = LD.firstDosen;

    while(p!=NULL){
        if(strcmp(p->kodeDosen,kodeX)==0){
            return p;
        }
        p = p->nextDosen;
    }
    return p;
}
// searchDosen: search dosen berdasarkan kode, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL
boolean searchMKBool(ListMK LMK, char* kodeX){

    adrMK p = LMK.firstMK;

    while(p!=NULL){
        if(strcmp(p->kodeMK,kodeX)==0){
            return true;
        }
        p = p->nextMK;
    }
    return false;
} // search matakuliah berdasarkan kode, bila ketemu maka return true
adrMK searchMK(ListMK LMK, char* kodeX){

    adrMK p = LMK.firstMK;

    while(p!=NULL){
        if(strcmp(p->kodeMK,kodeX)==0){
            return p;
        }
        p = p->nextMK;
    }
    return p;
}
// searchMK: search matakuliah berdasarkan kode, bila ketemu maka return-lah addressnya, bila tidak ketemu maka return NULL

void cetakMKbyDosen(ListDosen LD, ListMKDOS LMKDOS, char* kodeDosenX){

    adrMKDOS p = LMKDOS.firstMKDOS;

    printf("\nkode dosen = %s\n",kodeDosenX);
    if(p==NULL){
        printf("List kosong\n");
    }else{
        while(p != NULL){
            if(strcmp((p->dosenPengajar)->kodeDosen,kodeDosenX)==0){
                printf("kode matakuliah = %s\n",(p->matkul)->kodeMK);
            }
            p = p->nextMKDOS;
        }
    }
}
// cetakMKbyDosen: mencetak semua kode matakuliah yang pernah/sedang diajar oleh kodedosenX
void cetakDosenbyMK(ListMK LMK, ListMKDOS LMKDOS, char* kodeMKX){

    adrMKDOS p = LMKDOS.firstMKDOS;

    printf("\nkode Matakuliah = %s\n",kodeMKX);
    if(p==NULL){
        printf("List kosong\n");
    }else{
        while(p!=NULL){
            if(strcmp((p->matkul)->kodeMK,kodeMKX)==0){
                printf("kode dosen = %s\n",(p->dosenPengajar)->kodeDosen);
            }
            p = p->nextMKDOS;
        }
    }
}
// cetakDosenbyMK: mencetak semua kode dosen yang pernah/sedang mengajar matakuliah kodeMKX

boolean isRelated(ListDosen LD, char* kodeDosenX, ListMK LMK, char* kodeMKX, ListMKDOS LMKDOS){

    adrMKDOS p = LMKDOS.firstMKDOS;

    while(p!=NULL){
        if(strcmp((p->dosenPengajar)->kodeDosen,kodeDosenX)==0 && strcmp((p->matkul)->kodeMK,kodeMKX)==0){
            return true;
        }
        p = p->nextMKDOS;
    }
    return false;
}
// isRelated: mereturn true bila ada hubungan/relasi antara kodeDosenX tertentu dengan kodeMKX tertentu
// atau dengan kata lain, pernah atau sedang mengajar matakuliah tsb

int totalSKSDosen(ListDosen LD, char* kodeDosenX, ListMKDOS LMKDOS){

    adrMKDOS p = LMKDOS.firstMKDOS;
    int total = 0;

    while(p!=NULL){
        if(strcmp((p->dosenPengajar)->kodeDosen,kodeDosenX)==0){
            total = total + (p->matkul)->sks;
        }
        p = p->nextMKDOS;
    }
    return total;
}
// totalSKSDosen: mereturn total SKS dari semua matakuliah yang pernah/sedang diajar oleh kodeDosenX


