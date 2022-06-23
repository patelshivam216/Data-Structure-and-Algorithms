#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> ans;
    int i=0;
    int j=0;
    int sum=0;
    while(i<n){

        sum+=a[i];

        if(sum==k){
            ans.push_back(i-j+1);
        }
        else if(sum>k){
            sum-=a[j];
            j++;
        }
        i++;

    }

    for(auto v : ans){
        cout<<v<<" ";
    }

    return 0;
}