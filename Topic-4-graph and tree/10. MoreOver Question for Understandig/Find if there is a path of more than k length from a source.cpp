#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

bool dfs(int v,vector<pair<int,int>> graph[],vb &vis,int k){
	if(k<=0) return true;
	
	for(auto pair : graph[v]){
		int child = pair.first;
		int weight = pair.second;
		if(vis[child]) continue;
		if(weight >= k) return true;
		vis[child] = true;
		if(dfs(child,graph,vis,k-weight)){
			return true;
		}
		vis[child] = false;

	}
}

bool FindPathMoreThanK(int v,int k,vector<pair<int,int>> graph[]){
	vb vis(v,false);
	for(int i=0;i<v;i++){
		if(vis[i]) continue;
		vis[i] = true;
		if(dfs(i,graph,vis,k)){
			return true;
		}
	}

	return  false;
}


int main(){
	int v,e,k;
	cin>>v>>e>>k;
	vector<pair<int,int>> graph[v];
	for(int i=0;i<e;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		graph[u].push_back({v,wt});
		graph[v].push_back({u,wt});
	}

	cout<<FindPathMoreThanK(v,k,graph);

	return 0;

}

/*

 0 - 3 -  4 
 |   |   |  \
 1 - 2 - 5 - 6

7 9 10
0 3 1
0 1 2
3 4 3
3 2 4
1 2 5
2 5 6
4 5 7
4 6 8
5 6 9



*/