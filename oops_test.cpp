/* #include<bits/stdc++.h>  //fiile use for testing for preparation but has no use in the project
using namespace std;
class  student{
public:
    string name;
    string branch;
    int age;
    map<string,double>mpp={
        {"Maths",0},
        {"Physics",0},
        {"FoCP",0},
        {"FoEE",0},
        {"PC",0}
    };
};
int main(){
    student s1;
    student s2;
    s1.name="devanshu thakur";
    s2.name ="prince thakur";
    s1.age=20;
    s2.age=15;

    s1.mpp["Maths"]=40;
    cout<<s1.mpp["Maths"]<<endl;
    
    fstream file("student.txt",ios::app|ios::in|ios::out);
    string line,str;

    cout<<"Enter name to add: ";cin>>str;
    while(getline(file,line)){
        if (line.find(str) != string::npos) {
            
            line=s1.name;
            file<<line;

        }
    }
    
} */
#include<bits/stdc++.h>
using namespace std;
class  student{
public:
    string name;
    int ID;
    string branch;
    int age;
    map<string,double>mpp={
        {"Maths",0},
        {"Physics",0},
        {"FoCP",0},
        {"FoEE",0},
        {"PC",0}
    };
};
/* int main(){
    student s1;
    s1.name="Devanshu";
    ifstream file("student.txt");
    string content="",line,str;
    str="Rahul";
    while(getline(file,line)){
        size_t pos=line.find(str);
        if(pos!=string ::npos){
            line.replace(pos,str.length(),s1.name);

        }
        content+=line+"\n";
    }
    file.close();
    ofstream file2("student.txt");
    file2<<content;
    file2.close();
} */
int main() {
    student s;
    ifstream file("student.txt");
    string line, str = "734873433";
    while(getline(file,line)){
        if(line.find(str)!=string ::npos){
            getline(file,line);
            s.name=line.substr(line.find(':')+1);
        }
    }
    cout<<s.name;
}
