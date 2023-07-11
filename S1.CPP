#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>

struct student
{
 char name[20];
 char en[15];
 char course[10];
 float id;
};

fstream file;
student obj;

void add()
{
 cout<<"Enter Name: ";
 cin>>obj.name;
 cout<<"Enter Enrollment Number: ";
 cin>>obj.en;
 cout<<"Enter Course: ";
 cin>>obj.course;
 cout<<"Enter ID: ";
 cin>>obj.id;

 file.open("database.txt",ios::app) ;
 file.write((char*)&obj,sizeof(obj));
 file.close();
}

void show_all()
{
 file.open("database.txt",ios::in);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  cout<<"Name: "<<obj.name<<endl;
  cout<<"Enrollment Number: "<<obj.en<<endl;
  cout<<"Course: "<<obj.course<<endl;
  cout<<"ID: "<<obj.id<<endl<<endl;

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}

void search()
{
 float user;
 cout<<"Enter ID: ";
 cin>>user;
 file.open("database.txt",ios::in);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  if (obj.id==user)
  {
   cout<<"Name: "<<obj.name<<endl;
   cout<<"Enrollment Number: "<<obj.en<<endl;
   cout<<"Course: "<<obj.course<<endl;
   cout<<"ID: "<<obj.id<<endl<<endl;
  }

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}

void edit()
{

 char user[15];
 cout<<"Enter Enrollment Number: ";
 cin>>user;

 file.open("database.txt",ios::in|ios::out);
 file.read((char*)&obj,sizeof(obj));

 while (file.eof()==0)
 {
  if (strcmp(obj.en,user)==0)
  {
   cout<<"Name: "<<obj.name<<endl;
   cout<<"Enrollment Number: "<<obj.en<<endl;
   cout<<"Course: "<<obj.course<<endl;
   cout<<"ID: "<<obj.id<<endl<<endl;

   cout<<"\nEnter New course: ";
   cin>>obj.course;

   file.seekp(file.tellg()-sizeof(obj));
   file.write((char*)&obj,sizeof(obj));
   cout<<"\n\nFile Updated";
   break;
  }

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 getch();
}


void main()
{
 clrscr();
 int option;

 while(1)
 {
   cout<<"Enter 1 to Enter Record\n";
  cout<<"Enter 2 to Show All Record\n";
  cout<<"Enter 3 to Search Record\n";
  cout<<"Enter 4 to Exit\n";
  cout<<"\n\nEnter Option: ";
  cin>>option;

  switch (option)
  {
   case 1:
    add();
    cout<<"\n\nRecord Entered\n";
    getch();
    break;
   case 2:
    show_all();
    break;
   case 3:
    search();
    break;
   case 4:
    exit(0);
  }
 }
 getch();
}