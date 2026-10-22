#include<iostream> //file is used to add new records.
#include "project.h"
#include<string>
#include<fstream> //file have input id as id
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
    cout<<"*Type order: Maths FoCP FoEE PC E_Physics"<<endl;
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
        "Maths tinyint check(Maths <= 100),"
        "FoCP tinyint check(FoCP <= 100),"
        "FoEE tinyint check(FoEE <= 100),"
        "PC tinyint check(PC <= 100),"
        "E_Physics tinyint check(E_Physics <= 100));";

    if(sqlite3_exec(db,createTable,nullptr,nullptr,&error)!=SQLITE_OK){
        cout<<"Error: "<<error<<endl;
        sqlite3_close(db);
        return 1;
    }
    string insertData = "insert into record(id, Maths, FoCP, FoEE, PC, E_Physics) values(" +
        id + "," + to_string(arr[0]) + "," + to_string(arr[1]) + "," +
        to_string(arr[2]) + "," + to_string(arr[3]) + "," + to_string(arr[4]) + ");";

    if (sqlite3_exec(db, insertData.c_str(), nullptr, nullptr, &error)!=SQLITE_OK) {
        cout << "Error: " << error << endl;
        sqlite3_close(db);
        return 1;
    }
    cout << "Marks recorded successfully" << endl;
    sqlite3_close(db);
    return 0;
}