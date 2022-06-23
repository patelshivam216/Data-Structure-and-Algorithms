#include<bits/stdc++.h>
using namespace std;

bool dfs(int v,int cur_c,vector<int> graph[],vector<int> &vis,vector<int> &colour,int p_c=-1){

    
    vis[v]=1;
    bool ans=true;

    for(auto child : graph[v]){
        
        if(vis[child] && colour[child] != cur_c)
            continue;
        if(vis[child])
            return false;

        vis[child]=1;
        if(cur_c==0) colour[child]=1;
        else colour[child] = 0;

        ans &= dfs(child,colour[child],graph,vis,colour,cur_c); 
    }

    return ans;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> graph[v+1];
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    vector<int> vis(v+1,0);
    vector<int> colour(v+1,-1);
    bool ans = true;

    for(int i=1;i<=v;i++){
        if(vis[i])
            continue;
        if(!dfs(i,0,graph,vis,colour)){
            ans=false;
            break;
        }

    }
    cout<<ans;
    return 0;
}