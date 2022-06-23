#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int> &sub_sum,vector<int> graph[],int p=-1){

    sub_sum[v]+=v;
    for(auto child : graph[v]){
        if(child==p)
            continue;
        
        dfs(child,sub_sum,graph,v);
        sub_sum[v]+=sub_sum[child];
    }

}
/*

// input


6 5 

1 2 
1 3 
3 4 
3 5 
3 6 



*/
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
   
    vector<int> sub_sum(v+1,0);
    dfs(1,sub_sum,graph);
    for(int i=1;i<=v;i++){
        cout<<i<<" - "<<sub_sum[i]<<endl;
    }
    return 0;

}