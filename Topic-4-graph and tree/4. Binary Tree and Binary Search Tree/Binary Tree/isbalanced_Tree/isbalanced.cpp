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

int_fast16_t height(Node* root){
    if(root==NULL)
        return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);

    if(lh==-1 or rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;

    return max(lh,rh)+1;
}


int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<height(root);

    return 0;
}