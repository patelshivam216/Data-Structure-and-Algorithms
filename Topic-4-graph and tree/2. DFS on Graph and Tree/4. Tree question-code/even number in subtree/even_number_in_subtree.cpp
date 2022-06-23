#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
// vector for list
vector<int> graph[N];
int depth[N];
int even[N];


 void dfs(int vertex,int parent=0)
 {
     if(vertex%2==0)
        even[vertex]++;
     for(auto child : graph[vertex])
     {
        
        if(child==parent) continue;
        dfs(child,vertex);
        even[vertex]+=even[child];

     }


   

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
   
    for(int i=1;i<=vertex;i++)
    {
        cout<<i<<" "<<even[i]<<endl;

    }


    return 0;
}

