#include<iostream>
#include<stdlib.h>

using namespace std;

class garden{
	private :
		int statustmbh; 
		int jumlahair;
		int jumlahppk;
	
	public :
		garden (){ 
			garden :: statustmbh  = 0;
			garden :: jumlahair   = 0;
			garden :: jumlahppk = 0;
		}
		
		void siram(){ 
			jumlahair++;
			cektmbh();
		}
		void berippk(){ 
			jumlahppk++;
			cektmbh();
		}
		void cektmbh(){ 
			if(jumlahair >= 3 && jumlahppk >= 1){
				cout<<"Tanaman Anda Tumbuh "<<endl;
				tmbh();
			}
			else{
				cout<<"Kondisi Garden Belum Memenuhi Untuk Tumbuh "<<endl;
				cout<<"jumlah air   = "<<jumlahair<<endl;
				cout<<"jumlah ppk = "<<jumlahppk<<endl;
			}
		}
		void tmbh(){ 
			if(statustmbh < 4){
				jumlahair   = jumlahair - 3;
				jumlahppk 	= jumlahppk - 1;
				statustmbh++;
			}else{
                cout<<"Tanaman Anda Sudah Berbunga";
            }
		}
		void displaygarden(){
			cout<<"Status Pertumbuhan Tanaman = "<<pertmbhan()<<endl;
			cout<<"Jumlah air   = "<<jumlahair<<endl;
			cout<<"Jumlah ppk 	= "<<jumlahppk<<endl;
		}

		string pertmbhan(){
			if (statustmbh == 0){ 
				return "Benih"; 
			}
			else if(statustmbh == 1){ 
				return "Tunas";
			}
			else if(statustmbh == 2){  
				return "Tanaman Kecil";
			}
			else if(statustmbh == 3){ 
				return "Tanaman Dewasa";
			}
			else if(statustmbh == 4){ 
				return "Berbunga";
			}
            return 0;
		}
		int getstatustmbh(){ 
			return statustmbh;
		}
};
int main(){
	int pilih;
	char y;
	garden w;
	cout<<"Catatan	: Untuk tumbuh Dibutuhkan 3 Air dan 1 Pupuk "<<endl;
	
	menu:
		cout<<"\n";
		cout<<"0  Memberi Air "<<endl;
		cout<<"1  Memberi Pupuk"<<endl;
		cout<<"2  Keluar"<<endl;
		cout<<"Masukan pilihan Anda = ";cin>>pilih;
		
		if(pilih == 0){
			system("cls");
			w.siram();
			cout<<"\n";
			w.displaygarden();
			cout<<"Saya Ingin Berpindah ke Menu (y/t) = ";cin>>y;
			if (y == 'y'){
				goto menu;
			}
			else if(y == 't'){
				cout<<" Terimakasih ";
			}
		}
		else if(pilih == 1){
			system("cls");
			w.berippk();
			cout<<"\n";
			w.displaygarden();
			cout<<"Saya Ingin Berpindah ke Menu (y/t) = ";cin>>y;
			if (y == 'y'){
				goto menu;
			}
			else if(y == 't'){
				cout<<" Termikasih ";
			}
		}
        else if(pilih == 2){
            cout<<"Terimakasih";
        }
        return 0;
}