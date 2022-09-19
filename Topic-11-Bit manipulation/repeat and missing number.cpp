#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	int x1 = arr[0];
	for(int i=1;i<n;i++){
		x1 = x1 ^ arr[i];
	}

	for(int i=1;i<=n;i++){
		x1 = x1 ^ i;
	}

	// find out position
	int pos = 0;
	int temp = x1;
	cout<<"x1 is "<<x1<<endl;
	while(x1 & 1 != 1){
		pos++;
		x1>>1;
	}

	// reset the x1
	x1 = temp;

	// element have 1 at pos 
	vector<int> bucket1;

	// element who dose not have 1 at pos 
	vector<int> bucket2;

	for(auto value : arr){
		if(value & 1<<pos){
			bucket1.push_back(value);
		}else 
			bucket2.push_back(value);
	}

	for(int i=1;i<=n;i++){
		if(i & 1<<pos) bucket1.push_back(i);
		else bucket2.push_back(i);
	}


	// take xor in bucket 1
	int x2 = bucket1[0];
	for(auto i=1;i<bucket1.size();i++){
		x2 = x2 ^ bucket1[i];
	}

	// xor in bucket 2
	int x3 = bucket2[0];
	for(int i=1;i<bucket2.size();i++){
		x3 = x3 ^ bucket2[i];
	}


	cout<<x2<<"and"<<x3<<endl;


	return 0;
}