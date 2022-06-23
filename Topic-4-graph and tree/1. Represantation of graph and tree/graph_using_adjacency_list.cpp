#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
// vector for list 
vector<int> graph[N];
// if edges are with weights
// vector<pair<int,int>> graph[N];
// graph[1] is connected with 5 with weight 5 
 
int main()
{
    int vertex,edges;
    cin>>vertex>>edges;
     //input
    // 5 5
    // 1 5 
    // 2 5
    // 2 3
    // 3 5
    // 5 4

    for(int i=0;i<edges;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

        // if we have weights

        // int wt;
        // graph[v1].push_back({v2,wt});
        // graph[v2].push_back({v1,wt});

    }
    //if we want to check edge are present or not 
    // what i can do

    // if edges between 2 aqnd 5 
    for(auto v1 : graph[2])
    {
          if(v1==5)
            {
                cout<<"edge is there between 2 and 5!!"<<endl;

            }
      
    }

for(auto v1 : graph[1])
    {
          if(v1==4)
            {
                cout<<"edge is there between 1 and 4!!"<<endl;

            }
             cout<<"edge is Not between 1 and 4!!"<<endl;
      
    }


    return 0;
}

