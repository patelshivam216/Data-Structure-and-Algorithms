#include<bits/stdc++.h>
using namespace std;
#define NIFT -1e9
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define vb vector<bool>

void dfs(int v,vi graph[],vb &vis,vi &inTime,vi &outTime,int &Time){
	vis[v] = true;
	inTime[v] = Time++;

	for(auto child : graph[v]){
		if(vis[child] == true) continue;
		dfs(child,graph,vis,inTime,outTime,Time);
	}

	outTime[v] = Time++;

}


int main(){
	int v;
	cin>>v;
	vi graph[v+1];
	for(int i=1;i<v;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	/*
	This method, calculation in and out time is called euler tour
	*/

	vi inTime(v+1,0);
	vi outTime(v+1,0);
	vb vis(v+1,false);
	int Time = 1;
	dfs(1,graph,vis,inTime,outTime,Time);

	int Q;
	cin>>Q;
	while(Q--){
		int dir,oliver,bob;
		cin>>dir>>oliver>>bob;

		/*

		dir = 0 means bob is going toward mension means at 1
		dir = 1 means bob is going away from mension (going far from 1)

		*/

		if(dir == 0){

			if(inTime[oliver]<inTime[bob] and outTime[bob]<outTime[oliver]){
				cout<<"YES"<<endl;
			}else cout<<"NO"<<endl;

		}else{

			if(inTime[bob]<inTime[oliver] and outTime[oliver]<outTime[bob]){
				cout<<"YES"<<endl;
			}else
				cout<<"NO"<<endl;

		}
	}

	return 0;
}

/*


9
1 2
1 2
2 6
2 7
3 4
3 5
6 9
7 8
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1


Graph is like tree so edges for this would be vertexs-1

*/