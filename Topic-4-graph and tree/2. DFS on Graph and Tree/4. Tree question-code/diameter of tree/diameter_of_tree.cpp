#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
// vector for list
vector<int> graph[N];
int depth[N];


 void dfs(int vertex,int parent=0)
 {

     /*Take action on vertex after entering the vertex */

     for(auto child : graph[vertex])
     {
         /*Take action on child before entering the child node */

        if(child==parent) continue;

        depth[child]=depth[vertex]+1;

        dfs(child,vertex);



        /*Take action on child after entering child node;*/
     }


     /*Take action on vertex before exit*/

 }

int main()
{
    int vertex;
    cin>>vertex;
    // 13
    // 1 2
    // 1 3
    // 1 13
    // 2 5
    // 3 4
    // 5 6
    // 5 7
    // 5 8
    // 8 12
    // 4 9
    // 4 10
    // 10 11



    for(int i=0;i<vertex-1;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }
    dfs(1);// vector graph is globle variable
    int max_node;
    int max_depth=-1;

    for(int i=1;i<=vertex;i++)
    {
        if(max_depth<depth[i])
        {
            max_depth=depth[i];
            max_node=i;

        }
        depth[i]=0;
    }
    dfs(max_node);

    max_depth=-1;
    for(int i=1;i<=vertex;i++)
    {
        if(max_depth<depth[i])
        {
            max_depth=depth[i];


        }

    }
    cout<<"diameter is "<<max_depth;



    return 0;
}

