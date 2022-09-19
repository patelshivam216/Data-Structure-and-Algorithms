#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

void dfs(int v,int src,int vertexs,vi graph[],set<int> &visited,string pathSoFar){

	if(visited.size() == vertexs-1){
		bool Found = false;
		for(auto child : graph[v]){
			if(child == src){
				Found = true;
				break;
			}
		}
		if(Found){
			cout<<pathSoFar<<" "<<src<<endl;
		}
	}

	visited.insert(v);
	for(auto child : graph[v]){
		if(visited.find(child) == visited.end()){
			pathSoFar.append(" "+to_string(child));
			dfs(child,src,vertexs,graph,visited,pathSoFar);
			pathSoFar = pathSoFar.substr(0,pathSoFar.size()-(to_string(child).size()+1));
		}
	}
	visited.erase(v);
}

void Himaltonian(int v,vi graph[]){
	set<int> visited;
	int src = 0;
	string pathSoFar = to_string(src);
	dfs(src,src,v,graph,visited,pathSoFar);
}

int main(){
	int v,e;
	cin>>v>>e;
	vi graph[v];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	Himaltonian(v,graph);

	return 0;

}

/*

 0 - 3 -  4 
 |   |   |  \
 1 - 2 - 5 - 6

Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once.

7 9
0 3
0 1
3 4
3 2
1 2 
2 5 
4 5
4 6
5 6 



*/