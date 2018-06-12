/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 640-641
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <vector>
#include <cctype>

using namespace std;
int main()
{
    vector<int> v(10);  // vector mirip seperti tipe data array, namun vector bersifat dinamis/fleksibel (ukurannya bisa mengembang/menyusut)
    vector<int>::iterator p;  // p dapat dianggap sebagai pointer yang menunjuk ke alamat vector

    cout << "Ukuran vector (array dynamic) = " << v.size() << "\n";
    cout << "Mengisi vector dengan integer kelipatan 2.\n";
    p = v.begin(); // mengarahkan pointer p ke alamat elemen pertama vector
    int i=0;
    while(p != v.end()){
        *p = i*2;
        p++;
        i++;
    }

    cout << "Menampilkan isi vector:\n";
    p = v.begin();
    while(p != v.end()){
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";



    cout << "Memperbesar ukuran vector\n";
    cout << "Mengisi vector dengan integer kelipatan 3.\n";
    for(i=0; i<10; i++){
        v.push_back(i*3);
    }
    cout << "Ukuran vector sekarang = " << v.size() << "\n";
    cout << "Isi vector sekarang:\n";
    p = v.begin();
    while(p != v.end()){
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";

    return 0;
}
