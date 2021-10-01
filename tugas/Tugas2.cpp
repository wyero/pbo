#include <iostream>
using namespace std;

int main(){
    int thnLhr, thnSkrng, umur;
    cout<<"Masukkan Tahun Lahir : ";
    cin>>thnLhr;
    cout<<"Masukkan Tahun Sekarang : ";
    cin>>thnSkrng;
    umur = thnSkrng - thnLhr;
    cout<<"Berarti usia anda sekarang adalah "<<umur<<" tahun";
}