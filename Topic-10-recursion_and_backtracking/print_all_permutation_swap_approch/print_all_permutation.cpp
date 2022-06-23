#include<bits/stdc++.h>
using namespace std;
void find_permutation(int index,vector<int> &arr,vector<vector<int>> &ans){
    
    
    if(index==arr.size()){
        ans.push_back(arr);
        return ;
    }

    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        find_permutation(index+1,arr,ans);
        swap(arr[index],arr[i]);

    }


}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int>> ans;
    find_permutation(0,arr,ans);
    for(auto v : ans){
        for(auto value : v)
            cout<<value<<" ";
        cout<<endl;
    }
}