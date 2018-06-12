#include"tree.h"
void makeTree(BinTree *p, int nimX, char* namaX, int nilaiX, address leftX, address rightX){ //create root untuk pohon
    address q=(address)malloc(sizeof(m1));
    if(q!=NULL){
        q->nim=nimX;
        q->nama=namaX;
        q->nilai=nilaiX;
        q->left=leftX;
        q->right=rightX;
    }
    (*p)=q;
}
void insertNode(BinTree *p, int nimX, char* namaX, int nilaiX){// insert node terurut (cek agar NIM yang masuk ke tree tidak double)
    if((*p)==NULL){
        makeTree(&(*p),nimX,namaX,nilaiX,NULL,NULL);
    }else {
        if((*p)->nim==nimX){
            printf("NIM sudah tersedia\n");
        }else if(nimX>(*p)->nim){
            insertNode(&(*p)->right,nimX,namaX,nilaiX);
        }else{
            insertNode(&(*p)->left,nimX,namaX,nilaiX);
        }
    }
}

void cetakPreOrder(BinTree p){
    if(p!=NULL){
        printf("NIM : %d\n",p->nim);
        printf("Nama : %s\n",p->nama);
        printf("Nilai : %d\n\n",p->nilai);
        cetakPreOrder(p->left);
        cetakPreOrder(p->right);
    }
}
void cetakInOrder(BinTree p){
    if(p!=NULL){
        cetakInOrder(p->left);
        printf("NIM : %d\n",p->nim);
        printf("Nama : %s\n",p->nama);
        printf("Nilai : %d\n\n",p->nilai);
        cetakInOrder(p->right);
    }
}
void cetakPostOrder(BinTree p){
     if(p!=NULL){
        cetakPostOrder(p->left);
        cetakPostOrder(p->right);
        printf("NIM : %d\n",p->nim);
        printf("Nama : %s\n",p->nama);
        printf("Nilai : %d\n\n",p->nilai);
    }
}

boolean search(BinTree p, int nimX){
    if(p==NULL){
       return false;
        }else{
            if(p->nim==nimX){
                return true;
            }else{
                if(nimX > p->nim){
                    search(p->right,nimX);
                }else{
                    search(p->left,nimX);
                    }
            }
        }
    }

int nbNode(BinTree p){ //banyaknya node
    if(p==NULL){
        return 0;
    }else{
        return 1+nbNode(p->left)+nbNode(p->right);
    }
}

int sumNilai(BinTree p){ //Penjumlahan nilai semua node
    if(p==NULL){
        return 0;
    }else{
        return p->nilai+sumNilai(p->left)+sumNilai(p->right);
    }
}
int maxNilai(BinTree p){ //untuk semua rentang nilai -tak hingga sampai tak hingga
    int kiri,kanan;
    if(p->left==NULL || p->right==NULL){
        return p->nilai;
    }else{
        kiri=maxNilai(p->left);
        kanan=maxNilai(p->right);
        if(kiri>kanan){
            if(kiri > p->nilai){
                return kiri;
            }else{
                return p->nilai;
            }
        }else{
            if(kanan > p->nilai){
                return kanan;
            }else{
                return p->nilai;
            }
        }
    }
}
int minNilai(BinTree p){ //untuk semua rentang nilai -tak hingga sampai tak hingga
    int kiri,kanan;
    if(p->left==NULL || p->right==NULL){
        return p->nilai;
    }else{
        kiri=minNilai(p->left);
        kanan=minNilai(p->right);
        if(kiri < kanan){
            if(kiri > p->nilai){
                return kiri;
            }else{
                return p->nilai;
            }
        }else{
            if(kanan < p->nilai){
                return kanan;
            }else{
                return p->nilai;
            }
        }
    }
}
int nbDaun(BinTree p){ //Daun = tidak memiliki cabang
    if(p==NULL){
        return 0;
    }else{
        if(p->left==NULL && p->right==NULL){
            return 1;
        }else{
            return nbDaun(p->right)+nbDaun(p->left);
        }
    }
}

int nbParent(BinTree p){ //Parent = memiliki cabang
    if(p==NULL){
        return 0;
    }else{
        if(p->left==NULL && p->right==NULL){
            return 0;
        }else{
            return nbParent(p->right)+nbParent(p->left)+1;
        }
    }
}

int levelOfNode(BinTree p, int nimX){
    if (!search (p,nimX)){
        return -1;
    }else{
        if(p->nim==nimX){
            return 0;
        }else{
            if(nimX>p->nim){
                return 1+levelOfNode(p->right,nimX);
            }else{
                return 1+levelOfNode(p->left,nimX);
            }

        }
    }
}

// nimX ada di level berapa (level root = 0, dst...)
// nimX dijamin ada di tree
int depthOfTree(BinTree p){ // kedalaman maksimal tree
   if(p==NULL){
        return -1;
   }else{
        if(p->left==NULL && p->right==NULL){
            return 0;
        }else{
            return 1+depthOfTree(p->left)+depthOfTree(p->right);
        }
   }
}

void reverseTree(BinTree *p){
    address q=(*p)->left;
    (*p)->left=(*p)->right;
    (*p)->right=q;
    reverseTree(&(*p)->left);
    reverseTree(&(*p)->right);
}
//lihat contoh berikut
/*
      Tampak Depan            Tampak Belakang
           5                        5
         /   \                    /   \
        2     8                  8     2
       / \   / \    MENJADI     / \   / \
      1   4 6   9              9   6 4   1
         /   \                    /   \
        3     7                  7     3
*/
void cetakOnLevel(BinTree p, int level){//mencetak semua nama/nim yang berada di level tertentu ( level root = 0 )
    if(level==0){
        printf("\nNIM : %d\n",p->nim);
        printf("Nama : %s\n",p->nama);
        printf("Nilai : %d\n",p->nilai);
    }else{
        if(p!=NULL){
            if(p->left!=NULL){
                cetakOnLevel(p->left,level-1);
            }
            if(p->right!=NULL){
                    cetakOnLevel(p->right,level-1);
                }
            }
        }
    }
int maxNilaiOnLevel(BinTree p,int level){ //mengembalikan nilai max pada level tertentu, jika tidak terdapat node di level tersebut return -1
    if(p==NULL){
        return -1;
    }
    int kiri,kanan;
    if(level==0){
        return p->nilai;

    }
}
int minNilaiOnLevel(BinTree p,int level); //mengembalikan nilai max pada level tertentu, jika tidak terdapat node di level tersebut return 101

