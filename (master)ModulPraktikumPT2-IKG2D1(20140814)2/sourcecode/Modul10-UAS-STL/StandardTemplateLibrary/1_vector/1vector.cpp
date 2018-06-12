/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 638-639
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <vector>
#include <cctype>

using namespace std;
int main()
{
    vector<int> v(10);  // vector mirip seperti tipe data array, namun vector bersifat dinamis/fleksibel (ukurannya bisa mengembang/menyusut)
    int i;

    cout << "Ukuran vector (array dynamic) = " << v.size() << "\n";
    cout << "Mengisi vector dengan integer kelipatan 2.\n";
    for(i=0;i<10;i++){
        v[i] = i*2;
    }
    cout << "Menampilkan isi vector:\n";
    for(i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";
	
	
    cout << "Memperbesar ukuran vector\n";
    cout << "Mengisi vector dengan integer kelipatan 3.\n";
    for(i=0;i<10;i++){
        v.push_back(i*3);
    }
    cout << "Ukuran vector sekarang = " << v.size() << "\n";
    cout << "Isi vector sekarang:\n";
    for(i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n\n";

    return 0;
}
