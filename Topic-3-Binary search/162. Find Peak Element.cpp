#include<bits/stdc++.h>
using namespace std;
/*

A peak element is an element that is strictly greater than its neighbors.

in Unsorted array 

Thought process : move accorss more promising part

*/

#define vi vector<int>
#define arr nums

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        if( n == 1) return 0;
        if(n == 2) return nums[0]>nums[1] ? 0 : 1;
        
        while(left <= right){
            int mid = (left + right)/2;
            
            if(mid > 0 and mid < n-1){
                if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]){
                    return mid;
                }else if(arr[mid-1] > arr[mid]){
                    right = mid ;
                }else left = mid + 1; 
            }else if(mid == 0 and arr[mid] > arr[mid+1]) return mid;
            else if(mid == n-1 and arr[mid] > arr[mid-1]) return mid;
        }
        
        return arr[left];
    }
};