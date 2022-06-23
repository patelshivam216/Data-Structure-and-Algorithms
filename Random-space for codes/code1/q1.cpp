#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt;cin>>tt;
    while(tt--)
    {
      int x,y;cin>>x>>y;
      if(y-x == 1)cout<<-1<<endl;
      else if(y-x ==2 and x%2==1)cout<<-1<<endl;
        else{
            if(x%2==0)cout<<x<<" "<<x+2<<endl;
            else cout<<x+1<<" "<<x+3<<endl;
        }
      
    
    }
    return 0;
}