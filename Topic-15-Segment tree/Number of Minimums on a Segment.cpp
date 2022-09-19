
//***************************** FIND MIN SEGMENT BUGG (codeforce) *****************************\\

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int const N = 1e5+2;
int const MOD = 1e9+7;
pii Tree[N*4];
int arr[N];

void buildTree(int node,int start,int end){

    if(start == end){
        Tree[node].first = arr[start];
        Tree[node].second = 1;
        return;
    }

    int mid = (start+end)/2;
    buildTree(2*node,start,mid);
    buildTree(2*node+1,mid+1,end);

    if(Tree[2*node].first < Tree[2*node+1].first){
        Tree[node].first = Tree[node*2].first;
        Tree[node].second = Tree[node*2].second;
    }else if(Tree[2*node+1].first < Tree[2*node].first){
        Tree[node].first = Tree[2*node+1].first;
        Tree[node].second = Tree[2*node+1].second;
    }else{
        Tree[node].first = Tree[node*2].first;
        Tree[node].second = Tree[2*node].second + Tree[2*node+1].second;
    }

    return;

}

pii query(int node , int start , int end , int left , int right){
    if(left>end || start> right){
        pii d;
        d.first = MOD;
        d.second = -1;
        return d;
    }

    if(left<=start and end <= right){
        return Tree[node];
    }

    int mid = (start+end)/2;

    pii q1 = query(node*2 , start , mid , left , right);
    pii q2 = query(node*2+1 , mid+1 , end , left , right);

    pii ans;
    if(q1.first < q2.first){
        ans = q1;
    }else if(q2.first < q1.first){
        ans = q2;
    }else{
        ans.first = q1.first;
        ans.second = q1.second+q2.second;
    }

    return ans;

}


void update(int node , int start , int end , int index , int value){
    if(start == end){
        Tree[node].first = value;
        Tree[node].second = 1;
        arr[index] = value;
        return ;
    }

    int mid = (start+end)/2;
    update(node*2,start,mid,index,value);
    update(2*node+1,mid+1,end,index,value);

    if(Tree[2*node].first < Tree[2*node+1].first){
        Tree[node].first = Tree[node*2].first;
        Tree[node].second = Tree[node*2].second;
    }else if(Tree[2*node+1].first < Tree[2*node].first){
        Tree[node].first = Tree[2*node+1].first;
        Tree[node].second = Tree[2*node+1].second;
    }else{
        Tree[node].first = Tree[node*2].first;
        Tree[node].second = Tree[2*node].second + Tree[2*node+1].second;
    }

}

int main(){
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(1,0,n-1);

    while(t--){
        int type;
        cin>>type;

        if(type == 1){
            int index,value;
            cin>>index>>value;

            update(1,0,n-1,index,value);

        }else if(type == 2){
            int left,right;
            cin>>left>>right;
            pii ans = query(1,0,n-1,left,right-1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }


    return 0;
}

/*
5 5
3 4 3 5 2
2 0 3
1 1 2
2 0 3
1 0 2
2 0 5

ans should be :
3 2
2 1
2 3

*/