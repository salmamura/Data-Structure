#include <stdio.h>
#include "point.c"

int main(){
        Point pa = makePoint(2,1);
	tulisPoint(pa);

    	Point pb = makePoint(8,9);
	tulisPoint(pb);

	Point pc = pTambah(pa,pb);
	Point pd = pKurang(pa,pb);
	tulisPoint(pc);
	tulisPoint(pd);

	printf("\n\n[0=No,1=Yes] pEqual(pa,pb) = %i\n",pEqual(pa,pb));
	printf("[0=No,1=Yes] pNotEqual(pa,pb) = %i\n",pNotEqual(pa,pb));
	printf("[0=No,1=Yes] pLessThan(pa,pb) = %i\n",pLessThan(pa,pb));
	printf("[0=No,1=Yes] pGreaterThan(pa,pb) = %i\n",pGreatherThan(pa,pb));
	printf("[0=No,1=Yes] isOrigin(pa) = %i\n",isOrigin(pa));

	printf("\n\nkuadran(pa) = %i\n",kuadran(pa));
	printf("kuadran(pb) = %i\n",kuadran(pb));

	printf("\n\njarakOrigin(pa) = %f\n",jarakOrigin(pa));
	printf("jarakOrigin(pb) = %f\n",jarakOrigin(pb));

	Point pe = pMirrorSbX(pa);
	Point pf = pMirrorSbY(pa);
	Point pg = pTranslasi(pa,20,10);
	Point ph = pRotasi(pa,(0.5*3.14));
	tulisPoint(pe);
	tulisPoint(pf);
	tulisPoint(pg);
	tulisPoint(ph);

   	 return 0;
}
