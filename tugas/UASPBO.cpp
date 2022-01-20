#include <iostream>
#include <mysql/mysql.h>
#include <sstream>
using namespace std;

		const char* hostname = "192.168.1.6";
		const char* user = "root";
		const char* pass = "22012#";
		const char* dbname = "UAS";
		unsigned int port = 3306;
		const char* unixsocket = NULL;
		unsigned long clientflag = 0;
	
		MYSQL* connectdb(){
	    MYSQL * conn;
	    conn = mysql_init(0);
	    conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
	    if (conn) {
	        cout<< "Berhasil"<<endl;
	        return conn;
	    } else {
	        cout<< "Gagal"<<endl;
	        return conn;
	    }
	}
	void createDatabase(MYSQL* conn){
	    string database;
	    stringstream createdb, dropdb, createulangdb;
	    cout<<"Masukkan Nama Database: \n";
	    cin >> database;
	    createdb << "CREATE DATABASE "+database+" ";
	    string query = createdb.str();
	    const char* q = query.c_str();
	    int qstate = mysql_query(conn, q);
	    if(qstate==0){
	        cout<<"Berhasil Membuat Database\n";
	    }else if (qstate ==0)
	    {
	        dropdb << "DROP DATABASE "+database+" ";
	        string query = dropdb.str();
	        const char* q = query.c_str();
	        int qstate = mysql_query(conn, q);
	        cout<<"Database Berhasil Dihapus\n";
	    }else{
	        createulangdb << "CREATE DATABASE "+database+" ";
	        string query = createulangdb.str();
	        const char* q = query.c_str();
	        int qstate = mysql_query(conn, q);
	        cout<<"Membuat Ulang Database\n";
	    }
	}
};
class MahasiswaA{
	void insertDataMahasiswa(MYSQL* conn){
	    int qstate =0;
	    stringstream inserttodb;
	    	int id;
	    	string nim, nama, create_at, update_at;
		    cout<<"ID : "; cin>>id;
		    cout<<"NIM : "; cin>>nim;
			cout<<"Nama : "; cin>>nama;
			cout<<"Create At : "; cin>>create_at;
			cout<<"Update At : "; cin>>update_at; 
		    inserttodb << "INSERT INTO Mahasiswa (ID, NIM, Nama, Create At, Update At) VALUES ('"+id+"','"+nim+"', '"+nama+"','"+create_at+"','"+update_at+"')";
		    string query = inserttodb.str();
		    const char* q = query.c_str();
		    qstate = mysql_query(conn, q);
		    if (qstate == 0){
		        cout <<"Mahasiswa Berhasil Ditambah"<<endl;
		    } else {
		        cout <<"Mahasiswa Gagal Ditambah"<<endl;
		    }
	}
	void displayDataMahasiswa(MYSQL* conn){
	    MYSQL_ROW row;
	    MYSQL_RES* res;
	    	if (conn){
	   		int qstate = mysql_query(conn, "SELECT * FROM Mahasiswa");
	    	if(!qstate){
	            res = mysql_store_result(conn);
	            int count = mysql_num_fields(res);
	            cout << "==============LIST DATA MAHASISWA==============\n";
	            cout <<"\tID\tNIM\tNAMA\CREATE AT\UPDATE AT\n";
	            while(row = mysql_fetch_row(res)){
	                for(int i=0; i<count;i++){
	                    cout <<"\t"<<row[i];
	                }
	                cout<<endl;
	            }
			}
			} else {
	        cout << "Data Kosong" <<endl;
	    }
	}
	void updateDataMahasiswa(MYSQL* conn){
	    MYSQL_ROW row;
	    MYSQL_RES* res;
		    string id;
		    cout << "Masukkan ID Mahasiswa: "<<endl;
		    cin >> id;
		    stringstream selectdb, updatedb;
		    selectdb << "SELECT * FROM Mahasiswa WHERE ID = '"+id+"' ";
		    string query = selectdb.str();
		    const char* q = query.c_str();
		    mysql_query(conn, q);
		    res = mysql_store_result(conn);
		    int count = mysql_num_fields(res);
		    my_ulonglong x = mysql_num_rows(res);
		    string nim, nama, create_at, update_at;
		    if(x>0){
		        cout<<"NIM : ";
		        cin>>nim;
		        cout<<"Nama : ";
		        cin>>nama;
		        cout<<"Create At : "; cin>>create_at;
		        cout<<"Update At : "; cin>>update_at;
		        updatedb <<"UPDATE mahasiswa SET NIM = '"+nim+"', Nama= '"+nama+", Create at = '"+create_at+"', Update At= '"+update_at+",' WHERE id = '"+id+"' ";
		        string query = updatedb.str();
		        const char* q = query.c_str();
		        mysql_query(conn, q);
		    }else{
		        cout<<"Error\n";
		    }
		}
	void deleteData(MYSQL* conn){
		MYSQL_ROW row;
	    MYSQL_RES* res;
		    string id;
		    cout << "Masukkan ID : "<<endl;
		    cin >> id;
		    stringstream selectdb, deletedb;
		    selectdb << "SELECT * FROM Mahasiswa WHERE ID = '"+id+"' ";
		    string query = selectdb.str();
		    const char* q = query.c_str();
		    mysql_query(conn, q);
		    res = mysql_store_result(conn);
		    int count = mysql_num_fields(res);
		    my_ulonglong x = mysql_num_rows(res);
		
		    if(x>0){
		        deletedb <<"DELETE FROM Mahasiswa WHERE ID = '"+id+"' ";
		        string query = deletedb.str();
		        const char* q = query.c_str();
		        mysql_query(conn, q);
		    }else{
		        cout<<"Error\n";
		    }	
};
class MatkulA{
	void insertDataMatkul(MYSQL* conn){
	    int qstate =0;
	    stringstream inserttodb;
	    	int id;
	    	string kdMatkul, nama, create_at, update_at;
		    cout<<"ID : "; cin>>id;
		    cout<<"Kode Matkul : "; cin>>kdMatkul;
			cout<<"Nama : "; cin>>nama;
			cout<<"Create At : "; cin>>create_at;
			cout<<"Update At : "; cin>>update_at; 
		    inserttodb << "INSERT INTO Matkul (ID, Kode Matkul, Nama, Create At, Update At) VALUES ('"+id+"','"+kdMatkul+"', '"+nama+"','"+create_at+"','"+update_at+"')";
		    string query = inserttodb.str();
		    const char* q = query.c_str();
		    qstate = mysql_query(conn, q);
		    if (qstate == 0){
		        cout <<"Matkul Berhasil Ditambah"<<endl;
		    } else {
		        cout <<"Matkul Gagal Ditambah"<<endl;
		    }
	}
	void displayDataMatkul(MYSQL* conn){
	    MYSQL_ROW row;
	    MYSQL_RES* res;
	    	if (conn){
	   		int qstate = mysql_query(conn, "SELECT * FROM Matkul");
	    	if(!qstate){
	            res = mysql_store_result(conn);
	            int count = mysql_num_fields(res);
	            cout << "==============LIST MATA KULIAH==============\n";
	            cout <<"\tID\tKODE MATKUL\tNAMA\CREATE AT\UPDATE AT\n";
	            while(row = mysql_fetch_row(res)){
	                for(int i=0; i<count;i++){
	                    cout <<"\t"<<row[i];
	                }
	                cout<<endl;
	            }
			}
			} else {
	        cout << "Data Kosong" <<endl;
	    }
	}
	void updateDataMatkul(MYSQL* conn){
	    MYSQL_ROW row;
	    MYSQL_RES* res;
		    string id;
		    cout << "Masukkan ID Matkul: "<<endl;
		    cin >> id;
		    stringstream selectdb, updatedb;
		    selectdb << "SELECT * FROM Matkul WHERE ID = '"+id+"' ";
		    string query = selectdb.str();
		    const char* q = query.c_str();
		    mysql_query(conn, q);
		    res = mysql_store_result(conn);
		    int count = mysql_num_fields(res);
		    my_ulonglong x = mysql_num_rows(res);
		    string kdMatkul, nama, create_at, update_at;
		    if(x>0){
		        cout<<"Kode Matkul : ";
		        cin>>kdMatkul;
		        cout<<"Nama : ";
		        cin>>nama;
		        cout<<"Create At : "; cin>>create_at;
		        cout<<"Update At : "; cin>>update_at;
		        updatedb <<"UPDATE Matkul SET Kode Matkul = '"+kdMatkul+"', Nama= '"+nama+", Create At = '"+create_at+"', Update At= '"+update+",' WHERE ID = '"+id+"' ";
		        string query = updatedb.str();
		        const char* q = query.c_str();
		        mysql_query(conn, q);
		    }else{
		        cout<<"Error\n";
		    }
		}
	void deleteDataMatkul(MYSQL* conn){
		MYSQL_ROW row;
	    MYSQL_RES* res;
		    string id;
		    cout << "Masukkan ID : "<<endl;
		    cin >> id;
		    stringstream selectdb, deletedb;
		    selectdb << "SELECT * FROM Matkul WHERE ID = '"+id+"' ";
		    string query = selectdb.str();
		    const char* q = query.c_str();
		    mysql_query(conn, q);
		    res = mysql_store_result(conn);
		    int count = mysql_num_fields(res);
		    my_ulonglong x = mysql_num_rows(res);
		
		    if(x>0){
		        deletedb <<"DELETE FROM Matkul WHERE ID = '"+id+"' ";
		        string query = deletedb.str();
		        const char* q = query.c_str();
		        mysql_query(conn, q);
		    }else{
		        cout<<"Error\n";
		    }	
};
int main(){
	MYSQL* conn = connectdb();
	int pilih;
	MahasiswaA MH;
	MatkulA MK;
	string ulang;
	do{
		cout<<"MENU"<<endl;
		cout<<"1. Create Database"<<endl;
		cout<<"2. Create"<<endl;
		cout<<"3. Read"<<endl;
		cout<<"4. Update"<<endl;
		cout<<"5. Delete"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Masukkan pilihan anda : "; cin>>pilih;
		if(pilih == 1){
			createDatabase(conn);
		}else if(pilih == 2){
			int p;
			cout<<"1. Create Mahasiswa"<<endl;
			cout<<"2. Create Matkul"<<endl;
			cout<<"pilih : "; cin>>p;
			if(p == 1){
				MH.insertDataMahasiswa(conn);
				MH.displayDataMahasiswa(conn);
			}else if(p == 2){
				MK.insertDataMatkul(conn);
				MK.displayDataMatkul(conn);
			}
		}else if(pilih == 3){
			int p;
			cout<<"1. Read Mahasiswa"<<endl;
			cout<<"2. Read Matkul"<<endl;
			cout<<"pilih : "; cin>>p;
			if(p == 1){
				MH.displayDataMahasiswa(conn);
			}else if(p == 2){
				MK.displayDataMatkul(conn);
			}
		}else if(pilih == 4){
			int b;
			cout<<"1. Update Data Mahasiswa"<<endl;
			cout<<"2. Update Matkul"<<endl;
			cout<<"Pilih : "; cin>>b;
			if(b == 1){
				MH.updateDataMahasiswa(conn);
				MH.displayDataMahasiswa(conn);
			}else if(b == 2){
				MK.updateDataMatkul(conn);
				MK.displayDataMatkul(conn);
			}
		}else if(pilih == 5){
			int m;
			cout<<"1. Delete Data Mahasiswa"<<endl;
			cout<<"2. Delete Matkul"<<endl;
			cout<<"Pilih : "; cin>>m;
			if(m == 1){
				MH.deleteDataMahasiswa(conn);
				MH.displayDataMahasiswa(conn);
			}else if(pilih == 2){
				MK.deleteDataMatkul(conn);
				MK.displayDataMatkul(conn);
			}
		}else if(pilih == 6){
			cout<<"Terima Kasih"<<endl;
		}
		cout<<"Ulangi Program [y/n] : "; cin>>ulang;
	}while(ulang == "y");
	cout<<"Program Selesai"<<endl;
}