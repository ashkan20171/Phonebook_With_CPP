#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void Open(string);
void Close();
int Count();
struct user
{
	string name;
	int code;
}u;
FILE *f;
void main()
{
	int s,r;
	char ch;
	string strname="";
	user *aryu;
	do
	{
	bool temp=false;
	system("cls");
	cout<<"1 Add\n";
	cout<<"2 Show\n";
	cout<<"3 Delete\n";
	cout<<"4 Delete All\n";
	cout<<"5 Search\n";
	cout<<"6 Edit\n";
	cout<<"7 Sort\n";
	cout<<"8 Exit\n";
	cout<<"Enter Num(1-8) :";
	cin>>s;
	if(s==1)
	{
		Open("a");
		cout<<"Enter Name and Code :";
		cin>>u.name>>u.code;
		fwrite(&u,sizeof(u),1,f);
		Close();

	}
	else if(s==2)
	{
		system("cls");
		r=Count();
		if(r!=0)
		{
		cout<<"Name : Code :\n";
		Open("r");
		for(int i=1;i<=r;i++)
		{
			fread(&u,sizeof(u),1,f);
			cout<<u.name<<" "<<u.code<<"\n";
		}
		Close();
		}
		else
		{
			cout<<"List is empty...\n";
		}
	}
	else if(s==3)
	{
		system("cls");
		cout<<"Enter Name :";
		cin>>strname;
		aryu=new user[Count()];
		r=Count();
		Open("r");
		for (int i = 0; i <= r-1; i++)
		{
			fread(&aryu[i],sizeof(aryu[0]),1,f);
			if(aryu[i].name==strname)
				temp=true;
		}
		Close();
		if(temp==true)
		{
		Open("w");
		for (int i = 0; i <= r-1; i++)
		{
			if(aryu[i].name!=strname)
				fwrite(&aryu[i],sizeof(aryu[0]),1,f);
		}
		Close();
		cout<<"deleted...\n";
		}
		else
			cout<<"Item not found...\n";
	}
	else if(s==4)
	{
		system("cls");
		cout<<"Are you sure ? (y/n)";
		ch=getch();
		if(ch=='y' || ch=='Y')
		{
			Open("w");
			Close();
			cout<<"\nAll items was deleted...\n";
		}
	}
	else if(s==5)
	{
		system("cls");
		cout<<"Enter Name :";
		cin>>strname;
		r=Count();
		if(r!=0)
		{
			Open("r");
			for (int i = 0; i <= r-1; i++)
			{
				fread(&u,sizeof(u),1,f);
				if(u.name==strname)
				{
					cout<<u.name<<" "<<u.code<<"\n";
					temp=true;
				}
			}
			if(temp==false)
				cout<<"Item not found...\n";
			Close();
		}
		else
			cout<<"List is empty...";
	}
	else if(s==6)
	{
		int code;
		cout<<"Enter Code :";
		cin>>code;
		r=Count();
		aryu=new user[r];
		Open("r");
		for (int i = 0; i <= r-1; i++)
		{
			fread(&aryu[i],sizeof(aryu[i]),1,f);
			if(aryu[i].code==code)
				temp=true;
		}
		Close();
		if(temp==true)
		{
			Open("w");
			for (int i = 0; i <= r-1; i++)
			{
				if(aryu[i].code!=code)
					fwrite(&aryu[i],sizeof(aryu[i]),1,f);
			}
			Close();
			cout<<"Enter new name and code :";
			cin>>u.name>>u.code;
			Open("a");
			fwrite(&u,sizeof(u),1,f);
			Close();
		}
		else
		{
			cout<<"Item not found...\n";
		}

	}
	else if(s==7)
	{
		r=Count();
		aryu=new user[r];
		Open("r");
		for (int i = 0; i <= r-1; i++)
			fread(&aryu[i],sizeof(aryu[i]),1,f);
		Close();
		for (int i = 0; i <= r-1-1; i++)
		{
			for (int j = 0; j < r-1-i; j++)
			{
				if(aryu[j].code > aryu[j+1].code)
				{
					u.name=aryu[j].name;
					u.code=aryu[j].code;

					aryu[j].name=aryu[j+1].name;
					aryu[j].code=aryu[j+1].code;

					aryu[j+1].name=u.name;
					aryu[j+1].code=u.code;
				}
			}
		}
		cout<<"Name: Code:\n";
		for (int i = 0; i <= r-1; i++)
			cout<<aryu[i].name<<" "<<aryu[i].code<<"\n";
	}
	else if(s==8)
	{
		system("cls");
		cout<<"WWW.LEARNFILES.COM";
		getch();
		exit(0);
	}
	else
	{
		system("cls");
		cout<"Erorr...\n";
	}
	cout<<"Do you want to continue ? ";
	ch=getch();
	}while (ch=='y' || ch=='Y');
}

void Open(string str)
{
	if(str=="a")
		f=fopen("f:\\learnfiles.txt","a");
	else if(str=="r")
		f=fopen("f:\\learnfiles.txt","r");
	else if(str=="w")
		f=fopen("f:\\learnfiles.txt","w");
}
void Close()
{
	fclose(f);
}
int Count()
{
	int c=0;
	Open("r");
	while (!feof(f))
	{
		fread(&u,sizeof(u),1,f);
		c++;
	}
	Close();
	c--;
	return c;
}