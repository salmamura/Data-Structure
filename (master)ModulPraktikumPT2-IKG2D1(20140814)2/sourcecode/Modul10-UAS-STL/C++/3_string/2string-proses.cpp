/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 689
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "PROGRAM C++ UNTUK MEMPROSES STRING.\n";
    string str1("Belajar C++ itu mudah dan menyenangkan.");
	string str2("Langit biru");
	cout << "str1: " << str1 << "\n";
	cout << "str2: " << str2 << "\n\n";

	cout << "Insert str2 into str1:\n";
	str1.insert(7, str2);
	cout << str1 << "\n\n";

	cout << "Remove 9 characters from str1:\n";
	str1.erase(6, 9);
	cout << str1 <<"\n\n";

	cout << "Replace 8 characters in str1 with str2:\n";
	str1.replace(7, 8, str2);
	cout << str1 << endl;
    return 0;
}
