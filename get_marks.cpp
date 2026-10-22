#include<iostream> //file is used to obtain marks record from new.db.
#include "project.h"
#include<string> //file have input id as id
#include<fstream>
#include<sqlite3.h>
using namespace std;
int get_marks(){
    string id;//Checking if id is present in registered students list
    cout<<"Enter id: ";cin>>id;
    if(id.length()!=8){
        cout<<"Enter 8 digit ID!\n";
        get_marks();
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
        cout<<"ID does not exists!";
        return 0;
    }
    //get makrs from databse
    sqlite3* db;
    if(sqlite3_open("new.db",&db)!=SQLITE_OK){
        cout<<"Error: "<<sqlite3_errmsg(db)<<endl;
        sqlite3_close(db);
        return 1;
    }
    const char* selectData="select * from record;";

    cout<<"Academic Marks Record:"<<endl;
    sqlite3_stmt* stmt;

    if(sqlite3_prepare_v2(db,selectData,-1,&stmt,nullptr)!=SQLITE_OK){
        cout<<"Error: "<<sqlite3_errmsg(db)<<endl;
        sqlite3_close(db);
        return 1;
    }
    cout << "---------------------------------------------------------\n";
    cout << "\nID        \tMaths \tFoCP \tFoEE \tPC \tE_Physics\n";
    cout << "---------------------------------------------------------\n";
    while(sqlite3_step(stmt)==SQLITE_ROW){
        int st_id=sqlite3_column_int(stmt,0);
        int marks_M=sqlite3_column_int(stmt,1);
        int marks_CP=sqlite3_column_int(stmt,2);
        int marks_EE=sqlite3_column_int(stmt,3);
        int marks_PC=sqlite3_column_int(stmt,4);
        int marks_Phy=sqlite3_column_int(stmt,5);

        if(id==to_string(st_id)){
            cout<<st_id<<"\t"<<marks_M<<"\t"<<marks_CP<<"\t"<<marks_EE<<"\t"<<marks_PC<<"\t"<<marks_Phy<<"\t"<<endl;
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}