#include<bits/stdc++.h>
using namespace std;

bool bfs(int v,int c,vector<int> graph[],vector<int> &vis,vector<int> &colour){
    
    queue<pair<int,int>> q;
    q.push({v,c});//at the first time as perent we gives -1 because we use 1 and 0 as colour
    
    while(!q.empty()){
        auto p=q.front();
        q.pop();

        int cur_v=p.first;
        int cur_c=p.second;
        
        for(auto child : graph[cur_v]){
            
            if(vis[child] && cur_c != colour[child] )
                continue;
            
            if(vis[child])
                return false;

            if(cur_c==0){
                q.push({child,1});
                colour[child]=1;
            }else{
                q.push({child,0});
                colour[child]=0;
            }

            vis[child]=1;
        }
    }

    return true;
}

int main(){

    int v,e;
    cin>>v>>e;
    vector<int> graph[v+1];
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> vis(v+1,0);
    vector<int> colour(v+1,-1);

    bool ans=true;
    for(int i=1;i<=v;i++){
        
        if(vis[i]) continue;

        if(!bfs(i,0,graph,vis,colour)){
            ans=false;
            break;
        }

    }

    cout<<ans;
    return 0;

}