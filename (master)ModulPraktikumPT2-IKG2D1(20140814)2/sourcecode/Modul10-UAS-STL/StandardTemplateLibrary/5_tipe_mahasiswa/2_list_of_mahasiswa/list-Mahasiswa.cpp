/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 655-657
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <list>
#include <cstdlib>
#include "Mahasiswa.cpp"

using namespace std;


void cetakList(list<Mahasiswa> listX){
    cout << "Menampilkan isi list:\n";
    list<Mahasiswa>::iterator px = listX.begin();
    while(px != listX.end()) {
        (*px).printInfo();
        px++;
    }
    cout << "\n\n";
}

int main(){
    list<Mahasiswa> myList; // create an empty list
    int i;
    cout << "Mengisi list dengan data mahasiswa, menggunakan insert last (push_back).\n";
    Mahasiswa m1(11810000,"Doraemon");
    Mahasiswa m2(11810001,"Nobita");
    Mahasiswa m3(11810002,"Shizuka");
    myList.push_back(m1);
    myList.push_back(m2);
    myList.push_back(m3);

    cetakList(myList);

    return 0;
}
