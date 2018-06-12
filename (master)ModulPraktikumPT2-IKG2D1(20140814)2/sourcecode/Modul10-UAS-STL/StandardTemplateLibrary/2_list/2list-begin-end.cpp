/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 650
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> myList; // create an empty list
    int i;
	cout << "Mengisi list dengan integer kelipatan 5.\n";
    for(i=0; i<10; i++){
        myList.push_back(i*5);
    }
    cout << "Ukuran list = " << myList.size() << "\n";
    cout << "Menampilkan isi list secara berurut dari depan: ";
    list<int>::iterator p = myList.begin();
    while(p != myList.end()) {
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";

    cout << "Menampilkan isi list secara terbalik (dari belakang): ";
    p = myList.end();
    while(p != myList.begin()) {
        p--;
        cout << *p << " ";
    }
    return 0;
}
