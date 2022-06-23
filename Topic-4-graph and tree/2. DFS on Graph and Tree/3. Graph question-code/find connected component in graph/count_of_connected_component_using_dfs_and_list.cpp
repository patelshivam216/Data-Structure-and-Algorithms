#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
bool visited[N];
vector<int> graph[N];
void dfs(int vertex)
{
    visited[vertex]=true;
    for(auto child : graph[vertex])
    {
        if(visited[child])
        continue;
        dfs(child);
    }

}
int main()
{
    int n,m;
    //n=vertex
    //m=edges 
    cin>>n>>m;
    //input
    // 8 5
    // 1 2 
    // 2 3 
    // 2 4 
    // 3 5 
    // 6 7 
    int count=0;
    //count for counting connected component 
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
        dfs(i);
        count++;
    }
  
    cout<<"connected component is "<<count<<endl;
    return 0;
}