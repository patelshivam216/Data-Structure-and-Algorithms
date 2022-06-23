#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> graph[N];
int par[N];// par[i]=parent of i




 void dfs(int vertex,int parent=-1)
 {
      par[vertex]=parent;
     
     for(auto child : graph[vertex])
     {
         
	    if(child==parent) 
        {
            continue;
        }

       
        dfs(child,vertex);

       
     }


   

 }



//function which return path
vector<int> path(int v)
{
    vector<int> ans;
    while(v != -1)
    {
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    
    return ans;
 
}
int main()
{
    // remember for tree edges = vertex-1;

    int v;
    cin>>v;
    for(int i=0;i<v-1;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }
    //input
    /*

        13
1 3 1 2 1 13 2 5 5 6 5 7 5 8 8 12 3 4 4  9 4 10 10 11 
6 7 

    */

    dfs(1);

   
    int x,y;
    cin>>x>>y;
    vector<int> path1 = path(x);
    vector<int> path2 = path(y);

    for(auto p1 : path1)
    {
        cout<<p1<<" ";
    }
    cout<<endl;
    for(auto p2 : path2)
    {
        cout<<p2<<" ";
    }

    int mn_ln= min(path1.size(),path2.size());
    // mn_ln=min(path1.size(),path2.size());
    int lca=-1;
    for(int i=0;i<mn_ln;i++)
    {
        if(path1[i]==path2[i])
            lca=path1[i];
        else
            break;

    }
    cout<<"LCA is "<<lca<<endl;



    return 0;
}
