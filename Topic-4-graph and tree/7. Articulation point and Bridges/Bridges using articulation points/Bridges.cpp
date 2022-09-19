#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

void dfs(int v,vi graph[] , vi &disTime , vi &LowestDisTime ,int &Timer,vector<bool> vis
 ,set<vi> &ans, int parent = -1){

	disTime[v] = LowestDisTime[v] = Timer++; // first update newest time as possible

	vis[v] = true; // mark true

	for(auto child : graph[v]){

		if(child == parent) continue; // Ignoring the path from its parent (Path which is already taken)

		if(vis[child] == true){ 

			LowestDisTime[v] = min(LowestDisTime[v],disTime[child]); // is v's adjecent is already visited 
			// means it has lower discovery time so update current 

		}else if(vis[child] == false){

			dfs(child,graph,disTime,LowestDisTime,Timer,vis,ans,v);

			LowestDisTime[v] = min(LowestDisTime[v],LowestDisTime[child]); // if this adjacent are not visited 
			// then do dfs and afterward , update our Lowest discovery time with our because this are just visited 

			if(LowestDisTime[child] > disTime[v]){ // This is The ROCK condition
				vi temp;
				temp.push_back(v);
				temp.push_back(child);
				ans.insert(temp);
				/*

				--> After ingnoring The Path we already come through , Now we are at Node v 
				 and if its adjecent child have LowestDisTime which is Greater than my disTime
				 means IF Node v is removed Than that child Node(adjacent Node) will no more connected 
				
				--> also this means those adjecent Nodes have any other path such that thay will overcome node v and meet
				remaining graph
				
				*/

			}
		}
	}
}

vii ArticulationPoints(int v,vi graph[]){
	
	vii ans;
	set<vi> temp; // will maintain a set to avoid reduandancy
	vi disTime(v+1,0); // This array will capture discovery time 

	vi LowestDisTime(v+1,0); // This array will capture Lowest discovery time by ingnoring thaose path 
	// which comes from it parent and check its adjecents weather those have lower discovery time or not
	
	vector<bool> vis(v+1,false);
	int Timer = 1;

	dfs(1,graph,disTime,LowestDisTime,Timer,vis,temp);
	for(auto vec : temp) ans.push_back(vec);

	return ans;

}

int main(){

	int v,e;
	cin>>v>>e;

	vi graph[v+1];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vii ans = ArticulationPoints(v,graph);
	for(auto v1 : ans){
		for(auto v2 : v1){
			cout<<v2<<" ";
		}
		cout<<endl;
	}


	return 0;
}


/*

12 14
1 2 
1 4
2 3 
3 4 
4 5
5 6
6 7
6 9
7 8
9 8
8 10
10 11 
11 12
10 12 


*/