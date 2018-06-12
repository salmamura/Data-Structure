/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 648
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <list>
using namespace std;

void cetakList(list<int> listX){
    cout << "Menampilkan isi list: ";
    list<int>::iterator px = listX.begin();
    while(px != listX.end()) {
        cout << *px << " ";
        px++;
    }
    cout << "\n\n";
}

int main()
{
    list<int> myList; // create an empty list
    int i;
	cout << "Mengisi list dengan integer kelipatan 5.\n";
    for(i=0; i<10; i++){
        myList.push_back(i*5);
    }
    cout << "Ukuran list = " << myList.size() << "\n";
    cetakList(myList);

	cout << "Mengubah nilai elemen list (ditambah 100).\n";
    list<int>::iterator p = myList.begin();
    p = myList.begin();
    while(p != myList.end()) {
        *p = *p + 100;
        p++;
    }
    cetakList(myList);

    return 0;
}
