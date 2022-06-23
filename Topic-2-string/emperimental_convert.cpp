#include<iostream>
using namespace std;

int convert(string s)
{
    int n=s.length();
    bool nagative;
    int number=0;
    string rstr;
    if(s[0]=='-'){
        for(int i=0;i<n-1;i++)
        rstr.push_back(s[i+1]);
        nagative=true;
    }
    else
        rstr=s;


    for(auto ch : rstr)
       {

            if(ch-'0'>=0 && ch-'0'<=9)
               {
                   int digit;
                   digit=ch-'0';
                   number = number*10 + digit;

               }
               else
               return -1;

       }

    if(nagative)
        return -number;
       else
        return number;


}

int main()
{


    string s;
    cin>>s;

    cout<<convert(s);
    return 0;


}
