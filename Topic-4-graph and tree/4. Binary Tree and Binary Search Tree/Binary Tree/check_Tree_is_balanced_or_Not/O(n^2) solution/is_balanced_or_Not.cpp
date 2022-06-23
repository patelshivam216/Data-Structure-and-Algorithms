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

int TreeHeight(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh=TreeHeight(root->left);
    int rh=TreeHeight(root->right);

    return 1+max(lh,rh);

}

bool is_balanced(Node* root){
    if(root==NULL){
        return true;
    }

    
    int lh=TreeHeight(root->left);
    int rh=TreeHeight(root->right);

    if(abs(lh-rh)>1) return false;

    bool left=is_balanced(root->left);
    bool right=is_balanced(root->right);

    if(left==false || right == false ) return false ;

    return true;

}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(5);
    root->left->left->left->left=new Node(6);
    root->left->left->left->left->left=new Node(7);
    
    
    cout<<is_balanced(root);

    return 0;
}