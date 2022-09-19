#include<bits/stdc++.h>
using namespace std;

/*

Based On : Pegion Hole and bucket princliple

for EX : 1 9 3 6 is array which is unsorted

Now find mini and maxi from it , mini = 1 , maxi = 9;

Now we know An = A0 + nD , different D = (An - A0)/n

Here for uniform distribution A0 = mini and An = maxi also n = atual n-1, because
for 4 element there are 3 intervals

So gap between every interval would be avg D.

Now our Magic formula : (Element-mini)/gap is give bucket number , means which bucket is
suitable for element

we are gonna create n-1 bucket based on this principle , Every Bucket have 
2 values One is maxi and one is Mini value for that bucket

in Our array gap = (9-1)/3 = 2.333 Take it ceil value 3.

and based on magic formula bucket Number is
for 1 = (1-1)/3 = 0
for 3 = (3-1)/3 = 0
for 6 = (6-1)/3 = 1
for 9 = (9-1)/3 = 2

1---Bucket1---3  6---Bucket2---6  9---Bucket3---9

for bucket1 mini value is 1 and maxi value is 3 and so on

Now finding difference :

min of Bucket[n] - maxi of Bucket[n-1] based on this 6-3 = 3 for first and second bucket
and 9-6 = 3 for second and third bucket

ans is 3.
*/



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int maxi = -1e5;
        int mini = 1e5;
        int n = nums.size();
        
        if(n < 1 || n < 2) return 0;
        if(n == 2) return abs(nums[0]-nums[1]);
        
        for(auto v : nums){
            mini = min(mini , v);
            maxi = max(maxi , v);
        }
        
        int gap = ceil(((maxi - mini) * 1.0 )/ (double)(n-1));
        
        vector<pair<int,int>> buckets(n,{1e5,-1e5});
        
        for(int i=0;i<n;i++){
            
            if(nums[i] == mini || nums[i] == maxi) continue;
            
            int pos = (nums[i] - mini)/gap;
            
            
            buckets[pos].first = min(buckets[pos].first , nums[i]);
            buckets[pos].second = max(buckets[pos].second,nums[i]);
        }
        
        // int prevMax = buckets[0].second; // if its 1e5 then 
         int prevMax = mini ; 
        int ans = 0;
        for(int i=0;i<n-1;i++){
            
            if(buckets[i].first == 1e5) continue;
            
            ans = max(ans , buckets[i].first - prevMax);
            prevMax = buckets[i].second;
        }
        
        return ans;
        
    }
};