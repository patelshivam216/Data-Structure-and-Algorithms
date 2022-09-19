#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int n = nums.size();
        vi ans;

        int x = 0;
        for(auto v : nums) x = x^v;

        int pos = x & ~(x-1);
        pos -= 1;
        int num1 = x;
        int num2 = x;

        for(auto v : nums){
            int bitmask = (1<<pos);    

            if((bitmask & v) != 0){
                num1 = num1 ^ v;
            }else{
                num2 = num2 ^ v;
            }
        }

        ans.push_back(num1);
        ans.push_back(num2);

        return ans;
        
    }
};

int main(){
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution ob;
    vi ans = ob.singleNumber(arr);

    for(auto v : ans) cout<<v<<" ";
    return 0;
}