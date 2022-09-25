#include <iostream>
using namespace std;

int maxValue{3};
int top{1};
static int totalBarang{};
static int i{0};

struct paketKiriman
{
    char jenisBarang[30];
    int beratBarang;
    char kotaTujuan[50];
    struct paketKiriman *pointer;
};

void tambahNilai (struct paketKiriman *p)
{

    if (i == 0)
    {
        p->pointer = new struct paketKiriman[maxValue];
    }
    cout << "Masukkan data Jenis Barang : ";
    cin >> p->pointer[i].jenisBarang;
    cout << "Masukkan data Berat Barang : ";
    cin >> p->pointer[i].beratBarang;
    cout << "Masukkan data Kota Tujuan : ";
    cin >> p->pointer[i].kotaTujuan;
    i++;
    totalBarang++;
    top++;
}

void hapusData (struct paketKiriman *p ,int index)
{
    if (index >= 0 && index < totalBarang)
    {
        for (int j = index; j < totalBarang-1; j++)
            p->pointer[j] = p->pointer[j+1];
        totalBarang--;
        top--;
    }
}
void displayNilai (struct paketKiriman display)
{
    cout << "\nHasil data : " << endl;
    for (int j = 0; j < totalBarang; j++)
    {
        cout << "Data ke-" << j+1 << "\n" << display.pointer[j].jenisBarang << " "
                << display.pointer[j].beratBarang << " "
                << display.pointer[j].kotaTujuan << endl;
    }
}


int main () {

    int pilih{}, indexHapus{};
    struct paketKiriman data;
    cout << "Limit Stack Data hanyalah : " << maxValue << endl;
    do
    {
            cout << "\n1. Tambah Data : " << endl;
            cout << "2. Tampilkan Data : " << endl;
            cout << "3. Hapus Data ke- : " << endl;
            cout << "4. Keluar Program : " << endl;

            cout << "\nMasukkan pilihan anda : ";
            cin >> pilih;

            if (pilih == 1)
            {
                if (top <= maxValue)
                    tambahNilai (&data);
                else
                    cout << "Stack is FULL!!!" << endl;
            }
            else if (pilih == 2)
                displayNilai(data);
            else if (pilih == 3)
            {
                 if (top > 0)
                {
                    cin >> indexHapus;
                    hapusData(&data,indexHapus);
                }
                 else
                     cout << "Stack is EMPTY!!!" << endl;
            }
            else
                exit(1);
    } while (pilih >= 1 || pilih <=3 );

    return 0;
}
