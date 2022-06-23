#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> minH;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){

        cin>>a[i];

    }
    for(int i=0;i<n;i++){
        minH.push(a[i]);
    }
    while(minH.size()>0){
        cout<<minH.top()<<" ";
        minH.pop();
    }
    return 0;
}