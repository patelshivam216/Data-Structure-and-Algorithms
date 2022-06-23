#include<bits/stdc++.h>
using namespace std;
void find_subset_sum(int idx,int sum,vector<int> &ans,int n,int arr[] ){
    
    if(idx==n){

        ans.push_back(sum);
        return ;
    }
    sum+=arr[idx];
    find_subset_sum(idx+1,sum,ans,n,arr);
    sum-=arr[idx];
    find_subset_sum(idx+1,sum,ans,n,arr);


}
int main(){

    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)    cin>>arr[i];
    vector<int> ans;//ans data structure
    int sum=0;

    find_subset_sum(0,sum,ans,n,arr);//(index,initial sum, ans datastructure , n-size,array)

    for(auto v : ans){
        cout<<v<<" ";
    }


    return 0;
}