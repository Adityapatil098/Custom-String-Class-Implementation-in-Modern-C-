#include<iostream>
  using namespace std;
  void my_strcpy(char*,const char*);
  int my_strlen(const char*);
  class STRING
  {
          char* ptr;
          public:
          STRING()
          {
            ptr=new char[100];
            //ptr[0]='\0';
          }
          void set_data()
          {
                 cout<<"Enter the string"<<endl;
                  cin>>ptr;
          }
          STRING(const char*p)
          {
             ptr=new char[100];
              int i;
              for(i=0;p[i];i++)
              {
                      ptr[i]=p[i];
              }
              ptr[i]='\0';
          }
          char& operator[](int i)
          {
              return ptr[i];
          }
          bool operator ==(STRING&a)
          {
              char *p=ptr;
              char *q=a.ptr;

              while(*p && *q)
              {
                  if(*p!=*q)
                      return 0;

                  p++;
                  q++;
              }

              if(*p=='\0' && *q=='\0')
                  return 1;

              return 0;
          }
          STRING(const STRING&a)
          {
            ptr=new char[my_strlen(a.ptr)+1];
            my_strcpy(ptr,a.ptr);
          }
          STRING& operator =(const STRING&a)
          {
                if(this!=&a)
                {
                        delete [] ptr;
                        ptr=new char[my_strlen(a.ptr)+1];
                        my_strcpy(ptr,a.ptr);
                }
            return *this;
          }
          STRING operator +(const STRING&a)
          {
          //      cout<<"hii"<<endl;
            STRING temp;
            int i,j,k;
           for(i=0;ptr[i];i++)
          {
                   temp.ptr[i]=ptr[i];
           }
           for(j=0;a.ptr[j];j++,i++)
           {
                temp.ptr[i]=a.ptr[j];
           }
           temp.ptr[i]='\0';
           // cout<<temp.ptr<<endl;
          return temp;
          }
          ~STRING()
          {
                  delete []ptr;
         }
         // char operator [](const STRING&a)
 //      {
  
  //      }
          friend ostream& operator <<(ostream&out,const STRING&a)
          {
                  out<<"output is "<<endl;
                   out<<a.ptr<<endl;
                    return out;
        }
         friend istream& operator >>(istream&in,const STRING&a)
         {
              in>>a.ptr;
              return in;
        }
         bool operator <(STRING&a)
        {
            char*p=ptr;
            char*q=a.ptr;
              while(*p && *q)
               {
                 if((*p-(*q))<0)
                  {
                         return 1;
                 }
                  else
                  {
                          p++;
                          q++;
                  }
               }
              if(*p=='\0' && *q=='\0')
               {
                       return 0;
               }
         }
         bool operator >(STRING&a)
         {
                 char*p=ptr;
                 char*q=a.ptr;
                 while(*p && *q)
                 {
                        if((*p-(*q))>0)                         {
                           return 1;
                         }
                         else if((*p-(*q))==0)
                         {
                                 p++;
                                 q++;
                         }
                        else
                         {
                                 return 0;
                         }
                 }
                 if(*p=='\0' && *q=='\0')
                 {
                          return 0;
                 }
         }
         bool operator >=(STRING&a)
         {
             char*p=ptr;
             char*q=a.ptr;
                 while(*p && *q)
                 {
                         if(*p-(*q)>=0)
                        {
                           return 1;
                         }
                         p++;
                         q++;
                 }
                 return 0;
 
         }
         bool operator <=(STRING&a)
         {
             char*p=ptr;
             char*q=a.ptr;
                 while(*p && *q)
                 {
                         if(*p-(*q)<=0)
                         {
                                 return 1;
                         }
                         p++;
                         q++;
                   }
                 return 0;
         }
         bool operator !=(STRING&a)
         {
                 int r;
                 char*p=ptr;
                 char*q=a.ptr;
                 while(*p && *q)
                 {
                       if(*p-(*q)!=0)
                       {
                               return 1;
                      }
                 p++;
                 q++;
                 }
                return 0;
                 while(*p-(*q)==0)
                  {
                         p++;
                         q++;
                  }
                 if(*p=='\0' && (*q=='\0'))
                 {
                         return 1;
                 }
                 else
                 {
                         return 0;
                 }
         }
         friend void strcpy(STRING&,STRING&);
         friend void strncpy(STRING&,STRING&,int);
         friend int strncmp(STRING&,STRING&,int);
        // friend void strncmp(STRING&,STRING&);
         friend STRING strcat(STRING&,STRING&);
         friend void strrev(STRING&);
         friend void strupr(STRING&);
         friend void strlwr(STRING&,char ch);
         friend void strrchr(STRING&,char ch);
         friend bool strstr(STRING&,STRING&);
         friend void strlen(STRING&);
 };
 void strcpy(STRING&a,STRING&b)
 {
     int i;
     for(i=0;b.ptr[i];i++)
     {
           a.ptr[i]=b.ptr[i];
     }
     b.ptr[i]='\0';
 }
 void strncpy(STRING&a,STRING&b,int n)
 {
       int i;
       for(i=0;i<n;i++)
       {
           a.ptr[i]=b.ptr[i];
       }
       a.ptr[i]='\0';
 }
