#include<iostream>

using namespace std;

int main()
{
    char name[100];
    int age;
    cout<<"Enter Your Name:";
    cin.getline(name,100);
    cout<<"Hi, "<<name<<endl;
    cout<<"Enter Your Age:";
    cin>>age;
    if (age>=18)
    {
        cout<<"You Are Eligible For Voting \nGo Ahead And Vote"<<endl;
    }
    else
    {
        cout<<name<<", you are not eligible for voting,"<<endl;
        cout<<"Wait for "<<18-age<<" year(s)"<<endl;
    }
}
