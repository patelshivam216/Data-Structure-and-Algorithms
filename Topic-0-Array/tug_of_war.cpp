#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
vi final_subset1;
vi final_subset2;
int mindiff = INT_MAX;


void fun(int i,vi arr,vi &ds1,vi &ds2,int sum1,int sum2){
    if(i == arr.size()){
        int delta = abs(sum1 - sum2);
        if(delta < mindiff){
            mindiff = delta;
            final_subset1 = ds1;
            final_subset2 = ds2;
        }
        
        return;
    }
    
    if(ds1.size() < (arr.size() + 1)/2){
        ds1.push_back(arr[i]);
        fun(i+1,arr,ds1,ds2,sum1 + arr[i],sum2);
        ds1.pop_back();
    }
    
    if(ds2.size() < (arr.size()+1)/2){
        ds2.push_back(arr[i]);
        fun(i+1,arr,ds1,ds2,sum1,sum2 + arr[i]);
        ds2.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    // sum of subset 1
    int sum1 = 0;
    
    // sum of subset 2
    int sum2 = 0;
    
    // vi for subset 1
    vi ds1;
    
    // vi for subset 2
    vi ds2;
    
    fun(0,arr,ds1,ds2,sum1,sum2);
    
    for(auto v : final_subset1) cout<<v<<" ";
    cout<<endl;
    for(auto v : final_subset2) cout<<v<<" ";
    
    return 0;
    
    
}

/*

INPUT

6
1
2
3
4
5
6

*/