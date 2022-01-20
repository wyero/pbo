//Mahasiswa
#include <iostream>
#include <mysql/mysql.h>
#include <sstream>
using namespace std;

class MahasiswaA{
	public :
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
	    cout<<"Masukkan nama database: \n";
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
		    inserttodb << "INSERT INTO Mahasiswa (id, nim, nama, create_at, update_at) VALUES ('"+id+"','"+nim+"', '"+nama+"','"+create_at+"','"+update_at+"')";
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
	            cout << "==============LIST DATA==============\n";
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
		    selectdb << "SELECT * FROM Mahasiswa WHERE id = '"+id+"' ";
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
		        updatedb <<"UPDATE mahasiswa SET nim = '"+nim+"', nama= '"+nama+", create at = '"+create_at+"', update at= '"+update+",' WHERE id = '"+id+"' ";
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
		    cout << "Masukkan Id : "<<endl;
		    cin >> id;
		    stringstream selectdb, deletedb;
		    selectdb << "SELECT * FROM Mahasiswa WHERE id = '"+id+"' ";
		    string query = selectdb.str();
		    const char* q = query.c_str();
		    mysql_query(conn, q);
		    res = mysql_store_result(conn);
		    int count = mysql_num_fields(res);
		    my_ulonglong x = mysql_num_rows(res);
		
		    if(x>0){
		        deletedb <<"DELETE FROM Mahasiswa WHERE id = '"+id+"' ";
		        string query = deletedb.str();
		        const char* q = query.c_str();
		        mysql_query(conn, q);
		    }else{
		        cout<<"error\n";
		    }	
};
int main(){
	MahasiswaA m;
	char kembali;
	int pilih;
    MYSQL* conn = connectdb();
    do{
        cout<<"MENU";
        cout<<"\n 0. Exit";
        cout<<"\n 1. Create ";
        cout<<"\n 2. Read ";
        cout<<"\n 3. Update ";
        cout<<"\n 4. Delete ";
        cout<<"\n 5. Create Database ";
        
        cout<<"\nPilih : "; cin>>pilih;

        switch(pilih){
            case 0:
                cout<<"\nThanks"<<endl;
                return 0;
            case 1:
				m.insertData(conn);
                m.displayData(conn);
                break;
            case 2:
				m.displayData(conn);
                break;
            case 3:
                m.updateData(conn);
                m.displayData(conn);
                break;
            case 4:
                m.deleteData(conn);
                m.displayData(conn);
                break;
            case 5:
                m.createDatabase(conn);
                break;
            default:
                cout<<"Pilihan Salah"<<endl;
                break;
            }
            cout<<"Ingin memilih menu lain (y/t)? ";
            cin>>kembali;
            cout<<endl;
        }
        while (kembali!= 't');
        cout<<"Thanks"<<endl;
    return 0;
	}
}