#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
bool visited[N];
int order[N];
vector<int> graph[N];


bool dfs(int src)
{
    visited[src]=true;
    order[src]=1;

    for(auto child : graph[src]){
        if(visited[child]){
            if(order[child])
                return true;
        }else{
            if(dfs(child)){
                return true;
            }
        }
    }
    order[src]=0;
    return false;

}


int main(){

    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }

    for(int i=1;i<=v;i++){
        if(visited[i])
            continue;
        if(dfs(i)){
            cout<<1;
            break;
        }
    }

    return 0;
}
    