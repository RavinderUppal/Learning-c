#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

static int p=0;

class a
{
private:
	char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:
	void install();
	void allotment();
	void show();
	void empty();
	void avail();
	void position(int i);


}
bus[10];

void vline(char ch)
{
	for (int i=0; i<=110; i++)
	{
		cout<<ch;
	}
}

void a::install()
{
	cout<<"Enter Bus No: ";
	cin>>bus[p].busn;
	cout<<"\nEnter Driver's Name: ";
	cin>>bus[p].driver;
	cout<<"\nArrival Time: ";
	cin>>bus[p].arrival;
	cout<<"\nDeparture Time: ";
	cin>>bus[p].depart;
	cout<<"\nFrom : ";
	cin>>bus[p].from;
	cout<<"\nTo: ";
	cin>>bus[p].to;
	bus[p].empty();

	p++;
}

void a::allotment()
{
	int seat;
	char number[5];
	top:
		cout<<"\nEnter Bus No: ";
		cin>>number;
		int n;
		for ( n=0; n<=p; n++)
		{
			if (strcmp(number, bus[n].busn)==0)
				break;
		}

		while(n<=p)
		{
			cout<<"\nEnter Seat No: ";
			cin>>seat;
			if (seat>32)
				cout<<"\nThere Are Only 32 Seats In Bus"<<endl;
			else if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
			{
				cout<<"\nEnter Passenger Name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			
			else
				{
					cout<<"\nThe Seat Is Already Reserved"<<endl;
				}

		}

		if(n>p)
				{
					cout<<"\nEnter Correct Bus No.";

					goto top;
				}



}
void a::empty()
{
	int i,j;
	for (i=0; i<8; i++)
	{
		for (j=0; j<4; j++)
		{
			strcpy(bus[p].seat[i][j], "Empty");
		}
	}
}

void a::show()
{
	int n;
	char number[5];
	cout<<"Enter Bus No: ";
	cin>>number;
	for (n=0; n<=p; n++)
	{
		if (strcmp(bus[n].busn,number)==0)
		{
			break;
		}
	}
	while(n<=p)
	{
		vline('*');
		cout<<"\nBus No: "<<bus[n].busn<<endl;
		cout<<"Bus Driver: "<<bus[n].driver<<"\t\tArrival Time: "<<bus[n].arrival<<\
		"\t\tDeparture Time: "<<bus[n].depart<<"\tFrom: "<<bus[n].from<<"\t\tTo: "<<bus[n].to<<endl;
		vline('*');

		bus[0].position(n);

		int a;
		for (int i=0; i<8; i++)
		{
			for (int j=0; j<4; j++)
			{
				a++;
				if (strcmp(bus[n].seat[i][j], "Empty")!=0)
				{
					cout<<"\nThe Seat no. "<<a+1<<" is rserved by "<<bus[n].seat[i][j]<<endl;
				}
			}
		}
		break;
	}
	if (n>p)
	{
		cout<<"/nEnter Correct Bus No: ";
	}
}

void a::position(int n)
{
	int p=0,s=0;
	for (int i=0; i<8; i++)
	{
		cout<<"\n";
		for (int j=0; j<4; j++)
		{
			s++;
			if (strcmp(bus[n].seat[i][j], "Empty")==0)
			{
				cout.width(5);

				cout.fill(' ');

				cout<<s<<'.';

				cout.width(10);

				cout.fill(' ');

				cout<<bus[n].seat[i][j];

				p++;

			}
			else
			{
				cout.width(5);

				cout.fill(' ');

				cout<<s<<'.';

				cout.width(10);

				cout.fill(' ');

				cout<<bus[n].seat[i][j];
			}
		}
	}

	cout<<"\n\nThere are "<< p <<" seat(s) empty in bus no. "<<bus[n].busn<<endl;

}

void a::avail()
{
	for (int n=0; n<p; n++)
	{
		vline('*');

		cout<<"\nBus No: "<<bus[n].busn<<endl;
		cout<<"Bus Driver: "<<bus[n].driver<<"\t\tArrival Time: "<<bus[n].arrival<<\
		"\t\tDeparture Time: "<<bus[n].depart<<"\tFrom: "<<bus[n].from<<"\t\t\To: "<<bus[n].to<<endl;

		vline('*');
		cout<<"\n";
		vline('_');

	}
}

int main()
{
	system("cls");

	int w;

	while(1)
	{
		cout<<"\n\n\t\t\t\t\t1.Install\n\t\t\t\t\t2.Reservation\n\t\t\t\t\t3.Show\n\t\t\t\t\t4.Buses Available\n\t\t\t\t\t5.Exit"<<endl;
		cout<<"\t\t\t\t\tEnter Your Choice: ";
		cin>>w;

		switch(w)
		{
			case 1: bus[p].install();
				break;

			case 2: bus[p].allotment();
				break;

			case 3: bus[p].show();
				break;

		 	case 4: bus[p].avail();
		 		break;

		 	case 5: exit(0);

		}
	}

	return 0;
}
