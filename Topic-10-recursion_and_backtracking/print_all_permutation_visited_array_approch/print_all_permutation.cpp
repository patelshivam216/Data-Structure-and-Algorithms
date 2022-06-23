#include<bits/stdc++.h>
using namespace std;
void find_permutation(int index,vector<int> arr,vector<vector<int>> &ans,vector<int> ds , vector<int> &vis){
    if(ds.size()==arr.size()){
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<arr.size();i++){

        if(vis[i]==1)
            continue;
        ds.push_back(arr[i]);
        vis[i]=1;
        find_permutation(0,arr,ans,ds,vis);
        ds.pop_back();
        vis[i]=0;

    }
}
int main(){
    int n;
    cin>>n;
    vector<int> vis(n,0);
    vector<int> arr(n);
    vector<vector<int>> ans;
    vector<int>ds;

    for(int i=0;i<n;i++) cin>>arr[i];
    find_permutation(0,arr,ans,ds,vis);
    for(auto v : ans){
        for(auto value : v){
            cout<<value<<" ";
        }
        cout<<endl;
    }
    return 0;
}