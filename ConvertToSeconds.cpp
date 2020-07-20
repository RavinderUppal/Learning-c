#include<iostream>

using namespace std;

class time
{
private:
    int hrs;
    int minutes;
    int sec;
    int ans;
public:
    readData()
    {
        cout<<"Enter time: "<<endl;
        cout<<" Hours? ";
        cin>>hrs;
        cout<<" Minutes? ";
        cin>>minutes;
        cout<<" Seconds? ";
        cin>>sec;
    }
    convert()
    {
        ans =((hrs*60 + minutes)*60)+sec;
    }
    displayData()
    {

        cout<<"The time is= "<<hrs<<":"<<minutes<<":"<<sec<<endl;
        cout<<"Time in total seconds: "<<ans;
    }
};
int main()
{

    time t;
    t.readData();
    t.convert();
    t.displayData();
    return 0;

}
