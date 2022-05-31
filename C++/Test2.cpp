#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main ()
{
    int student,studentage,totalage=0,male=0,female=0;
    string studentname, studentgender;
    cout << "Enter Number of Student needed: "; cin >> student;
    for (int counter=0; counter != student; counter ++)
    {
        cout <<"\nEnter Student Information"<<endl;
        cout <<"Name: "; cin >> studentname;
        cout <<"Gender (M for Male, F for Female): "; cin >> studentgender;
        cout <<"Age: "; cin >> studentage;
        if (studentgender=="M")
            male+=1;
        else if (studentgender=="F")
            female+=1;
        totalage=totalage+studentage;
    }
    cout << "\nNumber of student(s) entered: "<<student<<endl;
    cout << "Gender breakdown: "<<male<<" Male, "<<female<<" Female"<<endl;
    cout << "Average ages of student: "<<totalage/student<<" years old"<<endl;
    return 0;
}