#include <iostream>
#include <vector> // bagian dari STL
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //variable
    char option;
    int maks_inv, maks_item, pilih,acak,hapus;
    vector<string> item{"Pisau . sts: 5","Pedang . sts 10"};    //item
    vector<string> inve;    //vector untuk inventory
    vector<string>::iterator penunjuk   //iterator untuk inventory
    item.push_back("Pistol . sts: 15"); //item
    item.push_back("Laser . sts: 20");  //item
    item[2]="Batu . sts: 2";    //item pengganti
    srand(static_cast<unsigned>(time(0)));  //acak


    maks_item=item.size();  //maksimal item
    cout << "Maksimal item : "<< maks_item << endl; //tampilkan jumlah item
    cout << "Masukan Maks Inventory : "; cin >> maks_inv;   //input maks kapasitas inventory

    do{ //loop

    cout << "\nMenu :" << endl;
    cout << "1. Tampilkan Item" << endl;
    cout << "2. Tambah Item" << endl;
    cout << "3. Hapus Item" << endl;
    cout << "Pilih Menu : ";
    cin >> pilih;   //baca pilihan menu

    switch(pilih)//tampilan inventory
    {
        case 1://jika kosong
            if(inve.empty()){
                cout << "\nInvetory Masih Kosong" << endl;
            }else //jika ada isinya
                cout << endl;
               for(penunjuk=inve.begin()  ; penunjuk != inve.end();penunjuk++){
                    cout << *penunjuk << endl;
                    }
                }
            break;
        case 2: //jika inventory penuh
            if(inve.size()>=maks_inv){
                cout << "\nInvetory Penuh " <<endl;
            }
            else{   //jika item ditambahkan
            acak=rand()% maks_item;
            inve.push_back(item[acak]);
            cout << "\nItem yang ditambahkan adalah : "<< item[acak] << endl;
            }
            break;
        case 3:
            cout << "\nHapus item ke-";cin >> hapus;
            if(hapus-1>=inve.size()){   //hapus item
                cout << "Item Yang dipilih tidak ada" << endl;
            }else{
            hapus=hapus-1;  //kurangi jumlah inventory
            inve.erase(inve.begin()+hapus);
            }
            break;
        default:
            cout << "\nPilihan Salah" << endl;
            break;       }
    cout << "\nIngin Melanjutkan (y/n)? ";cin >> option;
    }while(option == 'y');
    //end loop

    return 0;
}
