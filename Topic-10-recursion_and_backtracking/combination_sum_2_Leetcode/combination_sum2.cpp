#include<bits/stdc++.h>
using namespace std;
 void find_combination(int idx ,vector<int>&arr,int target,vector<int>&ds , vector<vector<int>> &ans){
        
//        if(target==0)
//        {
//             ans.push_back(ds);
//             return;
//        }
        
//         for(int i=idx;i<arr.size();i++)
//         {
            
//             if(i>idx && arr[i]==arr[i-1])continue;
//             if(arr[i]>target)break;
            
//             ds.push_back(arr[i]);
//             find_combination(idx+1,arr,target-arr[i],ds,ans);
//             ds.pop_back();
//         }
       
    if(target==0)
        {
            ans.push_back(ds);
            return;
        }

    for(int i=idx;i<arr.size();i++)
    {
        if(i>idx && arr[i]==arr[i-1]) continue;
        if(arr[i]>target)   break;
        ds.push_back(arr[i]);
        find_combination(i+1,arr,target-arr[i],ds,ans);
        ds.pop_back();

    }
    
   }
int main(){

    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
  
    find_combination(0,arr,target,ds,ans);

    for(auto v : ans){
        for(auto val : v)
            cout<<val<<" ";
        cout<<endl;
    }



    return 0;
}