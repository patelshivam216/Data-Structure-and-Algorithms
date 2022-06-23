/*

here value of any node is considered as its number

delete edge , where both subtree's sum's multiplication would be maximum

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> graph[N];
int sub_sum[N];
void dfs(int v,int p=-1)
{
    sub_sum[v] = v;
    for(auto child : graph[v])
    {
        if(child==p)
        {
            continue ;
        }
        dfs(child,v);
        sub_sum[v] += sub_sum[child];

    }
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

       4
       1 2 1 4 4 3 

    */

    dfs(1);
    long long ans=0;
    for(int i=1;i<=v;i++)
    {
        cout<<sub_sum[i]<<" ";
    }
    cout<<endl;
    for(int i=2;i<=v;i++)
    {
        int part1= sub_sum[i];
        int part2= sub_sum[1]-part1;
        ans=max(ans,part1*1LL*part2);

        cout<<"ans "<<ans<<" part1 "<<part1<<" part2 "<<part2<<endl;
    }
    
    cout<<"max ans after edge deletion "<<ans;




    return 0;
}
