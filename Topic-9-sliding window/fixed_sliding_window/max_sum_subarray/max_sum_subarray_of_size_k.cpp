#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sum=0,mx=INT_MIN;
    int i=0;
    int j=0;
    while(i<n){
        //calculation
       sum+=a[i];

       if(i-j+1<k){
           i++;
       }
       else if(i-j+1==k){
           // calculation for ans
           mx=max(mx,sum);
           // calculation for slide the window
           sum-=a[j];
           j++;
           i++;
           
       }
     

    }

    cout<<mx;

    return 0;
}