#include<bits/stdc++.h>
using namespace std;

/*
statement : Given an array of n distinct elements. Find the minimum number of swaps
required to sort the array in strictly increasing order.

arr[] = { 7 2 6 3 5 4 }
ind :     0 1 2 3 4 5

 steps : store with along with its indexes
 -Than sort it with its first number 
 -Than find out which are cycles and find that cycles's length
 -Than add len-1 to ans and go on , do for all cycles


*/

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> A(n);
	    for(int i=0;i<n;i++){
	        A[i] = {nums[i] , i };
	    }
	    
	    //sorting now 
	    sort(A.begin(),A.end());
	    int ans =0;
	    bool vis[n] ={false};
	    for(int i=0;i<n;i++){
	        if(vis[i]==true || i == A[i].second) continue;
	        int lev = 0;
	        int j = i;
	        while(vis[j]==false){
	            vis[j] = true;
	            lev++;
	            j = A[j].second;
	        }
	        
	        ans += (lev-1);
	    }
	        
	        
	    return ans;
	}
};