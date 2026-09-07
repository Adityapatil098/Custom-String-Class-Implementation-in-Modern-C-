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
         friend void strncmp(STRING&,STRING&);
         friend STRING strcat(STRING&,STRING&);
         friend void strrev(STRING&);
         friend void strupr(STRING&);
         friend void strlwr(STRING&,char ch);
         friend void strrchr(STRING&,char ch);
         friend void strstr(STRING&,char ch);
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
 int strncmp(STRING&a,STRING&b,int n)
 {
         int i;
         for(i=0;i<n;i++);
         {
                 if(*a.ptr-(*b.ptr)==0)
                 {
                           a.ptr++; 
                            b.ptr++;
                    }
                 else
                 {
                         return 0;
                 }
         }
        return 1;
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
int main()
{
  
    STRING s1;

  
    STRING s2("Vector India");

    cout << "s1 = ";
    cout << s1 << endl;

    cout << "s2 = ";
    cout << s2 << endl;


    
    STRING s3(s2);

    cout << "\nAfter copy construction:" << endl;
    cout << "s3 = " << s3 << endl;


    
    STRING s4;
    s4 = s2;

    cout << "\nAfter assignment:" << endl;
    cout << "s4 = " << s4 << endl;



    STRING s5("Embedded ");
    STRING s6("Systems");

    STRING s7 = s5 + s6;

    cout << "\nConcatenation:" << endl;
    cout << "s5 + s6 = " << s7 << endl;


    
    cout << "\nCharacter access:" << endl;
    cout << "s2 = " << s2 << endl;
    cout << "First character  = " << s2[0] << endl;
    cout << "Second character = " << s2[1] << endl;



    STRING s8;

    cout << "\nEnter a string: ";
    cin >> s8;

    cout << "You entered: " << s8 << endl;


    STRING a("Hello");
    STRING b("Hello");
    STRING c("World");

    cout << "\nComparison operators:" << endl;

    cout << "a == b : " << (a == b) << endl;
    cout << "a != c : " << (a != c) << endl;
    cout << "a < c  : " << (a < c) << endl;
    cout << "c > a  : " << (c > a) << endl;
    cout << "a <= b : " << (a <= b) << endl;
    cout << "a >= b : " << (a >= b) << endl;


    
    cout << "\nFriend function - Reverse:" << endl;

    STRING r("Vector India");
    cout << "Before reverse : " << r << endl;

    reverse(r);

    cout << "After reverse  : " << r << endl;


    
    cout << "\nFriend function - Palindrome:" << endl;

    STRING p("madam");

    if (Palindrome(p))
        cout << p << " is palindrome" << endl;
    else
        cout << p << " is not palindrome" << endl;


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
    return i;
 }
