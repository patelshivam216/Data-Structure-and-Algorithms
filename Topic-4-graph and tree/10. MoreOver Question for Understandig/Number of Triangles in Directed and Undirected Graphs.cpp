#include<bits/stdc++.h>
using namespace std;
#define vii vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>

int main(){
    int v;
    cin>>v;
    vii m(v,vi(v)); 
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>m[i][j];
        }
    }

    int count = 0;
    bool isdirected = false;

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(m[i][j] and m[j][k] and m[k][i]){
                    count += 1;
                }
            }
        }
    }

    cout<<count<<endl;

    if(isdirected) count /= 3;
    else count /= 6;

    cout<<count<<endl;
   

    return 0;

}

/*

1 - 0 - 3
|  /    |
 2      4    

Normal for 5 vertices
5
0 1 1 0 0 
1 0 1 1 0
1 1 0 0 0
0 1 0 0 1
0 0 0 1 0
ans = 1

4
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
ans = 2

--> If graph is undirected then
let say 0 1 2 there vertexs give us trangle than 0,1,2's all permutution will give us ans so
 for getting only one we have to devide it with 6

 --> if graph is directed say 0->1->2->0 so these combination give us 3 permutution so
 we ahve to devide it by 3 at the end



*/