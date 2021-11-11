#include <iostream>
using namespace std;

class matematika{
	private :
		int nilaiA, nilaiB;
	public :
		void hitung(int a, int b){
			nilaiA = a;
			nilaiB = b;
		}
		void input(){
			cout<<"Masukkan angka 1 : "; 
			cin>>nilaiA;
			cout<<"Masukkan angka 2 : ";
			cin>>nilaiB;
		}
		void menu(){
			cout<<"PROGRAM MATEMATIKA SEDERHANA"<<endl;
			cout<<"MENU"<<endl;
			cout<<"0. Keluar"<<endl;
			cout<<"1. Penjumlahan"<<endl;
			cout<<"2. Pengurangan"<<endl;
			cout<<"3. Perkalian"<<endl;
			cout<<"4. Pembagian"<<endl;
		}
		int penjumlahan(){
			return nilaiA+nilaiB;
		}
		int pengurangan(){
			return nilaiA-nilaiB;
		}
		int perkalian(){
			return nilaiA*nilaiB;
		}
		int pembagian(){
			return nilaiA/nilaiB;
		}
		int hitung(int pilih){
			if(pilih == 0){
				cout<<"Thanks"<<endl;
			}else if(pilih == 1){
				input();
				cout<<"Hasil Penjumlahan : "<<penjumlahan()<<endl;
			}else if(pilih == 2){
				input();
				cout<<"Hasil Pengurangan : "<<pengurangan()<<endl;
			}else if(pilih == 3){
				input();
				cout<<"Hasil Perkalian : "<<perkalian()<<endl;
			}else if(pilih == 4){
				input();
				cout<<"Hasil Pembagian : "<<pembagian()<<endl;;
			}
		}
};
int main(){
	string ulang;
	int pilih;
	matematika m;
	do{
		m.menu();
		cout<<"Masukkan pilihan anda : ";
		cin>>pilih;
		m.hitung(pilih);
		cout<<"Ulangi Program [y/n] : ";
		cin>>ulang;
	}while(ulang == "y");
	cout<<"Program selesai"<<endl;
}