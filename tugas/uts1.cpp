#include <iostream>
using namespace std;

class nama{
	private :
		string firstName, middleName, lastName;
	public :
		void tulis(string x, string y, string z){
			firstName = x;
			middleName = y;
			lastName = z;
		}
		void input(){
			cout<<"Masukkan First Name : ";
			cin>>firstName;
			cout<<"Masukkan Middle Name : ";
			cin>>middleName;
			cout<<"Masukkan Last Name : ";
			cin>>lastName;
cout<<"Full Name : "<<firstName<<" "<<middleName<<" "<<lastName<<endl;
		}		
};
int main(){
	nama n;
	string ulang;
	int pilih;
	do{
	cout<<"MENU"<<endl;
	cout<<"0. Keluar"<<endl;
	cout<<"1. Input"<<endl;
	cout<<"Masukkan pilihan anda : ";
	cin>>pilih;
	if(pilih == 0){
		cout<<"Thanks"<<endl;
	}else if(pilih == 1){
		n.input();
	}
	cout<<"Ulangi program [y/n] : ";
	cin>>ulang;
	}while(ulang == "y");
	cout<<"Program selesai";
}