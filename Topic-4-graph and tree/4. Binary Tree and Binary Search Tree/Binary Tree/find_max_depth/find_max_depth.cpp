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

void find_max_depth(Node* root,int &mx,int p=0){
    if(root==NULL)
        return;

    mx=max(p,mx);
    //recursion 
    
    find_max_depth(root->left,mx,p+1);
    find_max_depth(root->right,mx,p+1);

    //backtracking

    p=p-1;


}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
  
    int mx=0;
    find_max_depth(root,mx);
    cout<<mx;

    return 0;
}