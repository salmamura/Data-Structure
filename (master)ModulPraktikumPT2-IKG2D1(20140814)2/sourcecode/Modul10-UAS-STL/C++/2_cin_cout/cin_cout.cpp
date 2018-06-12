/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Petunjuk cara compile: $ g++ cin_cout.cpp
Agar hasil compile yang muncul bukan a.out, cara compilenya adalah: $ g++ cin_cout.cpp -o objtest
Cara nge-run: $ ./objtest
*/


#include <iostream>
using namespace std;

int main(){
    cout << "PROGRAM C++ UNTUK MENERIMA INPUTAN DARI KEYBOARD.\n";

    int x;
    cout << "Masukkan sebuah angka integer: ";
    cin >> x;
    cout << "Angka yang Anda masukkan adalah: " << x << "\n";
    cout << "Kuadrat dari angka tersebut adalah: " << x*x << "\n";


    float y;
    cout << "Masukkan sebuah angka float: ";
    cin >> y;
    cout << "Angka yang Anda masukkan adalah: " << y << "\n";
    cout << "Kuadrat dari angka tersebut adalah: " << y*y << "\n";

    char c;
    cout << "Masukkan sebuah karakter: ";
    cin >> c;
    cout << "Karakter yang Anda masukkan adalah: " << c << "\n";

    char str[255];
    cout << "Masukkan sebuah string (maksimal 255 huruf, tanpa spasi, boleh ada _ atau - ): ";
    cin >> str;
    cout << "String yang Anda masukkan adalah: " << str << "\n";

    return 0;
}
