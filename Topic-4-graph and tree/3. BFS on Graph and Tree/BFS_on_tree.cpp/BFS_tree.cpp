#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> graph[N];
bool visited[N];
int lev[N];
int v;
void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1]=1;
    lev[1]=0;
    while(!q.empty())
    {
        int cur_v=q.front();
        q.pop();
        for(auto child : graph[cur_v])
        {
            if(visited[child]==1)
                continue;
            q.push(child);
            visited[child]=1;
            lev[child]=lev[cur_v]+1;


        }
    }

    for(int i=1;i<=v;i++)
    {
        cout<<i<<"'s level is "<<lev[i]<<endl;
    }



}
int main()
{
    
    cin>>v;
    for(int i=0;i<v-1;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    /*

    13
    1 2 1 3 1 13 2 5 5 6 5 7 5 8 8 12 3 4 4 9 4 10 10 11 

    */

    bfs();


    return 0;
}