#include <iostream>
using namespace std;

class waktu{
	private :
		int jam, menit, detik;
	public :
		waktu(int j, int m, int d);
		int hitung(int j, int m, int d);
		int tambahJam();
		int tambahMenit();
		int tambahDetik();
		void hasil();
};
waktu::waktu(int jam, int menit, int detik){
	hitung(jam, menit, detik);
}
int waktu::hitung(int j, int m, int d){
	if((j>=0 && j<=59)&&(m>=0 && m<=59)&&(d>=0 && d<=59)){
		jam = j;
		menit = m;
		detik = d;
	}else{
		cout<<"format salah"<<endl;
	}
}
	int waktu::tambahJam(){
		return jam;
	}
	int waktu::tambahMenit(){
		return menit;
	}
	int waktu::tambahDetik(){
		return detik;
	}
	void waktu::hasil(){
		cout<<jam<<" : "<<menit<<" : "<<detik;
}
int main(){
	waktu w;
	w.hitung(60,60,60);
	w.hasil();
}