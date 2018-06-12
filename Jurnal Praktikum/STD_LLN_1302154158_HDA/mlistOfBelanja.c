#include <stdio.h>
#include "listOfBelanja.c"

int main()
{
	ListOfBelanja li;
	createListBel(&li);

	address p0 = alokasi("sabun",5000,3);
	address p1 = alokasi("sendal",10000,2);
	address p2 = alokasi("tas",50000,1);
	address p3 = alokasi("buku",3000,7);
	address p4 = alokasi("pulpen",2000,4);
	insertFirstBel(&li,p0);
	insertLastBel(&li,p1);
	insertLastBel(&li,p2);
	insertLastBel(&li,p3);
	insertLastBel(&li,p4);
	prosesSubTotal(&li);
	cetakListBel(li);

	printf("\nalamat item di memori : %p\n",searchBel(li,"tas"));

	printf("nbElmt = %i\n",nbElmt(li));
	printf("max = %i\n",maxHargaSatuan(li));
	printf("min = %i\n",minHargaSatuan(li));
	printf("total harga = %i\n",totalHarga(li));
	printf("avg = %f\n",avgHargaSatuan(li));


	deleteFirstBel(&li);
	deleteLastBel(&li);
	cetakListBel(li);

    return 0;
}
