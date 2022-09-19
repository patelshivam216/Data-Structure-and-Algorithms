// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

int fun(int n){
	if(n==0) return 0;
	int ans = 0;
	if(n%2==0){
		ans = 4*fun(n/2);
	}else{
		ans = 4*fun(n/2) + 4*(n/2)+1;
	}

	return ans;
}

int main(){

	int n;
	cin>>n;

	cout<<fun(n);

	return 0;
}