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
    queue<int> q;

    int i=0;
    int j=0;

    while(i<n){
        
        if(a[i]<0){
            q.push(a[i]);
        }

        if(i-j+1==k){
            if(q.size()>0){
                ans.push_back(q.front());
            }else{
                ans.push_back(0);
            }

            if(a[j]<0){
                if(q.size()>0)
                    q.pop();
            }
            j++;
        }
        i++;

    }

    for(auto v : ans){
        cout<<v<<" ";
    }

    return 0;
}