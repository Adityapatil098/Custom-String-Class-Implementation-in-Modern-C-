#include<iostream>
#include<cstring>
using namespace std;
char* mstrcpy(char *,const char*);
int mstrcmp(const char *, const char *);
void mstrcat(char *,const char *);
int mstrlen(char *);
class STRING
{
	char *s;
	int length;
	public:
	STRING()
	{
		cout<<"default constructor"<<endl;
		s=0;
		length=0;
	}
	STRING(char *p)
	{
		cout<<"parameterised constructor"<<endl;
		length=strlen(p);
		s=new char[length+1];
		mstrcpy(s,p);

	}
	STRING(const STRING &t)
	{
		cout<<"copy constructor"<<endl;
		length=t.length;
		s=new char[length+1];
		mstrcpy(s,t.s);
	}
	~STRING()
	{
		cout<<"distructor"<<endl;
		delete []s;
	}
	void getstr()
	{
		cout<<s<<endl;
	}
	STRING operator =(const STRING t)
	{
		int len;
		for(len=0;t.s[len];len++);
		if(s!=0)
			delete []s;
		s=new char[len];
		mstrcpy(s,t.s);
		return t;
	}
	const char* operator =(const char *p)
	{
		int len;
		for(len=0;p[len];len++);
		if(s!=0)
			delete []s;
		s=new char[len];
		mstrcpy(s,p);
		return p;
	}
	char& operator[](int i)
	{
		return s[i];
	}
	STRING operator+(STRING &t)
	{
		int len;
		for(len=0;t.s[len];len++);
		len+=length;
		STRING temp;
		temp.length=len;
		temp.s=new char[len+1];
		temp.s[0]=0;
		mstrcat(temp.s,s);
		mstrcat(temp.s,t.s);
		return temp;
	}
	int operator>(STRING &t)
	{
		int l;
		l=mstrcmp(s,t.s);
		if(l>0)
			return 1;
		else
			return 0;
	}
	int operator>=(STRING &t)
	{
		int l;
		l=mstrcmp(s,t.s);
		if(l>=0)
			return 1;
		else
			return 0;
	}
	int operator<(STRING &t)
	{
		int l;
		l=mstrcmp(s,t.s);
		if(l<0)
			return 1;
		else
			return 0;
	}
	int operator<=(STRING &t)
	{
		int l;
		l=mstrcmp(s,t.s);
		if(l<=0)
			return 1;
		else
			return 0;
	}
	int operator==(STRING &t)
	{
		int l;
		l=mstrcmp(s,t.s);
		if(l==0)
			return 1;
		else
			return 0;
	}
	int operator!=(STRING &t)
	{
		int l;
		l=mstrcmp(s,t.s);
		if(l!=0)
			return 1;
		else
			return 0;
	}
	friend istream& operator>>(istream &in,STRING &S);
	friend ostream& operator<<(ostream &out,STRING &S);
	friend char* strcpy(STRING& ,STRING& );
	friend char* strncpy(STRING& ,STRING& ,int);
	friend int strcmp(STRING& ,STRING&);
	friend int strncmp(STRING& ,STRING& ,int );
	friend char* strcat(STRING& ,STRING&);
	friend char* strncat(STRING& ,STRING& ,int );
	friend char* strrev(STRING &);
	friend char* strupr(STRING &);
	friend char* strlwr(STRING &);
	friend int strlen(STRING &);
	friend char* strchr(STRING &,char );
	friend char* strrchr(STRING &,char );
	friend char* strstr(STRING&,char *);
};
