#include <iostream> //This is main.cpp file. The First Page of Application.
#include "project.h"
#include<string>
#include<windows.h>
using namespace std;
void pg1(){
    //Adding litte design to display
    cout << "\n=======================================================" << endl;
    cout << "          SMART STUDENT MANAGEMENT SYSTEM          " << endl;
    cout << "=======================================================" << endl;
    
    cout << " [1]  Register New Student\n";
    cout << " [2]  View Student Details\n";
    cout << " [3]  Remove Student Record\n";
    cout << " [4]  Update Student Information\n";
    cout << " [5]  Manage Marks Record\n";
    cout << " [6]  Generate Academic Rank List\n";
    cout << " [0]  Exit Program\n";
    
    cout << "-------------------------------------------------------" << endl;
    
}
int input_entry(){
    string num;
    int a;
    while(true){ 
        pg1();
        cout<<"Please enter your choice (0-6): ";
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
            cout<<"\n[1] Check by name()\n";
            cout<<"[2] Check by ID()\nEnter Option: ";
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
            cout<<"\n[1] Get Marks\n";
            cout<<"[2] Set Marks\n";
            cout<<"[3] Update Marks\n";
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
                cout << "\nInvalid sub-option!\n";
            }
        }
        else if(num=="6"){
            //cout<<"Sorry___\nUpdates are underway...>>>\n"; //keeping for updates
            rank_list();
        }
        else{
            cout << "\nInvalid choice! Exceeds range.\n\n";
        }
    }
    return 0;
}
int main(){
    input_entry();
    return 0;
}