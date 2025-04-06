#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;

class Student{
    private:
    string name;
    string rollNo;
    string grade;
    public:
    Student(){
        name = "";
        rollNo = "";
        grade = "";
    }
    void setRollNo(string rollNo){
        this->rollNo=rollNo;
    }
    void setName(string name){
        this->name=name;
    }
    void setGrade(string grade){
        this->grade = grade;
    }

    string getRollNo(){
        return this->rollNo;
    }
    string getName(){
        return this->name;
    }
    string getGrade(){
        return this->grade;
    }
};

string cal_grade(int avg){
    string grade;
    if(avg>90&&avg<=100){
        grade = "A";
    }
    else if(avg>80&&avg<=90){
        grade = "B";
    }
    else if(avg>70&&avg<=80){
        grade = "c";
    }
    else if(avg>60&&avg<=70){
        grade = "D";
    }
    else if(avg>50&&avg<=60){
        grade = "F";
    }
    return grade;
}
void displayReport(int total,int avg,string grade){
    cout<<"Student Report Card"<<endl;
    cout<<"*******************"<<endl;
    cout<<"Total Marks of Student :"<<total<<endl;
    cout<<"Average Marks of Student :"<<avg<<endl;
    cout<<"Grade of Student :"<<grade<<endl;
}
int main(){
    bool exit = false;
    Student s;
    while(!exit){
        system("cls");
        cout<<"Welcome to Student Report Card System"<<endl;
        cout<<"********************"<<endl;
        cout<<"1.Report Card"<<endl;
        cout<<"2.Exit"<<endl;
        cout<<"Enter Choice :";
        int choice;
        cin>>choice;
        system("cls");

        if(choice==1){
            // Take the student information 
            string rollNo,name,grade;
            int physics,maths,chemistry;
            cout<<"Enter RollNo of Student :";
            cin>>rollNo;
            cout<<"Enter Name of Student :";
            cin>>name;
            cout<<"Enter Physics Marks :";
            cin>>physics;
            cout<<"Enter Maths Marks :";
            cin>>maths;
            cout<<"Enter Chemistry Marks :";
            cin>>chemistry;
            system("cls");
            // set the value in the object
            s.setRollNo(rollNo);
            s.setName(name);
            
            // calculate the total marks and average
            int total = physics+maths+chemistry;
            int avg = total/3;

            // calculate the grade
            grade = cal_grade(avg);
            s.setGrade(grade);

            // display the report card 
            displayReport(total,avg,grade);
            //store report into file 
            ofstream out("C:/Users/Hp/Desktop/Student Report Card Management System/Student.txt",ios::app);
            out<<"\t"<<s.getRollNo()<<" : "<<s.getName()<<" : "<<s.getGrade()<<endl<<endl; // structure of the record in the file
            out.close();
            cout<<"Report Card is Saved in the File!"<<endl;
            Sleep(10000);
        }
        else if(choice==2){
            // Exit from the loop
            system("cls");
            exit = true;
            cout<<"Good Luck!";
            Sleep(3000);
        }
    }
}