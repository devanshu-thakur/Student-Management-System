#include <iostream> //This is main.cpp file. The First Page of Application.
#include "project.h"
#include<windows.h>
using namespace std;
void pg1(){
    for(auto i=0;i<40;i++){
        cout<<"__";
    }
    cout<<"\n------> Smart Student Management System <------\n"<<endl;
    cout<<"1.Register New Student Details\n"; //done
    cout<<"2.Check Student Details\n"; //done
    cout<<"3.Remove Student data\n"; //done
    cout<<"4.Upadte Student Details\n"; //done
    cout<<"5.Rank List\n";
    cout<<"0.Exit Program\n"; //done
    
}
int main(){
    int num,a;

    while(true){ 
        pg1();
        cout<<"Enter Option: ";cin>>num;
        if(num==0){
            cout<<"Please wait...";
            Sleep(2000);
            break;
        }
        else if(num==1){
            register_new_std();
        }
        else if(num==2){
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
        else if(num==3){
            remove();
        }
        else if(num==4){
            update();
        }
        else if(num==5){
            cout<<"Sorry___\nUpdate is underway..>>\n";
        }
    }
    return 0;
}