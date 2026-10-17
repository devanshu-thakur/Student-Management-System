#include<iostream>
#include "project.h"
#include<fstream>
#include<sqlite3.h>
using namespace std;
int set_marks(){
    int marks;
    string name,id;
    //Checking if id is present in registered students list
    cout<<"Enter Id: ";cin>>id;
    if(id.length()!=8){
        cout<<"Enter 8 digit ID!\n";
        set_marks();
    }
    ifstream file("student.txt");
    string line,match_id;
    while(getline(file,line)){
        if(line.find(id)!=string::npos){
            match_id=line.substr(line.find(':')+1);
            break;
        }
    }
    file.close();
    if(match_id!=id || id=="0"){
        return 0;
    }
    //set makrs as per id
    int arr[5];
    cout<<"Maths FoCP FoEE PC E_Physics"<<endl;
    cout<<"Enter Marks: ";
    for(auto i=0;i<5;i++){
        cin>>arr[i];
    }
    
    sqlite3* db;
    if(sqlite3_open("new.db",&db)!=SQLITE_OK){
        cout<<"Error: "<<sqlite3_errmsg(db)<<endl;
        sqlite3_close(db);
        return 1;
    }
    char* error=nullptr;
    const char * createTable =
        "create table if not exists record("
        "id int primary key,"
        "Maths int,"
        "FoCP tinyint,"
        "FoEE tinyint,"
        "PC tinyint,"
        "E_Physics tinyint)";
    if(sqlite3_exec(db,createTable,nullptr,nullptr,&error)){
        cout<<"Error: "<<sqlite3_errmsg(db);
        sqlite3_close(db);
        return 1;
    }
    string insertData = "insert or ignore into record(id, Maths, FoCP, FoEE, PC, E_Physics) values(" +
        id + "," + to_string(arr[0]) + "," + to_string(arr[1]) + "," +
        to_string(arr[2]) + "," + to_string(arr[3]) + "," + to_string(arr[4]) + ");";

    if (sqlite3_exec(db, insertData.c_str(), nullptr, nullptr, &error)) {
        cout << "Error: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }
    cout << "Marks recorded successfully" << endl;
    sqlite3_close(db);
    return 0;
}
/* int main(){
    set_marks();
    return 0;
} */