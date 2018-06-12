/*
Author   : Izzatul Ummah (izza@hpc.telkomuniversity.ac.id)
Date     : 2013.03.16
Objective: Untuk digunakan dalam praktikum perkuliahan Analisis Perancangan Algoritma, Komputasi Paralel, dan HPC

Reference:
- C++ Complete Reference 4th edition (Herbert Schildt, McGrawHill), page 643-645
  http://10.3.26.47/perpustakaan/C,C++/C++TheCompleteReference-4ed.pdf
*/


#include <iostream>
using namespace std;

class Mahasiswa{
    private:
        int nim;
        char* nama;
    public:
        Mahasiswa();
        Mahasiswa(int nimX, char* namaX);
        int getNim();
        void setNim(int nimX);
        char* getNama();
        void setNama(char* namaX);
        void printInfo();
};

Mahasiswa::Mahasiswa(){
    nim = -1;
    nama = "anonymous";
}
Mahasiswa::Mahasiswa(int nimX, char* namaX){
    nim = nimX;
    nama = namaX;
}
int Mahasiswa::getNim(){
    return nim;
}
void Mahasiswa::setNim(int nimX){
    nim = nimX;
}
char* Mahasiswa::getNama(){
    return nama;
}
void Mahasiswa::setNama(char* namaX){
    nama = namaX;
}
void Mahasiswa::printInfo(){
    cout << "NIM: " << nim << "\n";
    cout << "Nama: " << nama << "\n";
}
