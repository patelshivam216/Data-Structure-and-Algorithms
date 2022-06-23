#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
bool visited[N];
vector<int> graph[N];
vector<vector<int>> cc;//to save vector of connected component 
vector<int> current_c;
void dfs(int vertex)
{
    visited[vertex]=true;
    current_c.push_back(vertex);

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
        current_c.clear();
        dfs(i);
        cc.push_back(current_c);

        
    }
    for(auto current_c : cc)
    {
        for(auto node : current_c )
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }
  
    
    return 0;
}