#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define pb push_back
#define vb vector<bool>

void dfsTopo(int v,vp graph[],vector<bool> &vis,vi &toposort){
	vis[v] = true;
	for(auto pair : graph[v]){
		if(vis[pair.first]) continue;
		dfsTopo(pair.first,graph,vis,toposort);
	}

	toposort.pb(v);
}

void dfsTrans(int v,vp graph[],vb &vis,int &end,int &die){
	vis[v] = true;
	for(auto pair : graph[v]){
		int ch = pair.first;
		int weight = pair.second;
		if(vis[ch]) continue;
		end = ch;
		die = min(die,weight);
		dfsTrans(ch,graph,vis,end,die);
	}
}



vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d){

	vp graph[n+1];
	vp Trans[n+1];
	vii ans;
	vi temp;

	for(int i=0;i<p;i++){
		graph[a[i]].push_back({b[i],d[i]});
		Trans[b[i]].push_back({a[i],d[i]});
	}

	vi toposort;
	vector<bool> vis(n+1,false);
	for(int i=0;i<p;i++){
		if(vis[a[i]] == true) continue;
		dfsTopo(a[i],graph,vis,toposort);
	}

	for(int i=0;i<=n;i++){
		vis[i] = false;
	}

	for(auto v : toposort){
		if(vis[v] == true) continue;
		int start = v;
		int end;
		int die = 1e9;
		dfsTrans(v,Trans,vis,end,die);
		temp.pb(start);
		temp.pb(end);
		temp.pb(die);

		ans.pb(temp);
		temp.clear();
	}

	return ans;
	
        
}

int main(){
	int n,p;
	cin>>n>>p;

	vi a(p);
	vi b(p);
	vi d(p);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		cin>>d[i];
	}

	vii ans = solve(n,p,a,b,d);
	cout<<ans.size()<<endl;
	for(auto v : ans){
		for(auto value : v){
			cout<<value<<" ";
		}
		cout<<endl;
	}

	return 0;
}