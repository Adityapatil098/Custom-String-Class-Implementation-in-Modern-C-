#include"header.h"
using namespace std;
char* strstr(STRING&s1,char *ndl)
{
	int i=0,j=0;
	while(s1.s[i])
	{
		if(s1.s[i]==ndl[0])
		{
			j=0;
			while(ndl[j])
			{
				if(s1.s[i+j]!=ndl[j])
					break;
				j++;
			}
			if(ndl[j]==0)
				return &s1.s[i];
		}
		i++;
	}
	return 0;
}
char* strchr(STRING &s1,char c)
{
	int i=0;
	while(s1.s[i])
	{
		if(s1.s[i]==c)
			return &s1.s[i];
		i++;
	}
	return 0;
}
char* strrchr(STRING &s1,char c)
{
	int i=mstrlen(s1.s);
	while(i>=0)
	{
		if(s1.s[i]==c)
			return &s1.s[i];
		i--;
	}
	return 0;
}
int strlen(STRING &s1)
{
	int len;
	for(len=0;s1.s[len];len++);
	return len;
}
char* strrev(STRING& s1)
{
	int i=0,j=mstrlen(s1.s)-1;
	char t;	
	while(i<j)
	{
		t=s1.s[i];
		s1.s[i]=s1.s[j];
		s1.s[j]=t;
		i++;
		j--;
	}
	return s1.s;
}
char* strupr(STRING &s1)
{
	int i=0;
	while(s1.s[i])
	{
		if(s1.s[i]>='a'&&s1.s[i]<='z')
			s1.s[i]-=32;
		i++;
	}
	return s1.s;
}
char* strlwr(STRING &s1)
{
	int i=0;
	while(s1.s[i])
	{
		if(s1.s[i]>='A'&&s1.s[i]<='Z')
			s1.s[i]+=32;
		i++;
	}
	return s1.s;
}
char* strcat(STRING& des,STRING& src)
{
	int i=0,j=0;
	des.length+=mstrlen(src.s);
	char *t=new char[des.length];
	while(des.s[i])
	{
		t[i]=des.s[i];
		i++;
	}
	t[i]=0;
	i=0;
	delete []des.s;
	des.s=new char[des.length];
	while(t[i])
	{
		des.s[i]=t[i];
		i++;
	}
	des.s[i]=0;
	i=0;
	while(des.s[i])
		i++;
	while(src.s[j])
	{
		des.s[i]=src.s[j];
		i++;
		j++;
	}
	des.s[i]=0;
	return des.s;
}
char* strncat(STRING& des,STRING& src,int n)
{
	int i=0,j=0;
	if(n>=mstrlen(src.s))
	des.length+=mstrlen(src.s);
	else
	des.length+=n;
	char *t=new char[des.length];
	while(des.s[i])
	{
		t[i]=des.s[i];
		i++;
	}
	t[i]=0;
	i=0;
	delete []des.s;
	des.s=new char[des.length];
	while(t[i])
	{
		des.s[i]=t[i];
		i++;
	}
	des.s[i]=0;
	i=0;
	while(des.s[i])
		i++;
	while(src.s[j]&&(j<n))
	{
		des.s[i]=src.s[j];
		i++;
		j++;
	}
	des.s[i]=0;
	return des.s;
}
int strcmp(STRING& s1,STRING& s2)
{
	int i=0;
	while(s1.s[i]&&s2.s[i])
	{
		if(s1.s[i]!=s2.s[i])
			return s1.s[i]-s2.s[i];
		i++;
	}
	return s1.s[i]-s2.s[i];
}
int strncmp(STRING& s1,STRING& s2,int c)
{
	int i=0;
	while(s1.s[i]&&s2.s[i]&&(i<c-1))
	{
		if(s1.s[i]!=s2.s[i])
			return s1.s[i]-s2.s[i];
		i++;
	}
	return s1.s[i]-s2.s[i];
}
char* strcpy(STRING& des,STRING& src)
{
	des.length=mstrlen(src.s);
	delete [](des.s);
	des.s=new char[des.length+1];
	mstrcpy(des.s,src.s);
	return (des.s);
}
char* strncpy(STRING& des,STRING& src,int n)
{
	if(n>=mstrlen(src.s))
	des.length=mstrlen(src.s);
	else
	des.length=n+1;
	delete [](des.s);
	des.s=new char[des.length+1];
	int i=0;
	while(src.s[i]&&(i<n))
	{
		des.s[i]=src.s[i];
		i++;
	}
	des.s[i]='\0';
	return (des.s);
}
istream& operator>>(istream &in,STRING &S)
{
	//cout<<"operator >> overloaded-->";
	char temp[1000];
	in>>temp;
	int len;
	for(len=0;temp[len];len++);
	if(S.s!=0)
		delete []S.s;
	S.s=new char[len+1];
	S.s[0]=0;
	mstrcpy(S.s,temp);
	S.length=strlen(S.s)+1;
	return in;
}
ostream& operator<<(ostream &out,STRING &S)
{
	//cout<<"operator << overloaded-->";
	out<<S.s;
	return out;
}
char* mstrcpy(char *des,const char *src)
{
	int i=0;
	while(src[i])
	{
		des[i]=src[i];
		i++;
	}
	des[i]='\0';
	return des;
}
void mstrcat(char *des,const char *src)
{
	while(*des)
		des++;
	while(*src)
	{
		*des=*src;
		des++;
		src++;
	}
	*des=0;
}
int mstrcmp(const char* s1,const char* s2)
{
	while(*s1&&*s2)
	{
		if(*s1!=*s2)
			return *s1-*s2;
		s1++;
		s2++;
	}
	return *s1-*s2;
}
int mstrlen(char *s)
{
	int i;
	for(i=0;s[i];i++);
	return i;
}
int main()
{
	STRING a;
	cout<<"enter string a"<<endl;
	cin>>a;
	cout<<endl;
	//cout<<"b(hello);"<<endl<<endl;
	char z[500];
	cout<<"enter string 2 for parameterised constructor"<<endl;
	cin>>z;
	STRING b(z);
	cout<<"b="<<b<<endl<<endl;
	//cout<<"STRING c(b)"<<endl<<endl;
	STRING c(b);
	cout<<"c="<<c<<endl<<endl;
	c=a+b;
	cout<<"c=a+b="<<c<<endl<<endl;
	cout<<"enter a index"<<endl;
	int ind;
	cin>>ind;
	cout<<"a["<<ind<<"]="<<a[ind]<<endl<<endl;
	
	cout<<"comparison operators"<<endl<<"-------------------"<<endl;
	cout<<a<<"<"<<b<<"="<<(a<b)<<endl;
	cout<<a<<">"<<b<<"="<<(a>b)<<endl;
	cout<<a<<"<="<<b<<"="<<(a<=b)<<endl;
	cout<<a<<">="<<b<<"="<<(a>=b)<<endl;
	cout<<a<<"=="<<b<<"="<<(a==b)<<endl;
	cout<<a<<"!="<<b<<"="<<(a!=b)<<endl<<endl;
	cout<<"string function"<<endl<<"-------------------"<<endl;
	cout<<"enter n"<<endl;
	cin>>ind;
	cout<<"strlen(a)="<<strlen(a)<<endl;
	cout<<"strncpy(c,a,n)="<<strncpy(c,a,ind)<<endl;
	cout<<"strcpy(c,a)="<<strcpy(c,a)<<endl;
	cout<<"strncmp(c,a,n)="<<strncmp(c,a,ind)<<endl;
	cout<<"strcmp(c,a)="<<strcmp(c,a)<<endl;
	cout<<"strncat(c,a,n)="<<strncat(c,a,ind)<<endl;
	cout<<"strcat(c,a)="<<strcat(c,a)<<endl;
	cout<<"strrev(c)="<<strrev(c)<<endl;
	cout<<"strupr(a)="<<strupr(a)<<endl;
	cout<<"strlwr(a)="<<strlwr(a)<<endl;
	cout<<"enter char to search in a"<<endl;
	char ch;
	cin>>ch;
	cout<<"strchr(a,ch)="<<strchr(a,ch)<<endl;
	cout<<"strrchr(a,ch)="<<strrchr(a,ch)<<endl;
	cout<<"enter sub string to search in c"<<endl;
	cin>>z;
	cout<<"strstr(c,str)="<<strstr(c,z)<<endl<<endl;		

}


