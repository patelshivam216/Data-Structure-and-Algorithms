/*

    SEGMENT TREE BUILD

    Min and Max in segment Tree

8
5 3 2 4 1 8 6 10
1
0 7
2
5 100
1
0 7
-1

*/

#include<bits/stdc++.h>
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

/*
no overlaps : start end left right || left right start end 

complete overlaps : left start end right

partial : left start end right || start left end right
*/


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




int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    buildTree(1,0,n-1); // Tree's starting node is 1 always


   while(1){
        
        int type;
        cin>>type;

        cout<<"Type : "<<type<<endl;

        if(type == 1){ // for get result

            int l,r;
            cin>>l>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<endl;

        }else if(type == 2){ // for update

            int index,value;
            cin>>index>>value;
            update(1,0,n-1,index,value);
            cout<<arr[index]<<endl;

        }else break;
   }

    return 0;
}
