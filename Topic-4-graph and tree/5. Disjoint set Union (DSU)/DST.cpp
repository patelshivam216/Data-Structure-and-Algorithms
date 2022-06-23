#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int parent[10];
int size[10];

void make(int v){
    parent[v]=v;
    size[v]=1;

}

int find(int v){
    if(v==parent[v])
        return v;
    
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);

    if(a != b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }

}
/*
    5 4 
    
    1 2
    1 3 
    1 4 
    4 5 

*/
int main(){
    int v,e;
    cin>>v>>e;

    for(int i=1;i<=v;i++) make(i);

    for(int i=0;i<e;i++){
       
        int v1,v2;
        cin>>v1>>v2;
       
       Union(v1,v2);//------------------------------->>>> This function made all parent root 
       //------so on output window all parent array looks like same 
       
       
    }
    cout<<"parent array\n";
    for(int i=1;i<=v;i++)
        cout<<i<<" - "<<parent[i]<<endl;


    cout<<"find function call \n"<<"3 - "<<find(3)<<endl;
    cout<<"4 - "<<find(4)<<endl;
    cout<<"2 - "<<find(2)<<endl;
    cout<<"parent array\n";
    for(int i=1;i<=v;i++)
        cout<<i<<" - "<<parent[i]<<endl;

    return 0;
}