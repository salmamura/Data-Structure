#include <stdio.h>
#include "tree.c"

int main()
{
    int skill = 0;
	BinTree bt=NULL;
	makeTree(&bt,1302141175,"m5",5,NULL,NULL);
	insertNode(&bt,1302141178,"m8",8);
	insertNode(&bt,1302141172,"m2",2);
	insertNode(&bt,1302141179,"m9",9);
	insertNode(&bt,1302141174,"m4",4);
	insertNode(&bt,1302141171,"m1",1);
	insertNode(&bt,1302141173,"m3",3);
    insertNode(&bt,1302141176,"m6",6);
    insertNode(&bt,1302141177,"m7",7);
    skill = 30;
    //* tambahkan '/' pada awal baris ini (menjadi '//*') jika dapat mengerjakan code selanjutnya
	cetakPreOrder(bt);
	cetakInOrder(bt);
	cetakPostOrder(bt);
	skill = 40;
    //* tambahkan '/' pada awal baris ini (menjadi '//*') jika dapat mengerjakan code selanjutnya
	printf("[0=No,1=Yes] search(bt,asprak kece) = %i\n",search(bt,1302141173));
	printf("nbNode = %i\n",nbNode(bt));
	printf("sum = %i\n",sumNilai(bt));
	skill = 50;
    //* tambahkan '/' pada awal baris ini (menjadi '//*') jika dapat mengerjakan code selanjutnya
	printf("max = %i\n",maxNilai(bt));
	printf("min = %i\n",minNilai(bt));
	skill = 60;
    //* tambahkan '/' pada awal baris ini (menjadi '//*') jika dapat mengerjakan code selanjutnya
	printf("nbDaun = %i\n",nbDaun(bt));
	printf("nbParent = %i\n",nbParent(bt));
	printf("levelOfNode = %i\n",levelOfNode(bt,1302141173));
	printf("depthOfTree = %i\n\n\n",depthOfTree(bt));
	skill = 70;
    //* tambahkan '/' pada awal baris ini (menjadi '//*') jika dapat mengerjakan code selanjutnya
    int i = -1;
    while (i++<depthOfTree(bt)){
        printf("Level %d: ",i); cetakOnLevel(bt,i); puts("");
    }
    skill = 80;
    //* tambahkan '/' pada awal baris ini (menjadi '//*') jika dapat mengerjakan code selanjutnya
    i=-1;
    while (i++<depthOfTree(bt)){
        printf("MaxNilaiOnLevel %d: %d\n",i,maxNilaiOnLevel(bt,i));
        printf("MinNilaiOnLevel %d: %d\n",i,minNilaiOnLevel(bt,i));
    }
    skill = 90;
    //* tambahkan '/' pada awal baris ini (menjadi '//*') jika dapat mengerjakan code selanjutnya
    reverseTree(&bt);
    cetakInOrder(bt);
    skill = 100;
    /**/
    return skill;
}

