#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

bool dfs(int v,vi graph[],vi &track){
    for(auto child : graph[v]){
        if(track[child] != -1 and track[child] == track[v]) return false;
        if(track[child] != -1) continue;
        if(track[v] == 0){
            track[child] = 1;
        }else if(track[v] == 1)
            track[child] = 0;

            if(!dfs(child,graph,track)){
                return false;
            }
    }

    return true;
}

bool checkBipertite(int v,vi graph[]){
    vi track(v,-1);
    for(int i=0;i<v;i++){
        if(track[i] != -1) continue;
        track[i] = 0;
        if(!dfs( i,graph,track)){
            return false;
        }
    }

    return true;
}


int main(){
    int v;
    cin>>v;
    vii m1(v,vi(v)); // original
    vii m2(v,vi(v)); // complement
    vi graph[v]; // for further use
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>m1[i][j];
            if(i!=j){
                m2[i][j] = m1[i][j]==1?0:1;
            }
        }
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i!=j and m2[i][j] == 1){
                graph[i].push_back(j);
            }
        }
    }

    cout<<checkBipertite(v,graph);


    return 0;

}

/*

1 - 0 - 3
|  /    |
 2      4    


--> first find completement of given graph
--> means make edge where it is not and remove existing edges 
--> then find if that graph is bipertait or Not if Not then No clique will be derived

Normal for 5 vertices
5
0 1 1 0 0 
1 0 1 1 0
1 1 0 0 0
0 1 0 0 1
0 0 0 1 0

compelement

0 0 0 1 1 
0 0 0 0 1 
0 0 0 1 1 
1 0 1 0 0 
1 1 1 0 0 

and Ans would be true means its is bipertite so there are possiblity to devide it in two part
to make clique



*/