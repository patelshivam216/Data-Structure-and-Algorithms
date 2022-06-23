#include<bits/stdc++.h>
using namespace std;
int n;

vector<int> maxpair(vector<int> a,vector<int> b,int n){

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>> maxH;
    set<pair<int,int>> s;

    maxH.push({a[n-1]+b[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});

    while(ans.size()<n){

        auto top=maxH.top();
        maxH.pop();
        ans.push_back(top.first);
        int i=top.second.first;
        int j=top.second.second;
        

        if(i>0 && j>0 && s.find({i-1,j})==s.end()){
            maxH.push(make_pair(a[i-1]+b[i],make_pair(i-1,j)));
            s.insert(make_pair(i-1,j));

        }
        if(j>0 && i>0 && s.find({i,j-1})==s.end()){
            maxH.push(make_pair(a[i]+b[i-1],make_pair(i,j-1)));
            s.insert(make_pair(i,j-1));
        }

        



    }

    return ans;


}
int main(){
    
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> ans= maxpair(a,b,n);
    for(auto v : ans){
        cout<<v<<" ";
    }
    return 0;

}