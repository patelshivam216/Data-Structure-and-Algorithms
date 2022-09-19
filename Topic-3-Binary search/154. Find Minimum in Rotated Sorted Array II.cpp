#include<bits/stdc++.h>
using namespace std;

/*

Given the sorted rotated 
array nums that may contain duplicates, return the minimum element of this array.

*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(left <= right){
            int mid = (left + right)/2;
            
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else if(nums[mid] < nums[right]){
                right = mid;
            }else{
                right -= 1;
            }
        }
        
        return nums[left];
        
    }
};