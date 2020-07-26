#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<iomanip>

using namespace std;

int main()
{
    FILE *fp, *ft;
    char choice, another;

    struct student
    {
        char first_name[50], last_name[50],course[100];
        int section;
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp = fopen("user.txt","rb+");

    if (fp==NULL)
    {
        fp=fopen("user,txt","wb+");
        if (fp == NULL)
        {
            puts("cannot open file");
            return 0;
        }
    }

    recsize = sizeof(e);

    while (1)
    {
        system("cls");

        cout<<"\t\t\t======STUDENT DATABASE MANAGEMENT SYSTEM======";
        cout<<"\n";
        cout<<"\n\t\t\t1.ADD RECORDS";
        cout<<"\n\t\t\t2.LIST RECORDS";
        cout<<"\n\t\t\t3.MODIFY RECORDS";
        cout<<"\n\t\t\t4.DLETE RECORDS";
        cout<<"\n\t\t\t5.EXIT ";
        cout<<"\n\n";
        cout<<"enter your choice=> ";
        cin>>choice;

        switch(choice)
        {
            case '1':fseek(fp, 0, SEEK_END);
            another='Y';
            while(another=='y' || another=='Y')
            {
                system("cls");
                cout<<"enter the first name: ";
                cin>>e.first_name;
                cout<<"enter the last namee: ";
                cin>>e.last_name;
                cout<<"enter the course: ";
                cin>>e.course;
                cout<<"enter the section: ";
                cin>>e.section;
                fwrite(&e, recsize, 1,fp);
                cout<<"add another record(y/n)";
                cin>>another;
            }

            break;

            case '2':
                system("cls");
                rewind(fp);
                cout<<"======View the records in database======";
                cout<<"\n";
                while(fread(&e,recsize,1,fp)==1)
                {
                    cout<<"\n";
                    cout<<"\n"<<e.first_name<<setw(10)<<e.last_name;
                    cout<<"\n";
                    cout<<"\n"<<e.course<<setw(8)<<e.section;
                }
                cout<<"\n\n";
                system("pause");
                break;

            case '3':
                system("cls");
                another = 'Y';
                while(another=='y' || another=='Y')
                {
                    cout<<"\n Enter the last name of the student: ";
                    cin>>xlast_name;

                    rewind(fp);
                    while (fread(&e,recsize,1,fp)==1)
                    {
                        if (strcmp(e.last_name,xlast_name)==0)
                        {
                            cout<<"Enter the new first name: ";
                            cin>>e.first_name;
                            cout<<"Enter the new last name: ";
                            cin>>e.last_name;
                            cout<<"Enter the new course: ";
                            cin>>e.course;
                            cout<<"Enter the new section: ";
                            cin>>e.section;
                            fseek(fp,-recsize,SEEK_CUR);
                            fwrite(&e,recsize,1,fp);
                            break;
                        }
                        else
                            cout<<"record not found";

                    }
                    cout<<"\n Modify another record(Y/N)";
                    cin>>another;

                }
                break;

            case '4':
                system("cls");
                another = 'Y';
                while(another=='y' || another=='Y')
                {
                    cout<<"\nenter the last name of the student to delete: ";
                    cin>>xlast_name;

                    ft=fopen("temp.dat", "wb");

                    rewind(fp);
                    while(fread(&e, recsize,1,fp)==1)
                    {
                        if(strcmp(e.last_name,xlast_name)!=0)
                        {
                            fwrite(&e,recsize,1,ft);
                        }
                    fclose(fp);
                    fclose(ft);
                    remove("users.txt");
                    rename("temp.dat","users.txt");

                    fp=fopen("user.txt","rb+");

                    cout<<"\ndelete another record(Y/N)";
                    cin>>another;
                    }
                }
                break;

            case '5':
                fclose(fp);
                cout<<"\n\n";
                cout<<"\t\t  THANK YOU FOR USING THIS SOFTWARE";
                cout<<"\n\n";
                exit(0);
        }


    }

    system("pause");
    return 0;
}
