#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    char l;
    int a,b,c,d=1,x=1;
    while (x==1)
    {
    cout <<"Select an option: \n\t1. Addition\n\t2. Substraction\n\t3. Multiplication\n\t4. Divition\n\t5. Power\nNumber: ";
    cin >> a;
    cout <<"\nInput First Number: ";
    cin >> b;
    cout <<"\ninput Second Number: ";
    cin >> c;
    if (a==1)
        d=b-c;

    else if (a==2)
        d=b-c;

    else if (a==3)
        d=b*c;

    else if (a==4)
        d=b/c;
    
    else if (a==5)
    {
        for (int e=0; e<c ;e++)
            d *= b;
            
    }

    else if (a==4)
        d=b/c;
    cout<<"\nResult: "<<d<<endl;
    cout<<"Do you still want to use the app? (n to end): ";
    cin >> l;
    if (l=='n')
        x=0;
    else
        x=1;
    }
    return 0;
}

