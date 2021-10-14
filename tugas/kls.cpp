#include <iostream>
using namespace std;

class hitung{
    private :
      int a,b,c;
    public :
      void angka(int d, int e, int f){
          a = d;
          b = e;
          c = f;
      }
      int tambah(){
          return a+b+c;
      }
      int kurang(){
          return a-b-c;
      }
      int kali(){
          return a*b*c;
      }
      int bagi(){
          return a/b/c;
      }
};
int main(){
    hitung H;
    H.angka(10, 20, 50);
    cout<<"Hasil Penjumlahan : "<<H.tambah()<<endl;
    cout<<"Hasil Pengurangan : "<<H.kurang()<<endl;
    cout<<"Hasil Perkalian   : "<<H.kali()<<endl;
    cout<<"Hasil Pembagian   : "<<H.bagi()<<endl;
}