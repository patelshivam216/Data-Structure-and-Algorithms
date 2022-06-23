#include<bits/stdc++.h>
using namespace std;
/*
* 0-1 BFS means in graph all edges are weighted by 2 value {0,1}
and in this situation when we find shortest path then it calls 0-1 BFS problem 

* if we found vertex with edge 0 at level x then we are process it first with level x-1;

* for this we use deque stl which has push_back() and push_front() bothh

*/

const int N=1e3;
const int INF=1e4;
vector<pair<int ,int >> graph[N];
vector<int> lev(N,INF);
int v,e;

int bfs(){

    deque<int> q;
    q.push_back(1);
    lev[1]=0;

    while(!q.empty()){
        int cur_v=q.front();
        q.pop_front();
        for(auto child : graph[cur_v]){

            int child_v=child.first;
            int wt = child.second;
            if(lev[cur_v] + wt < lev[child_v]){

                lev[child_v]=lev[cur_v]+wt;
                if(wt==0){
                    q.push_front(child_v);
                }
                else 
                    q.push_back(child_v);
            }
        }

    }

    return lev[v];// v means last vertex because here we have to find 1 to last vertex's shortest path


}


int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;

        if(v1==v2)
            continue;// this will discard all self loops

        graph[v1].push_back({v2,0});
        graph[v2].push_back({v1,1});
    }
    cout<<bfs();


    
}


