#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n,m;//n*m
vector<vector<int>> val(N,vector<int>(N));
vector<vector<int>> vis(N,vector<int>(N));

bool isvalid(int i,int j){

    return i>=0 && j>=0 && i<n && j<m;
}


void dfs(int i,int j){

    if(!isvalid(i,j)){
        return;
    }
    if(vis[i][j]==true){
        return;
    }
    vis[i][j]=true;
    cout<<"Entering in "<<val[i][j]<<endl;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
    cout<<"leaving in "<<val[i][j]<<endl;



}



int main(){

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>val[i][j];
        }
    }
    dfs(0,0);



    return 0;

}

/*
input 

3 3 

1 2 3 
3 4 5 
5 6 7 


*/