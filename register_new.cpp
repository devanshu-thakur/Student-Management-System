#include <iostream>
#include<fstream> //This is register_new.cpp file. it design to store new students data.
#include "project.h"
#include<windows.h>
#include<ctime>
using namespace std;

int register_new_std(){

    int pin=1234,x;
    cout<<"Enter Password:";(cin>>x);
    if(pin!=x){
        return 0;
    }
//accessing time
    time_t now=time(nullptr);
    char* date=ctime(&now);
//taking required input and putting to file together
    ofstream file("student.txt",ios::app);
    string name,branch;
    int age,roll_no,sec;
    long long id;
    cout<<"Enter id: ";cin>>id;
    if(id==0){
        return 0;
    }
    file<<"id:"<<id<<""<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter Name:";getline(cin,name);
    
    file<<"name:"<<name<<""<<endl;
    cout<<"Enter Roll no. ";cin>>roll_no;
    file<<"roll no:"<<roll_no<<""<<endl;
    cout<<"Enter Age: ";cin>>age;
    file<<"age:"<<age<<"\n";
    cout<<"Enter branch: ";cin>>branch;
    file<<"branch:"<<branch<<"\n";
    cout<<"Enter Section: ";cin>>sec;
    file<<"section:"<<sec<<"\n";
    file<<"registration date:"<<date<<"\n";
    cout<<"\nsucessful";
    file.close();
    return 0;
}
