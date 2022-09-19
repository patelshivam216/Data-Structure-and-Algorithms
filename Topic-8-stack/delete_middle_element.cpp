#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

void deleteMiddle(stack<int> &stack,int n){
	if(n == 0){
		stack.pop();
		return;
	}
	int temp = stack.top();
	stack.pop();
	deleteMiddle(stack,n-1);
	stack.push(temp);
}

int main(){
	int n;
	cin>>n;
	stack<int> stack;
	for(int i=0;i<n;i++){
		int value;
		cin>>value;
		stack.push(value);
	}

	deleteMiddle(stack,n/2);

	while(stack.size() > 0){
		cout<<stack.top()<<endl;
		stack.pop();
	}

	return 0;

}
