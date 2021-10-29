#include <iostream>
using namespace std;

class waktu{
	private : // data hanya dapat diakses dalam kelas dan tidak bisa diakses diluar kelas		   
		int jam, menit, detik;
	public : // data bisa diakses di bagian program mana saja	
		void hitung(int j, int m, int d){
			if((j>=0 && j<=23)&&(m>=0 && m<=59)&&(d>=0 && d<=59)){
				jam = j;
				menit = m;
				detik = d;
			}else{
				cout<<"format waktu salah"<<endl;
			}
		}
		int tambahJam(){
			return jam;
		}
		int tambahMenit(){
			return menit;
		}
		int tambahDetik(){
			return detik;
		}
		int atur(){
			cout<<jam<<" : "<<menit<<" : "<<detik;
		}
};
int main(){
	waktu w;
	w.hitung(11,59,10);
	w.atur();
}