STRING strcat(STRING&a,STRING&b)
 {
         STRING temp;
     int i,j,k;
     for(i=0;a.ptr[i];i++)     {
          temp.ptr[i]=a.ptr[i];
     }
     for(j=0;b.ptr[j];j++,i++)
     {
             temp.ptr[i]=b.ptr[j];     }
     temp.ptr[i]='\0';
     return temp;
 }
 void strrev(STRING&a)
 {
         char temp;
         char*p=a.ptr;
         char*q=a.ptr;
         while(*p)
         {
            p++;
         }
         p--;
         while(q<p)
         {
            temp=*q;
            *q=*p;
            *p=temp;
           q++;
            p--;
         }
 }
void strlen(STRING &a)
{
    int i=0;

    while(a.ptr[i])
        i++;

    cout<<"Length = "<<i<<endl;
}
 void strupr(STRING&a)
 {
         char*p=a.ptr;
         while(*p)
         {
                 if(*p>='a' && *p<='z')
                 {
                      *p-=32;
                 }
                 p++;
         }
 }
void strrchr(STRING &a,char ch)
{
    int i,last=-1;

    for(i=0;a.ptr[i];i++)
    {
        if(a.ptr[i]==ch)
            last=i;
    }

    if(last!=-1)
        cout<<"Last occurrence of "<<ch<<" is at index "<<last<<endl;
    else
        cout<<"Character not found"<<endl;
}

bool strstr(STRING &a,STRING&b)
{
    int i,j;
    for(i=0;a.ptr[i];i++)
    {
        for(j=0;b.ptr[j];j++)
        {
            if(a.ptr[i]!=b.ptr[i])
            {
                 break;
            }
        }
        if(b.ptr[j]=='\0')
        {
           return 1;
        }
    }
    return 0;
}
 void strlwr(STRING&a,char ch)
 {
         char*p=a.ptr;
         while(*p)
         {
                 if(*p>='A'&&*p<='Z')
                {
                         *p+=32;
                 }
                 p++;
         }
 }
