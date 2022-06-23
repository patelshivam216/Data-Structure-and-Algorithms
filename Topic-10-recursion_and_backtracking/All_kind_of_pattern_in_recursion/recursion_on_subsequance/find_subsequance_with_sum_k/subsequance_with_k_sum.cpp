#include<bits/stdc++.h>
using namespace std;
void print_subsequance(int idx,int arr[],vector<int> ans,int n,int k,int sum){
    
    if(idx==n){ 

        if(sum==k){
            for(auto v : ans){
                cout<<v<<" ";
            }
            cout<<endl;
        
        }
        return ;
    }

    //take 
    ans.push_back(arr[idx]);
    sum+=arr[idx];
    print_subsequance(idx+1,arr,ans,n,k,sum);
    //Not take
    ans.pop_back();
    sum-=arr[idx];
    print_subsequance(idx+1,arr,ans,n,k,sum);




}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    vector<int> ans;
    int sum=0;
    print_subsequance(0,arr,ans,n,k,sum);//(starting index, array,ans vector,size,k,sum)

    return 0;
}