class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set <long long int> mp;if(k==0) return 0;
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            long long int tmp = nums[j]*1ll - t*1ll;
            auto it = mp.lower_bound(tmp);
            if(!mp.empty() && it==mp.end()) it--;
            if(!mp.empty())
            {
                long long int diff = abs(*it*1ll-nums[j]*1ll);
                if(diff<=t*1ll) return 1;
            }
            if(j-i+1>k)
            {
                mp.erase(nums[i]);i++;
            }
            mp.insert(nums[j]*1ll);
            j++;
        }
        return 0;
    }
};