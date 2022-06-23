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

int diameter(Node* root,int &d){
    if(root==NULL){
        return 0;
    }

    int lh=diameter(root->left,d);
    int rh=diameter(root->right,d);

    d=max(d,lh+rh);

    return 1+max(lh,rh);

}

int main(){

    // Node* root=new Node(1);
    // root->left=new Node(2);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // root->right->left=new Node(6);
    // root->right->right=new Node(7);

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->right=new Node(4);
    root->right->right->right=new Node(5);
    root->right->right->right->right=new Node(6);
    root->right->left=new Node(7);
    root->right->left->left=new Node(8);
    root->right->left->left->left=new Node(9);

    int d=0;
    diameter(root,d);
    cout<<d;

    return 0;
}