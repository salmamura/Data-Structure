/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.02.14
Objective: Untuk digunakan dalam praktikum perkuliahan Pemrograman Terstruktur II
*/

#include <stdio.h>
#include "tree.h"

int main()
{
	BinTree bt;
	makeTree(&bt,118129990,"Doraemon",65,NULL,NULL);
	insertNode(&bt,118129991,"Nobita",77);
	insertNode(&bt,118129992,"Shizuka",60);
	insertNode(&bt,118129993,"Upin",80);
	insertNode(&bt,118129994,"Ipin",70);

	cetakPreOrder(bt);
	cetakInOrder(bt);
	cetakPostOrder(bt);

	printf("[0=No,1=Yes] search(lr,118129992) = %i\n",search(bt,118129992));
	printf("nbNode = %i\n",nbNode(bt));
	printf("sum = %i\n",sumNilai(bt));
	printf("max = %i\n",maxNilai(bt));
	printf("min = %i\n",minNilai(bt));

	printf("nbDaun = %i\n",nbDaun(bt));
	printf("nbParent = %i\n",nbParent(bt));

	printf("levelOfNode = %i\n",levelOfNode(bt,118129992));
	printf("depthOfTree = %i\n",depthOfTree(bt));

    return 0;
}
