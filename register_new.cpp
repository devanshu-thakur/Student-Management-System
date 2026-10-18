#include <iostream>
#include<fstream> //This is register_new.cpp file. it design to store new students data.
#include "project.h"
#include<string>
#include<windows.h>
#include<ctime>
using namespace std;

int register_new_std(){
    string pin="1234",x;
    cout<<"Enter Password:";(cin>>x); //authentication
    if(pin!=x){
        cout<<"error...\n";
        return 0;
    }
    //accessing time
    time_t now=time(nullptr);
    char* date=ctime(&now);
    //Auto Reading the registration number from file line 1;
ifstream file4("student.txt");
string line4;
long long id = 20260000;
while (getline(file4, line4)) {
    if (line4.find("id:") == 0) {
        long long currentID = stoll(line4.substr(3));
        if (currentID > id) {
            id = currentID;
        }
    }
}
file4.close();
//increasing id for further use
id++;
//taking required input and putting to file together
    ofstream file("student.txt",ios::app);
    string name,branch;
    int age,roll_no,sec;
    //long long id;
    //cout<<"Enter id: ";cin>>id;
    if(id==0){
        id--;
        return 0;
    }
    cout<<"\nID registered is: "<<id<<endl;
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
    
    cout<<"\nSucessful";
    file.close();
    //REPROMPT to register new student or exit
    cout<<"\n1.New Registration\n2.Exit to back\n";
    cout<<"Enter option: ";
    int re_ask;
    cin>>re_ask;
    if(re_ask==1){
        register_new_std();
    }
    else{
        return 0;
    }
    return 0;
}