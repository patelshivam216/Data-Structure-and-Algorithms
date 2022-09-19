#include<bits/stdc++.h>
using namespace std;
#define NIFT -1e9
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define vb vector<bool>

void dfs(int v,vector<pii> graph[],vb &visited,vi &dist,int &calculateDist){

	visited[v] = true; 

	for(auto pair : graph[v]){
		int child = pair.first;
		int weight = pair.second;
		if(visited[child] == true) continue;

		calculateDist += weight;

		if(dist[child] < calculateDist){
			dist[child] = calculateDist;
		}

		dfs(child,graph,visited,dist,calculateDist);
		
		calculateDist -= weight;

	}

	visited[v] = false;
}

int main(){

	int v,e;
	cin>>v>>e;
	vector<pii> graph[v];
	for(int i=0;i<e;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		graph[u].push_back({v,wt});
	}

	vi dist(v,NIFT); // intial distance
	vb visited(v,false);
	int calculateDist = 0;
	int src = 1; // variable
	dist[1] = 0; // src to src distance would be zero
	dfs(src,graph,visited,dist,calculateDist); 

	for(int i=1;i<v;i++){
		cout<<i<<" - "<<dist[i]<<endl;
	}

	return 0;
}

/*


6 7
0 1 5
1 5 5
5 3 2
3 2 20 
5 2 50 
4 2 10
1 4 2 

*/