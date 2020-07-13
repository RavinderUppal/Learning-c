#include<iostream>

using namespace std;

int main()
{
    int num[5];
    cout<<"Enter elements:";
    for (int i=0; i<5; i++)
    {
        cin>>num[i];
    }
    cout<<"You entered:";
    for (int z=0; z<5; z++)
    {
        cout<<num[z]<<endl;
    }
    return 0;

}
