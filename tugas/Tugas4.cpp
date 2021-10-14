#include <iostream>
using namespace std;

class usia{
    private :
      int x,y;
    public :
      void hitung(int thnLhr, int thnSkrng){
          x = thnLhr;
          y = thnSkrng;
      }
      int hitungUsia(){
          return x - y;
      }
};
int main(){
    usia U;
    U.hitung(2021, 1990);
    cout<<"Berarti usia anda sekarang adalah "<<U.hitungUsia()<<" tahun";
}