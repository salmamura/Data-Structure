/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 686
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "PROGRAM C++ UNTUK MEMPROSES STRING.\n";
    string str1("Alpha");
    string str2("Beta");
    string str3("Omega");
    string str4;

    cout << "str1=" << str1 << "\n" << "str1=" << str3 << "\n";

    str4 = str1;
    cout << "str4=" << str4 << "\n";
    if(str4 == str1){
        cout << "str4 == str1\n";
    }

    str4 = str1 + " digabung dengan " + str3;
    cout << "str4=" << str4 << "\n";

    if(str4 == str1){
        cout << "str4 == str1\n";
    }
    if(str3 > str1){
        cout << "str3 > str1\n";
    }

    str1 = "Ini kalimat pertama.";
    cout << "str1=" << str1 << "\n";

    // Create a string object using another string object
    string str5(str1);
    cout << "str5=" << str5 << "\n";

    // Menerima masukan string dari keyboard
    cout << "Ketikkan sebuah string (tidak boleh ada spasi, gunakan _ atau - untuk memisahkan antar huruf): ";
    cin >> str5;
    cout << "String yang Anda ketikkan yaitu: " << str5;
    return 0;
}
