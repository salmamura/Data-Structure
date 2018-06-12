#include "header.h"

int main()
{
    Stack s;
    createStack(&s);
    infoType info;
    int pil;
    menu:
    system("cls");
    cout << "Menu"<<endl<<endl;
    cout << "1. Push"<<endl;
    cout << "2. Pop"<<endl;
    cout << "3. View"<<endl;
    cout << "4. Keluar"<<endl;
    cout << "Masukkan pilihan : ";
    cin >> pil;
    system("cls");
    switch(pil){
        case 1 :
            cout << "Masukkan ID barang : ";

            cin >> info.id_barang;
            cin.sync();
            cout << "Masukkan Nama barang : ";
            getline(cin, info.nama_barang);
            cout << "Masukkan Berat barang : ";
            cin >> info.berat;
            push(&s,createNode(info));

            break;
        case 2 :
            pop(&s,1);
            break;
        case 3 :
            display(s);
            break;
        case 4 :
            return 0;
            break;
    }
    getch();
    goto menu;
}
