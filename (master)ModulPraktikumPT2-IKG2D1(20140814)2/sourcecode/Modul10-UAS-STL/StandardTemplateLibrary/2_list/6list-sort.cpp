/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 652-653
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#define UPPER_RAND 1000

using namespace std;

void cetakList(list<int> listX){
    cout << "Menampilkan isi list: ";
    list<int>::iterator px = listX.begin();
    while(px != listX.end()) {
        cout << *px << " ";
        px++;
    }
    cout << "\n\n";
}


int main(){
    list<int> myList; // create an empty list
    int i;
	cout << "Mengisi list dengan integer random.\n";
	srand(time(NULL));
    for(i=0; i<10; i++){
        myList.push_back(rand() % UPPER_RAND);
    }
    cout << "Ukuran list = " << myList.size() << "\n";
	cetakList(myList);

	cout << "Mensorting elemen list dari nilai terkecil ke terbesar.\n";
	myList.sort();
	cetakList(myList);

    return 0;
}
