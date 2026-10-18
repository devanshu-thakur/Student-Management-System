#include <iostream>
#include<fstream>
#include "project.h"
#include<string>
using namespace std;
int update(){
    string str,line, id,oldName,newName;
    int Age,newAge,roll_no,newRoll_no,
    section,newSection;
    cout<<"Enter student ID: ";cin>>id;
    if(id=="0"){
        return 0;
    }
    else if(id.length()!=8){
        cout<<"Invalid ID!\n";
        update();
    }
    cout<<"*Update Options:\nname,age,roll_no,section\n";
    cout<<"Enter exact to update: ";cin>>str;
    if(str!="name"||str!="age"||str!="roll_no"||str!="section"){
        cout<<"error...\n";
        return 0;
    } 
    ifstream file("student.txt");
    while(getline(file,line)){
        if(line.find(id)!=string::npos){
            if(str=="name"){
                getline(file,line);
                oldName=line.substr(line.find(':')+1);
            }
            else if(str=="age"){
                getline(file,line);
                getline(file,line);
                getline(file,line);
                Age=stoi(line.substr(line.find(':')+1));
            }
            else if(str=="roll_no"){
                getline(file,line);
                getline(file,line);
                roll_no=stoi(line.substr(line.find(':')+1));
            }
            else if(str=="section"){
                getline(file,line);
                getline(file,line);
                getline(file,line);
                getline(file,line);
                getline(file,line);
                section=stoi(line.substr(line.find(':')+1));
            }
        }
    }
    file.close();
    ifstream file2("student.txt");
    string line2,content="";
    


    //Asking for new inputs:
    if(str=="name"){
        cout<<"Enter New: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newName);
    }
    else if(str=="age"){
        cout<<"Enter New: ";
        cin>>newAge;
    }
    else if(str=="roll_no"){
        cout<<"Enter New: ";
        cin>>newRoll_no;
    }
    else if(str=="section"){
        cout<<"Enter New: ";
        cin>>newSection;
    }
    int p=0;
    while(getline(file2,line2)){
        if(str=="name"){

            if(line2.find(id)!=string::npos){
                content+=line2+"\n";
                getline(file2,line2);
                size_t pos=line2.find(oldName);
                if(pos!=string::npos &&  p==0){
                    line2.replace(pos,oldName.length(),newName);
                    p++;
                }
                if(p>0){
                    line2=line2;
                }
            }
            content+=line2+"\n";
        }
        else if(str=="age"){
            
            if(line2.find(id)!=string::npos){
                content+=line2+"\n";
                getline(file2,line2);
                content+=line2+"\n";
                getline(file2,line2);
                content+=line2+"\n";
                getline(file2,line2);
                size_t pos=line2.find(to_string(Age));
                if(pos!=string::npos &&  p==0){
                    line2.replace(pos,to_string(Age).length(),to_string(newAge));
                    p++;
                }
                if(p>0){
                    line2=line2;
                }
            }
            content+=line2+"\n";
        }
        else if(str=="roll_no"){

            if(line2.find(id)!=string::npos){
                 content+=line2+"\n";
                getline(file2,line2);
                content+=line2+"\n";
                getline(file2,line2);
                size_t pos=line2.find(to_string(roll_no));
                if(pos!=string::npos &&  p==0){
                    line2.replace(pos,to_string(roll_no).length(),to_string(newRoll_no));
                    p++;
                }
                if(p>0){
                    line2=line2;
                }
            
            }
            content+=line2+"\n";
        }
        else if(str=="section"){

            if(line2.find(id)!=string::npos){
                content+=line2+"\n";
                getline(file2,line2);
                content+=line2+"\n";
                getline(file2,line2);
                content+=line2+"\n";
                getline(file2,line2);
                content+=line2+"\n";
                getline(file2,line2);
                content+=line2+"\n";
                getline(file2,line2);
                size_t pos=line2.find(to_string(section));
                if(pos!=string::npos &&  p==0){
                    line2.replace(pos,to_string(section).length(),to_string(newSection));
                    p++;
                }
                if(p>0){
                    line2=line2;
                }
            }
            content+=line2+"\n";
        }
    }
    file2.close();
    ofstream file3("student.txt");
    file3<<content;
    file3.close();
    return 0;
}