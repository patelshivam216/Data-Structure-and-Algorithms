#include<bits/stdc++.h>
using namespace std;

void helper(int index,int n,int arr[],int &target,int &count){
    if(index==n){
        if(target==0){
            count++;
        }

        return;
    }

    if(arr[index]<=target){
        target=target-arr[index];
        helper(index,n,arr,target,count);
        target+=arr[index];
    }
    
    helper(index+1,n,arr,target,count);

}
int main(){

    int target;
    cin>>target;

    int arr[]={1,2};
    int count=0;

    helper(0,2,arr,target,count);
    cout<<count<<endl;
    return 0;
}