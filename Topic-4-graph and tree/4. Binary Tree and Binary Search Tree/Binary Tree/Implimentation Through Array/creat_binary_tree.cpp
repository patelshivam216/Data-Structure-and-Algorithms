#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};


Node* CreatTree(Node* root,int a[],int start,int n){
    if(root==NULL){
        return NULL;
    }
    int l=2*start;
    int r=2*start+1;
    if(l<=n){
        
        root->left=new Node(a[l]);
    }
    if(r<=n){
        
        root->right=new Node(a[r]);
    }
    CreatTree(root->left,a,l,n);
    CreatTree(root->right,a,r,n);

    return root;

}
int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    Node* root=NULL;
    root=CreatTree(new Node(a[1]),a,1,n);
    
    return 0;
}