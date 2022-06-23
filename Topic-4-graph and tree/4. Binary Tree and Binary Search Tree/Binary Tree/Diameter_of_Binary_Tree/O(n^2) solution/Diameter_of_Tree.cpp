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

int height(Node* root){
    if(root==NULL)
        return 0;

    return 1+max(height(root->left),height(root->right));

}

int diameter(Node* root,int &d){
    if(root==NULL){
        return 0;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    d=max(d,lh+rh);

    diameter(root->left,d);
    diameter(root->right,d);

   return d;

    
}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->right=new Node(4);
    root->right->right->right=new Node(5);
    root->right->right->right->right=new Node(6);
    root->right->left=new Node(7);
    root->right->left->left=new Node(8);
    root->right->left->left->left=new Node(9);


    // Node* root=new Node(1);
    // root->left=new Node(2);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // root->right->left=new Node(6);
    // root->right->right=new Node(7);

    int d=0;
    cout<<diameter(root,d);

    return 0;
}