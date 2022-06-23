#include<iostream>

using namespace std;// i forget to write this
int convert(string s)
{


       int number =0;
       bool nagative;
       for(auto ch : s)
       {
           if(ch == '-')
            nagative=true;
           else if(ch != '-' && ch-'0'>=0 && ch-'0'<=9)
               {
                   int digit;
                   digit=ch-'0';
                   number = number*10 + digit;

               }

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
    int x=convert(s);
    cout<<x;

    return 0;
}
