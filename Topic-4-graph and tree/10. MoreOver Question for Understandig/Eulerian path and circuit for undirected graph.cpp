#include<bits/stdc++.h>
using namespace std;
#define NIFT -1e9
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define vb vector<bool>
void dfs(int v,vi graph[],vb &vis){
    vis[v] = true;
    for(auto child : graph[v]){
        if(vis[child]) continue;
        dfs(child,graph,vis);
    }
}

bool isConnected(int v,vi graph[]){
    vb vis(v,false);
    dfs(0,graph,vis);
    for(int i=0;i<v;i++){
        if(vis[i] == false) return false;
    }

    return true;
}

int findEler(int v,int edges,vi graph[]){
    if(!isConnected(v,graph)){
        return 0;
    }

    int HavingOddIndegree = 0;
    for(int i=0;i<v;i++){
        if(graph[i].size()%2){
            HavingOddIndegree++;
        }
    }

    if(HavingOddIndegree>2) return 0;
    return HavingOddIndegree == 2 ? 1 : 2;
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

    int ans = findEler(v,e,graph);

    if(ans == 0){
        cout<<"This is not a Euler Graph"<<endl;
    }else if(ans == 1){
        cout<<"This is a semi-Eulerian Graph"<<endl;
    }else if(ans == 2){
        cout<<"This is an Eulerain Graph"<<endl;
    }

    
}

/*

--> if graph is not connected means we cant visit all edges in one walk time so that kind
of graph never be Eulerian or semi

 1---0---3 
 |  / \  |
 | /   \ |
 2       4


5 6
0 2 
1 2 
1 0
0 3
0 4
3 4

rules for euler graph
--> all vertex mush have even drgree
--> starting vertex and ending vertex would be same 
--> all edges mush visit only once(we can visit any vertex any number of time)

rules for semi eulerian graph
--> only 2 vertex should have odd degree all other must have even degree
--> all edges mush visit only once(we can visit any vertex any number of time) 
--> start != end vertex

*/