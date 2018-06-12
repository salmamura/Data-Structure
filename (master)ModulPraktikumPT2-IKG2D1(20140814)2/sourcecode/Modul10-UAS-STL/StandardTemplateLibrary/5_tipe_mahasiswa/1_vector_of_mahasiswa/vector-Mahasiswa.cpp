/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 643-645
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include "Mahasiswa.cpp"

using namespace std;

void cetakVector(vector<Mahasiswa> vx){
    cout << "Menampilkan isi vector:\n";
    int i;
    for(i=0;i<vx.size();i++){
        vx[i].printInfo();
    }
    cout << "\n\n";
}


int main(){
    vector<Mahasiswa> vMhs(5);

    cout << "Ukuran vector (array dynamic) = " << vMhs.size() << "\n";
    cout << "Mengisi vector dengan data mahasiswa.\n";
    Mahasiswa m1(11810000,"Doraemon");
    Mahasiswa m2(11810001,"Nobita");
    Mahasiswa m3(11810002,"Shizuka");
    vMhs[0] = m1;
    vMhs[1] = m2;
    vMhs[2] = m3;

	cetakVector(vMhs);

    return 0;
}
