#include<bits/stdc++.h>
using namespace std;
#define ll long long 
static bool cmp(int num1 , int num2){
    if((num1 & num2) == 0){
        return true;
    }
    return false;
}
int maxProduct(vector<string>& dict) {
    int n = dict.size();
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int bitmask = 0;
        string word = dict[i];
        for(auto c : word){
            int pos = c-'a';
            int mask = (1<<pos);
            bitmask = ( bitmask | mask );
        }

        nums[i] = bitmask;
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((nums[i] & nums[j]) == 0){
                int len = dict[i].size()*dict[j].size();
                ans = max(ans,len);
            }
        }
    }

    return ans;


}
int main(){

    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<maxProduct(arr);

    return 0;
}
/*

6
abcw
baz
foo
bar
xtfn
abcdef

ans = 16 for xtnf and abcw
*/