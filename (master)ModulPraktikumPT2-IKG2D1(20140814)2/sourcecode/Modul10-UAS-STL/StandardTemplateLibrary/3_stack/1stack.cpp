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
using namespace std;

int main()
{
    stack<int> st; // create an empty stack
    int i;
	cout << "Mengisi stack (push) dengan integer secara berurut.\n";
    for(i=0;i<10;i++){
        st.push(i);
    }
    cout << "Menampilkan isi stack dengan cara melakukan pop berulang-ulang: ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}
