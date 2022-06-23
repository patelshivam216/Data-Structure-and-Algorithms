#include<bits/stdc++.h>
using namespace std;


int main()
{

    int nodes,edges;
    cin>>nodes>>edges;
    int graph[nodes][nodes];
    /*
    
    5 5
    1 5 
    2 5
    2 3
    3 5
    5 4
    
    */

    for(int i=1;i<=edges;++i)
    {
        int v1,v2;
        cin>>v1>>v2;
        //if weight are given then we take another input wt
        // int wt;
        // cin>>wt;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
        // graph[v1][v2]=wt;
        // graph[v2][v1]=wt;



    } 
    //this input operation take O(n)
    if(graph[5][4])
    {
        cout<<"edge between 5 and 4"<< endl;

    }
     if(graph[1][4] == 1)
    {
        cout<<"edge between 1 and 4"<< endl;

    }
    else 
    {
        cout<<"edge inn't between 1 and 4"<< endl;

    }






    return 0;
}