#include <iostream>
#include<fstream>
#include "project.h"
using namespace std;
int check_by_name(){
    ifstream file("student.txt");
    if(!file.is_open()){
        cout<<"Error on loading file.\n";
        return 1;
    }
    string name;
    cout<<"Enter student name: ";
    getline(cin>>ws,name);
    
    cout<<"\nExpanding Details-------->"<<endl;
    string line;
    int count=0,t;
    while(getline(file,line)){
        if(line.find(name)!=string::npos){
            count++;
            t=6;
        }
        if(count>=1 && t>0){
            cout<<line<<endl;
            t--;
        }
    }
    return 0;
}
int check_by_id(){
    ifstream file("student.txt");
    if(!file.is_open()){
        cout<<"Error on loading file.\n";
        return 1;
    }
    string id;
    cout<<"Enter student ID: ";
    getline(cin>>ws,id);
    
    
    cout<<"\nExpanding Details-------->"<<endl;
    string line;
    int count=0,t;
    while(getline(file,line)){
        if(line.find(id)!=string::npos){
            count++;
            t=7;
        }
        if(count>=1 && t>0){
            cout<<line<<endl;
            t--;
        }
    }
    return 0;
}