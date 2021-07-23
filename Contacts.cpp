#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<fstream>
using namespace std;

struct contact
{
	char name[25];
	int number[10];
	struct contact *prev;
	struct contact *next;
};

class contact_book
{
	struct contact *first;
	struct contact *last;

public:

	contact_book()
	{
		first=NULL;
		last=NULL;
		char name[25];
		int number[10];
		int i;
		fstream f;
		f.open("contacts.txt");
		while(!f.eof())
		{
			f>>name;
			for(i=0;i<10;i++)
				f>>number[i];
			add_contact(name,number);
		}
		f.close();
	}

	void add_contact(char new_name[25],int new_number[10])
	{
		struct contact *new_contact = new contact;
		struct contact *temp;
		int i;

		for(i=0;i<25;i++)
		{
			new_contact->name[i]=new_name[i];
		}
		for(i=0;i<10;i++)
		{
			new_contact->number[i]=new_number[i];
		}

		if(first==NULL && last==NULL)
		{
			first=new_contact;
			last=new_contact;
			new_contact->prev=NULL;
			new_contact->next=NULL;
		}
		else if(strcmpi(first->name,new_contact->name)>0)
		{
			temp=first;
			first=new_contact;
			temp->prev=new_contact;
			new_contact->next=temp;
			new_contact->prev=NULL;
		}
		else if(strcmpi(last->name,new_contact->name)<0)
		{
			temp=last;
			last=new_contact;
			temp->next=new_contact;
			new_contact->prev=temp;
			new_contact->next=NULL;
		}
		else
		{
			temp=first->next;
			while(temp->next!=NULL)
			{
				if(strcmpi(temp->name,new_contact->name)>0)
				{
					temp->prev->next=new_contact;
					new_contact->prev=temp->prev;
					new_contact->next=temp;
					temp->prev=new_contact;
					break;
				}
				else
					temp=temp->next;
			}
		}
	}

	void delete_contact(char new_name[25])
	{
		struct contact *temp;
		if(first==last)
		{
			temp=first;
			first=NULL;
			last=NULL;
			delete temp;
		}
		else if(strcmpi(new_name,first->name)==0)
		{
			temp=first;
			first=first->next;
			first->prev=NULL;
			delete temp;
		}
		else if(strcmpi(new_name,first->name)==0)
		{
			temp=last;
			last=last->prev;
			last->next=NULL;
			delete temp;
		}
		else
		{
			temp=first->next;
			while(temp->next!=NULL)
			{
				if(strcmpi(new_name,temp->name)==0)
				{
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					delete temp;
				}
				temp=temp->next;
			}
		}
	}

	void show()
	{
		int i;
		struct contact *temp;
		temp=first;
		while(temp!=NULL)
		{
			cout<<temp->name<<" ";
			for(i=0;i<10;i++)
				cout<<temp->number[i];
			cout<<endl;
			temp=temp->next;
		}
	}

	void get_no(char new_name[25])
	{
		int i;
		struct contact *temp;
		temp=first;
		while(temp!=NULL)
		{
			if(strcmpi(new_name,temp->name)==0)
			{
				cout<<temp->name<<" ";
				for(i=0;i<10;i++)
					cout<<temp->number[i];
				cout<<endl;
				break;
			}
			temp=temp->next;
		}
	}

	~contact_book()
	{
		struct contact *temp;
		int i;
		fstream f;
		f.open("contacts.txt");
		while(first!=NULL)
		{
			temp=first;
			first=first->next;
			f<<temp->name<<" ";
			for(i=0;i<10;i++)
				f<<temp->number[i]<<" ";
			f<<endl;
			delete temp;
		}
		f.close();
	}
};


void code()
{
	contact_book c;
	char choice;
	char name[25];
	int number[10];
	int i;
	switch(choice):
	{
		case 's':
			c.show();
			break;
		case 'd':
			cin>>name;
			c.delete_contact(name);
			break;
		case 'a':
			cin>>name;
			for(i=0;i<10;i++)
				cin>>number[i];
			c.add_contact(name,number);
			break;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input_contact.txt", "r", stdin);
	freopen("output_contact.txt", "w", stdout);
#endif
	
    code();

 return 0;
}