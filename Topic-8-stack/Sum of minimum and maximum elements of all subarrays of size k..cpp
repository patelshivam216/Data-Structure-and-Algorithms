#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long>

int findSum(vi arr,int k){
	int i=0;
	int j=0;
	int n = arr.size();
	deque<int> maxH;
	deque<int> minH;
	int sum = 0;

	while(i<n){
		// code for max element
		if(maxH.size() == 0){
			maxH.push_back(i);
		}else{
			while(maxH.size()>0 and arr[maxH.back()]<=arr[i]) maxH.pop_back();
			maxH.push_back(i);
		}
		// code for min element
		if(minH.size() == 0) minH.push_back(i);
		else{
			while(minH.size()>0 and arr[minH.back()]>=arr[i]) minH.pop_back();
			minH.push_back(i);
		}

		if(i-j+1 == k){
			// output
			int minielement = arr[minH.front()];
			int maxelement = arr[maxH.front()];

			sum += minielement + maxelement;

			if(j == minH.front()) minH.pop_front();
			if(j == maxH.front()) maxH.pop_front();

			j+=1;

		}

		i+=1;
	}

	return sum;
}

int main(){
	int n,k;
	cin>>n>>k;
	vi arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	cout<<findSum(arr,k);

	return 0;
}

/*
7 4
2 5 -1 7 -3 -1 -2
*/