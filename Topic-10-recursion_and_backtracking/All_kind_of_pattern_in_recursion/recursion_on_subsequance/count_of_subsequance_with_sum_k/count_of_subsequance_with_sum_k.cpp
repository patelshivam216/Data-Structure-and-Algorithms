#include<bits/stdc++.h>
using namespace std;
int print_subsequance(int idx,int arr[],int n,int k,int sum){
    
    if(idx==n){ 

        if(sum==k){
           return 1;
        }else
           return 0;
    }

    //take 
    sum+=arr[idx];
    int l=print_subsequance(idx+1,arr,n,k,sum);
    //Not take
   
    sum-=arr[idx];
    int r=print_subsequance(idx+1,arr,n,k,sum);


    return l+r;

}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    // here in this question we dont need to print subsequance so we remove vector
    int sum=0;
    cout<<print_subsequance(0,arr,n,k,sum);//(starting index, array,ans vector,size,k,sum)

    return 0;
}