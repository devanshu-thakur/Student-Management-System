#include<iostream>
#include<string>
#include<iostream> //file is used to obtain marks record from new.db.
#include "project.h"
#include<sqlite3.h>
using namespace std;
int rank_list(){
    //taking input for number of list
    string lim;
    cout<<"Enter the list limit: ";
    cin>>lim;

    //Accessing databse
    sqlite3* db;
    if(sqlite3_open("new.db",&db)!=SQLITE_OK){
        cout<<"Error: "<<sqlite3_errmsg(db)<<endl;
        sqlite3_close(db);
        return 1;
    }
    string selectData = "select * from record order by Maths+ FoCP+ FoEE+ PC+ E_Physics desc limit " + lim + ";";

    sqlite3_stmt*stmt;
    if(sqlite3_prepare_v2(db,selectData.c_str(),-1,&stmt,nullptr)!=SQLITE_OK){
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

        {
            cout<<st_id<<"\t"<<marks_M<<"\t"<<marks_CP<<"\t"<<marks_EE<<"\t"<<marks_PC<<"\t"<<marks_Phy<<"\t"<<endl;
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}