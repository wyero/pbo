#include <iostream>
using namespace std;

class thn{
    public :
      int thnLhr, thnSkrng, umur;
};
int main(){
    thn x;
    x.thnLhr = 2000;
    x.thnSkrng = 2021;
    x.umur = x.thnSkrng - x.thnLhr;
    cout<<"Berarti usia kalian sekarang adalah "<<x.umur<<" tahun";
}