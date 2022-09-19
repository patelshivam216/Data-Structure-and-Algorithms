#include<bits/stdc++.h>
using namespace std;
const int N=1e3;

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>> collection;
    vector<int> cur_v;
    int val[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>val[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(val[i][j]!=0 && i>0){
                 
                cur_v.push_back(val[i][j]+collection[i-1][j]);

            }
            else{

                cur_v.push_back(val[i][j]);

            }
           
        }
        collection.push_back(cur_v);
        cur_v.clear();
        
    }
    
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            cout<<collection[i][j];
        }
        cout<<endl;
    
    }
    return 0;
}