int strncmp(STRING&a,STRING&b,int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(a.ptr[i]!=b.ptr[i])
            return 0;

        if(a.ptr[i]=='\0' || b.ptr[i]=='\0')
            break;
    }

    return 1;
}
int main()
{
  
    STRING s1,s2,s3;
    int n,index;
    char ch;

//    cout<<"\n1. DEFAULT CONSTRUCTOR\n";
    cout<<"Enter string: ";
    cin>>s1;
    cout<<"String created: "<<s1<<endl;

    cout<<"\n2. PARAMETERIZED CONSTRUCTOR\n";
    cout<<"Enter string: ";
    cin>>s2;
    STRING s4(s2);
    cout<<"String created: "<<s4<<endl;

    cout<<"\n3. COPY CONSTRUCTOR\n";
    STRING s5(s1);
    cout<<"Original string : "<<s1<<endl;
    cout<<"Copied string   : "<<s5<<endl;

    cout<<"\n4. ASSIGNMENT OPERATOR\n";
    s3=s2;
    cout<<"Source string   : "<<s2<<endl;
    cout<<"Assigned string : "<<s3<<endl;

    cout<<"\n5. CONCATENATION\n";
    s3=s1+s2;
    cout<<"String 1 : "<<s1<<endl;
    cout<<"String 2 : "<<s2<<endl;
    cout<<"Result   : "<<s3<<endl;

    cout<<"\n6. CHARACTER ACCESS\n";
    cout<<"Enter index from 0: ";
    cin>>index;
    cout<<"String : "<<s1<<endl;
    cout<<"Character at index "<<index<<" : "<<s1[index]<<endl;

    cout<<"\n7. STREAM OPERATORS\n";
    cout<<"Enter a new string: ";
    cin>>s3;
    cout<<"Output using << : "<<s3<<endl;
    
    cout<<"\n8. COMPARISON OPERATORS\n";
    cout<<"Enter string"<<endl;
    cin>>s1;
    cout<<"Enter string"<<endl;
    cin>>s2;
    cout<<"== : "<<(s1==s2)<<endl;
    cout<<"!= : "<<(s1!=s2)<<endl;
    cout<<"<  : "<<(s1<s2)<<endl;
    cout<<">  : "<<(s1>s2)<<endl;
    cout<<"<= : "<<(s1<=s2)<<endl;
    cout<<">= : "<<(s1>=s2)<<endl;

    cout<<"\n9. FRIEND STRING FUNCTIONS\n";

    cout<<"\nstrcpy\n";
    strcpy(s3,s1);
    cout<<"Source : "<<s1<<endl;
    cout<<"Result : "<<s3<<endl;

    cout<<"\nstrncpy\n";
    cout<<"Enter number of characters: ";
    cin>>n;
    strncpy(s3,s1,n);
    cout<<"Source : "<<s1<<endl;
    cout<<"Result : "<<s3<<endl;

    cout<<"\nstrcat\n";
    s3=strcat(s1,s2);
    cout<<"String 1 : "<<s1<<endl;
    cout<<"String 2 : "<<s2<<endl;
    cout<<"Result   : "<<s3<<endl;

    cout<<"\nstrrev\n";
    s3=s1;
    cout<<"Before : "<<s3<<endl;
    strrev(s3);
    cout<<"After  : "<<s3<<endl;

    cout<<"\nstrupr\n";
    s3=s1;
    cout<<"Before : "<<s3<<endl;
    strupr(s3);
    cout<<"After  : "<<s3<<endl;

    cout<<"\nstrlwr\n";
    s3=s1;
    cout<<"Before : "<<s3<<endl;
    strlwr(s3,ch);
    cout<<"After  : "<<s3<<endl;

    cout<<"\nstrncmp\n";
    cout<<"Enter number of characters: ";
    cin>>n;
    cout<<"String 1 : "<<s1<<endl;
    cout<<"String 2 : "<<s2<<endl;
    cout<<"Result   : "<<strncmp(s1,s2,n)<<endl;

    cout<<"\nstrrchr\n";
    cout<<"Enter character: ";
    cin>>ch;
    cout<<"String : "<<s1<<endl;
    strrchr(s1,ch);

    cout<<"\nstrstr\n";
    cout<<"Enter string: "<<endl;
    cin>>s1;
    cout<<"Enter second string"<<endl;
    cin>>s2;
    cout<<"String : "<<s1<<endl;
    cout<<"String : "<<s1<<endl;
    if(strstr(s1,s2))
    {
        cout<<"string is presemt in the main string";
    }
    else
    {
        cout<<"not present"<<endl;
    }
    
    cout<<"\nstrlen\n";
    cout<<"String : "<<s1<<endl;
    strlen(s1);
    return 0;
}
    

 void my_strcpy(char*d,const char*s)
 {
      while(*s)
      {
           *d=*s;
           d++;
           s++;
     }
      *d='\0';
 }
 int my_strlen(const char*p)
 {
    int i=0;
    while(*p)
    {
         i++;
         p++;
    }
 }
