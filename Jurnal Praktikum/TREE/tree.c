#include "tree.h"
void makeTree(BinTree *p, int nimX, char* namaX, int nilaiX, address leftX, address rightX){
    *p=(address)malloc(sizeof(m1));
    if(*p!=NULL){
        (*p)->nim=nimX;
        (*p)->nama=namaX;
        (*p)->nilai=nilaiX;
        (*p)->left=leftX;
        (*p)->right=rightX;
    }
} //create root untuk pohon
void insertNode(BinTree *p, int nimX, char* namaX, int nilaiX){
    if(*p==NULL)
        makeTree(p,nimX,namaX,nilaiX,NULL,NULL);
    else{
        if((*p)->nim==nimX)
            printf("NIM sudah diinputkan\n");
        else{
            if(nimX>(*p)->nim)
                insertNode(&((*p)->right),nimX,namaX,nilaiX);
            else
                insertNode(&((*p)->left),nimX,namaX,nilaiX);
        }
    }
} // insert node terurut (cek agar NIM yang masuk ke tree tidak double)
void cetakPreOrder(BinTree p){
    if(p!=NULL){
        printf("Nama: %s\nNIM: %d\nNilai: %d\n\n",p->nama,p->nim,p->nilai);
        cetakPreOrder(p->left);
        cetakPreOrder(p->right);
    }
}
void cetakInOrder(BinTree p){
    if(p!=NULL){
        cetakInOrder(p->left);
        printf("Nama: %s\nNIM: %d\nNilai: %d\n\n",p->nama,p->nim,p->nilai);
        cetakInOrder(p->right);
    }
}
void cetakPostOrder(BinTree p){
    if(p!=NULL){
        cetakPostOrder(p->left);
        cetakPostOrder(p->right);
        printf("Nama: %s\nNIM: %d\nNilai: %d\n\n",p->nama,p->nim,p->nilai);
    }
}
boolean search(BinTree p, int nimX){
    if(p==NULL)
        return 0;
    else{
        if(nimX==p->nim)
            return 1;
        else{
            if(nimX>p->nim)
                search(p->right,nimX);
            else
                search(p->left,nimX);

        }
    }
}
int nbNode(BinTree p){
    return (p==NULL)?0:1+nbNode(p->left)+nbNode(p->right);
}
int sumNilai(BinTree p){
    return (p==NULL)?0:p->nilai+sumNilai(p->left)+sumNilai(p->right);
}
int maxNilai(BinTree p){
    if(p->left!=NULL && p->right!=NULL){
        int kiri=maxNilai(p->left);
        int kanan=maxNilai(p->right);
        return (kiri>kanan)?((kiri>p->nilai)?kiri:p->nilai):((kanan>p->nilai)?kanan:p->nilai);
    }else{
        if(p->left!=NULL){
            int kiri=maxNilai(p->left);
            return kiri>p->nilai?kiri:p->nilai;
        }
        if(p->right!=NULL){
            int kanan=maxNilai(p->right);
            return kanan>p->nilai?kanan:maxNilai(p->right);
        }
        return p->nilai;
    }
}
int minNilai(BinTree p){
    if(p->left!=NULL && p->right!=NULL){
        int kiri=minNilai(p->left);
        int kanan=minNilai(p->right);
        return (kiri<kanan)?((kiri<p->nilai)?kiri:p->nilai):((kanan<p->nilai)?kanan:p->nilai);
    }else{
        if(p->left!=NULL){
            int kiri=minNilai(p->left);
            return kiri<p->nilai?kiri:p->nilai;
        }
        if(p->right!=NULL){
            int kanan=minNilai(p->right);
            return kanan<p->nilai?kanan:p->nilai;
        }
        return p->nilai;
    }
}
int nbDaun(BinTree p){
    return p==NULL?0:((p->left==NULL && p->right==NULL)?1:nbDaun(p->left)+nbDaun(p->right));
}
int nbParent(BinTree p){
    return (p==NULL || (p->left==NULL && p->right==NULL))?0:nbParent(p->left)+nbParent(p->right)+1;
}
int levelOfNode(BinTree p, int nimX){
    return search(p,nimX)?(nimX==p->nim?0:((nimX>p->nim)?1+levelOfNode(p->right,nimX):1+levelOfNode(p->left,nimX))):-1;
} // nimX ada di level berapa (level root = 0, dst...)
int depthOfTree(BinTree p){
    if(p==NULL){
        return -1;
    }else{
        int kiri=depthOfTree(p->left);
        int kanan=depthOfTree(p->right);
        return (kiri>kanan)?kiri+1:kanan+1;
    }
}
void reverseTree(BinTree *p){
    if(*p!=NULL){
        address q = (*p)->left;
        (*p)->left = (*p)->right;
        (*p)->right = q;
        reverseTree(&(*p)->left);
        reverseTree(&(*p)->right);
    }
}
void cetakOnLevel(BinTree p, int level){
    if(level>0){
        if(p->left!=NULL)
            cetakOnLevel(p->left,level-1);
        if(p->right!=NULL)
            cetakOnLevel(p->right,level-1);
    }else
        if(!level)
            printf("%s ",p->nama);
}//mencetak semua nama/nim yang berada di level tertentu ( level root = 0 )
int maxNilaiOnLevel(BinTree p,int level){
    int kiri,kanan;
    if(level>0 && p!=NULL){
        if(p->left!=NULL && p->right!=NULL){
            kiri = maxNilaiOnLevel(p->left,level-1);
            kanan = maxNilaiOnLevel(p->right,level-1);
            return kiri>kanan?kiri:kanan;
        }
        if(p->left!=NULL || p->right!=NULL)
            return (p->left!=NULL)?maxNilaiOnLevel(p->left,level-1):maxNilaiOnLevel(p->right,level-1);
    }
    return !level?p->nilai:-1;
}
int minNilaiOnLevel(BinTree p,int level){
    int kiri,kanan;
    if(level>0 && p!=NULL){
        if(p->left!=NULL && p->right!=NULL){
            kiri = minNilaiOnLevel(p->left,level-1);
            kanan = minNilaiOnLevel(p->right,level-1);
            return kiri<kanan?kiri:kanan;
        }
        if(p->left!=NULL || p->right!=NULL)
            return (p->left!=NULL)?minNilaiOnLevel(p->left,level-1):minNilaiOnLevel(p->right,level-1);
    }
    return !level?p->nilai:101;
}
