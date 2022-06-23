#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
bool visited[N];
vector<int> graph[N];


bool dfs(int vertex,int parent)
{
    bool inloopExist=false;
    visited[vertex]=true;
    for(auto child : graph[vertex])
    { if(visited[child] && child==parent) continue;
        
        if(visited[child])
        return true;
        inloopExist |= dfs(child,vertex);
        // inloopExist = inloopExist || dfs();
    }

    return inloopExist;

}
int main()
{
    int n,m;
    //n=vertex
    //m=edges 
    cin>>n>>m;
    //input
    // n m
    // 8 5
    // 1 2 
    // 2 3 
    // 2 4 
    // 3 5 
    // 6 7 
    // in this input there in No loop now add one edge and creat loop
    // 1 5 
   bool inloopExist=false;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v2].push_back(v1);
        graph[v1].push_back(v2);

    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i])continue;
        if(dfs(i,0))
        {
            inloopExist=true;
            break;
        }
       
    }
    cout<<inloopExist;
  
    return 0;
}