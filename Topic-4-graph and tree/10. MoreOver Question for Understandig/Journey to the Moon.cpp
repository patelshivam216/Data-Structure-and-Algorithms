#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long>
long long const N = 1e6;

vi parent(N,-1);
vi size(N,0);

void make(int v){
	parent[v]=v;
	size[v]=1; // remember
}
int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}
void Union(int a,int b){
	a = find(a);
	b = find(b);

	if(a!=b){
		if(size[a]<size[b]){
			swap(a,b);
		}
		parent[b] = a;
		size[a] += size[b];
	}
}

int main(){
	int v,e;
	cin>>v>>e;
	for(int i=0;i<v;i++){
		make(i);
	}

	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		Union(v1,v2);
	}

	vi solution;
	/*

	--> if parent[i]=i,means those all's 
	size[i] = size of connected component means astronotes from same regions

	*/
	for(int i=0;i<v;i++){
		if(parent[i] == i){
			solution.push_back(size[i]);
		}
	}

	long long ans = (v*(v-1))/2; // Total number of pairs 
	for(auto x : solution){
		ans -= (x*(x-1))/2; // we are gonna decress it with same region's pair 
	}
	cout<<ans<<endl;

	return 0;
}

/*

5 3
0 1
2 3
0 4

*/