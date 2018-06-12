/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 641-642
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void cetakVector(vector<int> vx){
    cout << "Menampilkan isi vector:\n";
    vector<int>::iterator px = vx.begin();
    while(px != vx.end()){
        cout << *px << " ";
        px++;
    }
    cout << "\n\n";
}


int main(){
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
	cetakVector(v);


    cout << "Meng-insert data ke vector\n";
    p = v.begin(); // p menunjuk ke elemen ke-0 vector
    p = p+2; // sekarang p menunjuk ke elemen ke-2 vector
    v.insert(p,5,99); // menyisipkan 5 buah integer bernilai 99, disisipkan di vector elemen ke-2 hingga ke-6
    cout << "Ukuran vector sekarang = " << v.size() << "\n";
	cetakVector(v);

    cout << "Men-delete data di vector\n";
    p = v.begin(); // p menunjuk ke elemen ke-0 vector
    p = p+10; // sekarang p menunjuk ke elemen ke-10 vector
    v.erase(p,p+3); // menghapus 3 elemen vector mulai dari elemen ke-10 hingga ke-12
    cout << "Ukuran vector sekarang = " << v.size() << "\n";
	cetakVector(v);


    return 0;
}
