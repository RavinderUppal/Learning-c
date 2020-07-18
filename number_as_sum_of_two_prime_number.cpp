#include<iostream>

using namespace std;

int prime_num(int n);

int main()
{
    int n,flag;
    cout<<"Eneter a positive number:";
    cin>>n;
    flag=0;
    for (int i=2; i<=n/2; i++)
    {
        if (prime_num(i)==1)
        {
            if (prime_num(n-i)==1)
            {
                cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                flag=1;
            }
        }

    }
    if (flag==0)
        {
            cout<<"Given number cannot be represented as sum of two prime numbers.";
        }
}
int prime_num(int n)
{
    int i,is_prime;
    is_prime = 1;
    for (i=2; i<=n/2; i++)
    {
        if (n%i==0)
        {
            is_prime=0;
            break;
        }
    }
    return is_prime;
}
