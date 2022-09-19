#include<bitsd/stdc++.h>
using namespace std;

int const N = 1e5+2;
int Tree[4*N],arr[N];

void buildTree(int node,int start,int end){
    if(start == end){
        Tree[node] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(node*2,start,mid);
    buildTree(2*node+1,mid+1,end);

    Tree[node] = max(Tree[node*2],Tree[2*node+1]);
    return;
}

int query(int node,int start,int end,int left,int right){
    if(end < left || right < start){
        return -1e9;
    }

    if(start >= left and end <= right){
        return Tree[node];
    }

    int mid = (start+end)/2;

    int q1 = query(node*2,start,mid,left,right);
    int q2 = query(2*node+1,mid+1,end,left,right);

    return max(q1,q2);
}


void update(int node,int start,int end,int index,int value){
    
    if(start == end and index == start){
        arr[start] = value;
        Tree[node] = value;
        return;
    }

    int mid = (start + end)/2;

    if(index <= mid)
        update(node*2,start,mid,index,value);
    else if(index >= mid)
        update(2*node+1,mid+1,end,index,value);


    Tree[node] = max(Tree[node*2],Tree[2*node+1]);

    return ;

}

