#include<bits/stdc++.h>
using namespace std;

#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

vi minTimeTakenToFinish(int v,int e,vi graph[]){

	vi Time(v+1,0);
	vi indegree(v+1,0);
	// finding indegree
	for(int i=1;i<=v;i++){
		for(auto child : graph[i]){
			indegree[child]++;
		}
	}

	// if indegree is zero means that jobs are independent so perform first them
	queue<int> q;
	for(int i=1;i<=v;i++){
		if(indegree[i] == 0){
			q.push(i);
			Time[i] = 1;
		}
	}

	// every time when we push vertex in queue means we remove it from actual graph
	// so add -1 to all its adjecent and is anyone become zero indegree than 
	// add it again to queue and calculate time for it
	while(q.size()>0){
		int parent = q.front();
		q.pop();

		for(auto child : graph[parent]){
			
			indegree[child] -= 1;

			if(indegree[child] == 0){
				q.push(child);
				Time[child] = 1 + Time[parent];

			}

		}
	}


	return Time;


}

int main(){

	int v,e;
	cin>>v>>e;
	vi graph[v+1];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

	vi ans = minTimeTakenToFinish(v,e,graph);

	for(int i = 1;i<=v;i++){
		cout<<"vertex :"<<i<<" Time :"<<ans[i]<<endl;
	}

	
	return 0;
}