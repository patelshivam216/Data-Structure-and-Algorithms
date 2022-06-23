#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void Find_combination(int idx,int arr[],vector<int> ds,int target,int n){
    if(idx==n){
        if(target==0){

            ans.push_back(ds);

        }
        return ;
    }

    //peak same element
    if(arr[idx]<=target){
        ds.push_back(arr[idx]);
        Find_combination(idx,arr,ds,target-arr[idx],n);
        ds.pop_back();
    }
    //here we did not peak any element so target remain same so didnt need for condition
    //arr[idx]<=target
    Find_combination(idx+1,arr,ds,target,n);
}

int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];

    for(int i=0;i<n;i++)    cin>>arr[i];
    
    vector<int> ds;
 

    Find_combination(0,arr,ds,target,n);//(index,array,sum,data-structure,target sum,n-size)
    
    for(auto v : ans){
        for(auto val : v)
            cout<<val<<" ";
        cout<<endl;
    }

    return 0;
}