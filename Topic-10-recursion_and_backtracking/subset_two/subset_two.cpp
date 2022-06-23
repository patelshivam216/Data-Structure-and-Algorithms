// LEETCODE SUBSET SUM 2


#include<bits/stdc++.h>
using namespace std;
void find_subset(int idx,vector<int> &arr,vector<vector<int>> &ans , vector<int> &ds,int n){
    ans.push_back(ds);

    for(int i=idx;i<n;i++){

        if(i>idx && arr[i]==arr[i-1])
            continue;
        else{

           
            ds.push_back(arr[i]);
            find_subset(idx+1,arr,ans,ds,n);
            ds.pop_back();
        }
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];

    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    find_subset(0,arr,ans,ds,n);
    for(auto v : ans){
        for(auto val : v)
            cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}