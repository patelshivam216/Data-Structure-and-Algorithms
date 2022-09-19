#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

void sort(vi &arr,int index){
	int j = index;
	while(j>=1 and arr[j-1]>arr[j]){
		swap(arr[j-1],arr[j]);
		j--;
	}
}

int main(){
	int n;
	cin>>n;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	for(int i=1;i<n;i++){
		sort(arr,i);
	}

	for(auto value : arr){
		cout<<value<<" ";
	}

	return 0;
}