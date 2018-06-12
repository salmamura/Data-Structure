/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- The C++ Standard Library (Nicolai M. Josuttis, Addison Wesley), page 388 (Chapter 10.2 Queue)
  http://10.3.26.47/perpustakaan/C,C++/TheC++StandardLibrary.pdf
*/


#include <iostream>
#include <queue>
#include "Mahasiswa.cpp"
using namespace std;

int main()
{
    queue<Mahasiswa> q; // create an empty queue
    int i;
	cout << "Mengisi queue (push) dengan data mahasiswa secara berurut (insertLast).\n";
    Mahasiswa m1(11810000,"Doraemon");
    Mahasiswa m2(11810001,"Nobita");
    Mahasiswa m3(11810002,"Shizuka");
    q.push(m1);
    q.push(m2);
    q.push(m3);

    cout << "Menampilkan isi queue dengan cara melakukan pop (deleteFirst) berulang-ulang: \n";
    while(!q.empty()){
        q.front().printInfo();
        q.pop();
    }


    return 0;
}
