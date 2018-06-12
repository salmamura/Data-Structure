/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 653-654
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <list>
#include <cstdlib>

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

int main(){
    list<int> myList; // create an empty list
    int i;
	cout << "Mengisi myList dengan integer kelipatan 2.\n";
    for(i=0; i<10; i++){
        myList.push_back(i*2);
    }
    cout << "Ukuran list = " << myList.size() << "\n";
	cetakList(myList);

    list<int> yourList; // create an empty list
	cout << "Mengisi yourList dengan integer kelipatan 5.\n";
    for(i=0; i<5; i++){
        yourList.push_back(i*5);
    }
    cout << "Ukuran list = " << yourList.size() << "\n";
	cetakList(yourList);


	cout << "Menggabungkan myList dan yourList (akan terurut secara otomatis).\n";
	myList.merge(yourList);
	cetakList(myList);
    return 0;
}
