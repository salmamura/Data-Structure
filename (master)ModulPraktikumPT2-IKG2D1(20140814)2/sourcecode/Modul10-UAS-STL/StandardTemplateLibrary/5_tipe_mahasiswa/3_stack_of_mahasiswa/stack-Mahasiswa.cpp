/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- The C++ Standard Library (Nicolai M. Josuttis, Addison Wesley), page 380-381 (Chapter 10.1 Stack)
  http://10.3.26.47/perpustakaan/C,C++/TheC++StandardLibrary.pdf
*/


#include <iostream>
#include <stack>
#include "Mahasiswa.cpp"
using namespace std;

int main()
{
    stack<Mahasiswa> st; // create an empty stack
    int i;
	cout << "Mengisi stack (push) dengan data mahasiswa secara berurut.\n";
    Mahasiswa m1(11810000,"Doraemon");
    Mahasiswa m2(11810001,"Nobita");
    Mahasiswa m3(11810002,"Shizuka");
    st.push(m1);
    st.push(m2);
    st.push(m3);

    cout << "Menampilkan isi stack dengan cara melakukan pop berulang-ulang: \n";
    while(!st.empty()){
        st.top().printInfo();
        st.pop();
    }


    return 0;
}
