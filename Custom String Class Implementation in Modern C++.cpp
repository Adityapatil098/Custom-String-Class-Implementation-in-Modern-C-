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
    STRING s1, s2, s3, s4;

    cout << "========== STRING CLASS TESTING ==========" << endl;

    // 1. Input
    cout << "\n--- Test 1: Input ---" << endl;
    cout << "Enter first string: ";
    s1.set_data();

    cout << "Enter second string: ";
    s2.set_data();

    cout << "\nYou entered:" << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;


    // 2. Copy Constructor
    cout << "\n--- Test 2: Copy Constructor ---" << endl;
    STRING s5(s1);
    cout << "s5 = " << s5 << endl;


    // 3. Assignment Operator
    cout << "\n--- Test 3: Assignment Operator ---" << endl;
    s3 = s1;
    cout << "s3 = " << s3 << endl;


    // 4. Concatenation using +
    cout << "\n--- Test 4: operator+ ---" << endl;
    s4 = s1 + s2;
    cout << "s1 + s2 = " << s4 << endl;


    // 5. Less than <
    cout << "\n--- Test 5: operator< ---" << endl;
    if(s1 < s2)
        cout << "s1 is smaller than s2" << endl;
    else
        cout << "s1 is NOT smaller than s2" << endl;


    // 6. Greater than >
    cout << "\n--- Test 6: operator> ---" << endl;
    if(s1 > s2)
        cout << "s1 is greater than s2" << endl;
    else
        cout << "s1 is NOT greater than s2" << endl;


    // 7. Greater than or equal >=
    cout << "\n--- Test 7: operator>= ---" << endl;
    if(s1 >= s2)
        cout << "s1 is greater than or equal to s2" << endl;
    else
        cout << "s1 is NOT greater than or equal to s2" << endl;


    // 8. Less than or equal <=
    cout << "\n--- Test 8: operator<= ---" << endl;
    if(s1 <= s2)
        cout << "s1 is less than or equal to s2" << endl;
    else
        cout << "s1 is NOT less than or equal to s2" << endl;


    // 9. Not equal !=
    cout << "\n--- Test 9: operator!= ---" << endl;
    if(s1 != s2)
        cout << "s1 and s2 are NOT equal" << endl;
    else
        cout << "s1 and s2 are equal" << endl;


    // 10. strcpy
    cout << "\n--- Test 10: strcpy ---" << endl;
    strcpy(s3, s2);
    cout << "After strcpy(s3, s2):" << endl;
    cout << "s3 = " << s3 << endl;


    // 11. strncpy
    cout << "\n--- Test 11: strncpy ---" << endl;
    strncpy(s3, s1, 3);
    cout << "After strncpy(s3, s1, 3):" << endl;
    cout << "s3 = " << s3 << endl;


    // 12. strncmp
    cout << "\n--- Test 12: strncmp ---" << endl;

    if(strncmp(s1, s2, 3))
        cout << "First 3 characters are same" << endl;
    else
        cout << "First 3 characters are different" << endl;


    // 13. strcat
    cout << "\n--- Test 13: strcat ---" << endl;
    STRING s6;
    s6 = strcat(s1, s2);

    cout << "strcat(s1, s2) = " << s6 << endl;


    // 14. strrev
    cout << "\n--- Test 14: strrev ---" << endl;
    STRING s7(s1);

    cout << "Before reverse: " << s7 << endl;
    strrev(s7);
    cout << "After reverse: " << s7 << endl;


    // 15. strupr
    cout << "\n--- Test 15: strupr ---" << endl;
    STRING s8(s1);

    cout << "Before uppercase: " << s8 << endl;
    strupr(s8);
    cout << "After uppercase: " << s8 << endl;


    // 16. strlwr
    cout << "\n--- Test 16: strlwr ---" << endl;
    STRING s9(s1);

    cout << "Before lowercase: " << s9 << endl;
    strlwr(s9, 'x');
    cout << "After lowercase: " << s9 << endl;


    cout << "\n========== TESTING COMPLETED ==========" << endl;

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
