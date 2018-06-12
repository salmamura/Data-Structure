
#include <stdio.h>

#include "bpoint.c"

int main()
{
    Point pa = makePoint(2,1);

    printf("x,y = %.2f,%.2f\n",pa.x,pa.y);


	printf("jarakOrigin = %f\n",jarakOrigin(pa));

	Point pe = pMirrorSbX(pa);
	Point pf = pMirrorSbY(pa);
	Point pg = pTranslasi(pa,20,10);
	Point ph = pRotasi(pa,(0.5*3.1415));

	printf("hasil pencerminan terhadap sumbu x = %.2f, %.2f\n",pe.x,pe.y);
	printf("hasil pencerminan terhadap sumbu y = %.2f, %.2f\n",pf.x,pf.y);
	printf("hasil translasi = %.2f, %.2f\n",pg.x,pg.y);
	printf("hasil rotasi dengan sudut 90 derajat = %.2f, %.2f\n",ph.x,ph.y);




    return 0;
}
