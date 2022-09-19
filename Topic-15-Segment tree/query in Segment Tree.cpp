/*

    SEGMENT TREE BUILD

    Number of nodes in tree = 2n-1
    but for safty we take size of segment tree as 4*N

    To create it 

    --> devide and conquer 

    --> input
    
    8
    5 3 2 4 1 8 6 10
    1
    1
    1 5

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

// left....right --> range for query
int query(int node,int start,int end,int left,int right){
    
    if(end<left || right<start) return 0;

    if(left<=start and end <= right){
        return Tree[node];
    }


   int mid = (start+end)/2;

   int q1 = query(node*2 , start , mid , left , right);
   int q2 = query(node*2+1 , mid+1 , end , left , right);

   return q1+q2;


}

/*

no overlaps : start end left right || left right start end
complete overlaps : left start end right

partial :

left start end right || start left end right



*/


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    buildTree(1,0,n-1); // Tree's starting node is 1 always

   int Q;
   cin>>Q;
   while(Q--){
        
        int type;
        cin>>type;

        if(type == 1){
            int l,r;
            cin>>l>>r;

            int ans = query(1,0,n-1,l,r);
            cout<<ans<<endl;
        }else{


        }
   }

    return 0;
}
