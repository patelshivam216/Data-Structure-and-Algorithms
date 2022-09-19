/*

    SEGMENT TREE BUILD

    Number of nodes in tree = 2n-1
    but for safty we take size of segment tree as 4*N

    To create it 

    --> devide and conquer 
*/

#include<bits/stdc++.h>
using namespace std;
int const N = 1e5+2;

int Tree[4*N],arr[N];

void buildTree(int node,int start,int end){

    if(start == end){
        Tree[node] = arr[start];
        return ;
    }

    int mid = (start + end)/2;

    buildTree(2*node,start,mid); // left child
    buildTree(2*node+1,mid+1,end); // right child

    Tree[node] = Tree[node*2] + Tree[2*node+1]; // this line may be change accordinhgly requirment

    return;
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    buildTree(1,0,n-1); // Tree's starting node is 1 always

    for(int i=1;i<15;i++){
        cout<<Tree[i]<<endl;
    }

    return 0;
}