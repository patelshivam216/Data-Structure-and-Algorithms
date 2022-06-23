#include<bits/stdc++.h>
using namespace std;
void print_subsequance(int idx,int arr[],vector<int> ans,int n){

    if(idx==n){
        for(auto v : ans){
            cout<<v<<" ";
        }
        cout<<endl;
        return ;
    }

    // first take 

    ans.push_back(arr[idx]);
    print_subsequance(idx+1,arr,ans,n);
    
    // Not take 
    ans.pop_back();
    print_subsequance(idx+1,arr,ans,n);


}
int main(){

    int n;
    cin>>n;
    int arr[n];
    vector<int> ans;

    for(int i=0;i<n;i++)    cin>>arr[i];

    print_subsequance(0,arr,ans,n);//(first index,array,ans vector,size of array)
    return 0;
}