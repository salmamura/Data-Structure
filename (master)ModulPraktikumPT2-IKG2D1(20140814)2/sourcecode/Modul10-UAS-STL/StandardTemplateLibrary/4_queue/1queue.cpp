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
using namespace std;

int main()
{
    queue<int> q; // create an empty queue
    int i;
	cout << "Mengisi queue (push) dengan integer secara berurut (insertLast).\n";
    for(i=0;i<10;i++){
        q.push(i);
    }
    cout << "HEAD = " << q.front() << " ";
    cout << "TAIL = " << q.back() << " ";
	
    cout << "Menampilkan isi queue dengan cara melakukan pop berulang-ulang (deleteFirst): ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }


    return 0;
}
