#include<bits/stdc++.h>
using namespace std;
// given gride 
const int N = 1e3;
const int INF = 1e4;
int val[N][N];
bool visited[N][N];
int lev[N][N];
int n,m;

vector<pair<int ,int>> movements={
    {1,0},{0,1},{0,-1},{-1,0},
    {1,1},{-1,-1},{-1,1},{1,-1}
};

bool isvalid(int i,int j){

    return (i<n && j<m && i>=0 && j>=0);
}

int bfs(){
    int mx=0;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           
           mx=max(mx,val[i][j]);

        }
    }

    queue<pair<int,int>> q;

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           
           if(mx==val[i][j]){

               q.push({i,j});
               lev[i][j]=0;
               visited[i][j]=true;

           }

        }
    }

    while(!q.empty()){
        auto cur_v=q.front();
        int v_x = cur_v.first;
        int v_y = cur_v.second;
        q.pop();

        for(auto movement : movements){

            int child_x = v_x + movement.first;
            int child_y = v_y + movement.second;
            
            if(!isvalid(child_x,child_y))
                continue;
            if(visited[child_x][child_y])
                continue;
            q.push({child_x,child_y});
            visited[child_x][child_y]=true;
            lev[child_x][child_y]=lev[v_x][v_y]+1;
            ans=max(ans,lev[child_x][child_y]);


        }
    }

    return ans;


}

/*

3 4 
1 2 1 2 
1 1 1 2
1 1 2 2 

*/
int main(){
    
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            cin>>val[i][j];
        }
    }
    
    cout<<bfs();
    
    return 0;
}