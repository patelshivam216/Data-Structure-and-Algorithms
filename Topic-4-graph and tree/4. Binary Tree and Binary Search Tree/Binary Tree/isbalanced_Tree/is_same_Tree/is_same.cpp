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

bool issame(Node* root1,Node* root2){
    if(root1==NULL or root2==NULL){
        return (root1==root2);
    }

    return (root1->data == root2->data) && issame(root1->left,root2->left) && issame(root1->right,root2->right);
}


int main(){

    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->left->left=new Node(4);
    root1->left->right=new Node(5);
    root1->right->left=new Node(6);
    root1->right->right=new Node(7);

    Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(32);// this one is wrong
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);

    cout<<issame(root1,root2);

    

    return 0;
}