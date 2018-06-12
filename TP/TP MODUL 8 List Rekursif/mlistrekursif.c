//1302154158_SALMA

#include "listrekursif.c"

int main(){
    ListOfHotel lh;


    makeListBill(&lh,   "Szczesny", "Senin", "Rabu", 350000);
    insertLastBill(&lh, "Blaszczykowski", "Senin", "Rabu", 350000);
    insertLastBill(&lh, "Matuszczyk", "Selasa", "Sabtu", 675000);
    insertLastBill(&lh, "Jedrzejczyk", "Minggu", "Senin", 200000);
    insertLastBill(&lh, "Chygrynsky", "Rabu", "Jumat", 400000);

    cetakList(lh);

    printf("\n[0=No,1=Yes] search(lk,Blaszczkowski) = %i\n\n", cariOrang(lh, "Blaszczkowski"));
    printf("nbElmt  = %i\n", nbElmt(lh));
    printf("maxBill = %i\n", maxBill(lh));
    printf("minBill = %i\n", minBill(lh));
    printf("avgBill = %f\n", avgBill(lh));
    printf("sumBill = %i\n", sumBill(lh));

    return 0;
}
