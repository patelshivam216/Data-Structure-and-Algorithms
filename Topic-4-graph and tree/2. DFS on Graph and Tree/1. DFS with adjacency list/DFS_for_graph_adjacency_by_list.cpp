#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
// vector for list 
vector<int> graph[N];
bool visited[N];
 void dfs(int vertex)
 {

     /*Take action on vertex after entering the vertex */

     cout<<"Entered in "<<vertex<<endl;

    visited[vertex]=true;

     for(auto child : graph[vertex])

     {/*Take action on child before entering the child node */

     cout<<"parent "<<vertex<<" child "<<child<<endl;

     if(visited[child]==true) continue;



        dfs(child);

        /*Take action on child after entering child node;*/
     }

     cout<<"exiting vertex"<<vertex<<endl;

     /*Take action on vertex before exit*/

 }

int main()
{
    int vertex,edges;
    cin>>vertex>>edges;
    /*
     5 5
     1 5 
     2 5
     2 3
     3 5
     5 4
     */

    for(int i=0;i<edges;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }
    dfs(1);// vector graph is globle variable 
    

    return 0;
}

