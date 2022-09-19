#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

vi dijkastra(int src,int n,vector<pair<int,int>> graph[]){
	vi dist(n+1,1e9);
	dist[src] = 0;
	set<pair<int,int>> set;
	set.insert({0,src});

	while(set.size()>0){
		auto p = *set.begin();
		set.erase(set.begin());

		int v = p.second;

		for(auto pair : graph[v] ){
			int weight = pair.second;
			int child = pair.first;

			if(dist[v] + weight < dist[child]){
				dist[child] = dist[v] + weight;
				set.insert({dist[child],child});
			}
		}

	}

	return dist;
}

int MinEdgesToReverse(int v,int source,int destination,vector<pair<int,int>> graph[]){

	vi dist = dijkastra(source,v,graph);
	return dist[destination];

}

int main(){
	int v,e,s,d;
	cin>>v>>e>>s>>d;
	vector<pair<int,int>> graph[v+1];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back({v,0});
		graph[v].push_back({u,1});
	}

	cout<<MinEdgesToReverse(v,s,d,graph);

	return 0;

}

/*

vetex edges source destination

7 7 1 7
1 2 
3 2 
3 4 
6 2
5 6 
7 5
7 4

--> what we have done here ?

so we add weight as 0 is for direct edge and the for reverse we add 1 weight and simply make it 
0-1 graph

after that simply called dijkastra so it will find all distance from source to destination
and among those we simply return what we needed 


*/

