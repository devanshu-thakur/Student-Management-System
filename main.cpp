#include <iostream> //This is main.cpp file. The First Page of Application.
#include "project.h"
#include<string>
#include<windows.h>
using namespace std;
void pg1(){
    //adding litte design
    for(auto i=0;i<36;i++){
        cout<<"__";
    }
    //List to display
    cout<<"\n------> Smart Student Management System <------\n"<<endl;
    cout<<"1.Register New Student\n"; //done
    cout<<"2.Check Student Details\n"; //done
    cout<<"3.Remove Student data\n"; //done
    cout<<"4.Upadte Student Details\n"; //done
    cout<<"5.Marks Record\n"; //done
    cout<<"6.Rank List\n";
    cout<<"0.Exit Program\n"; //done
    
}
int input_entry(){
    string num;
    int a;
    while(true){ 
        pg1();
        cout<<"Enter Option: ";
        cin>>num;
        if(num=="0"){
            cout<<"\nPlease wait...\n";
            Sleep(2000);
            break;
        }
        else if(num=="1"){
            register_new_std();
        }
        else if(num=="2"){
            cout<<"\n1.Check by name()\n";
            cout<<"2.Check by ID()\nEnter Option: ";
            cin>>a;
            if(a==1){
                check_by_name();
            }
            else if(a==2){
                check_by_id();
            }
        }
        else if(num=="3"){
            remove();
        }
        else if(num=="4"){
            update();
        }
        else if(num=="5"){
            cout<<"\n1.Get Marks\n";
            cout<<"2.Set Marks\n";
            cout<<"3.Update Marks\n";
            cout<<"Enter Option: ";
            string perC;
            cin>>perC;
            if(perC=="1"){
                get_marks();
            }
            else if(perC=="2"){
                set_marks();
            }
            else if(perC=="3"){
                update_marks();
            }
            else{
                break;
            }
        }
        else if(num=="6"){
            cout<<"Sorry___\nUpdates are underway...>>>\n"; //keeping for updates
        }
        else{
            input_entry();
        }
    }
    return 0;
}
int main(){
    input_entry();
    return 0;
}