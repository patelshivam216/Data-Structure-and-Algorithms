#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int> &parent_array,vector<int> graph[],int p=-1){

   parent_array[v]=p;
    for(auto child : graph[v]){
        if(child==p)
            continue;
        
        dfs(child,parent_array,graph,v);
        
    }

}
/*

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
   
    vector<int> parent_array(v+1,0);

    dfs(1,parent_array,graph);
    
    for(int i=1;i<=v;i++){
        cout<<i<<" - "<<parent_array[i]<<endl;
    }
    
    return 0;
}