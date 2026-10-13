#include <iostream>
#include<fstream>
#include "project.h"
using namespace std;
int remove(){
    int pin=1234,x;
    cout<<"Enter Password:";(cin>>x);
    if(x!=pin){
        cout<<"error...\n";
        return 0;
    }
    else if(x==0){
        return 0;
    }
    cout<<"Enter Student ID: ";
    string id;
    getline(cin>>ws,id);
    if(id==to_string(0)){
        return 0;
    }
    if(id.length()!=8){
        cout<<"Should be 8 digit ID!.\n";
        remove();
    }
    ifstream file("student.txt");
    ofstream file2("demo.txt");
    string line;
    int count=0,p=0,d=0;
    while(getline(file,line)){
        
        if(line.find(id)!=string::npos){
            count++;
            d++;
        }
        else if(line.find(id)==string::npos && count==0){
            file2<<line<<endl;
        }
        if(count==1){
            p++;
        }
        if(p==8){
            count=0;
        } //if programm fails then i can use p==7
    }
    if(d==0){
        cout<<"No Student record!";
    }
    else{
        cout<<"Success\n";
    }
    file.close();
    file2.close();
    remove("student.txt");
    rename("demo.txt","student.txt");
    return 0;
}