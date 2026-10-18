#include<iostream> //file is used to update the existing marks of students, not to add new records.
#include<fstream> //file have input id as entered_id
#include<string>
#include "project.h"
#include<sqlite3.h>
using namespace std;
int update_marks(){
    int marks;
    string name,entered_id;
    //Checking if entered_id is present in registered students list
    cout<<"Enter Id: ";cin>>entered_id;
    if(entered_id.length()!=8){
        cout<<"Invalid ID!\n";
        update_marks();
    }
    ifstream file("student.txt");
    string line,match_id;
    while(getline(file,line)){
        if(line.find(entered_id)!=string::npos){
            match_id=line.substr(line.find(':')+1);
            break;
        }
    }
    file.close();
    if(match_id!=entered_id || entered_id=="0"){
        return 0;
    }
    //update makrs as per id
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
    #include <string>
// 1. Construct the SQL query
string queryStr = "UPDATE record SET "
                  "Maths = " + to_string(arr[0]) + ", "
                  "FoCP = " + to_string(arr[1]) + ", "
                  "FoEE = " + to_string(arr[2]) + ", "
                  "PC = " + to_string(arr[3]) + ", "
                  "E_Physics = " + to_string(arr[4]) + " "
                  "WHERE id = " + entered_id + ";";

// 2. Convert it to 'const char*' for your database function
const char* updateTable = queryStr.c_str();
char* error = nullptr;

    if (sqlite3_exec(db, updateTable, nullptr, nullptr, &error)) {
        cout << "Error: " << error << endl;
        sqlite3_close(db);
        return 1;
    }
    cout<<"Marks Updated!\n";
    sqlite3_close(db);
    return 0;
}