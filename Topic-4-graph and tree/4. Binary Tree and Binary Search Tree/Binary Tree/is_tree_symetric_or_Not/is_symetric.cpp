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

bool helper(Node* left_node,Node* right_node){

    if(left_node==NULL || right_node==NULL){
        return left_node==right_node;
    }

    if(left_node->data != right_node->data){
        return false;
    }

    return helper(left_node->left,right_node->right) && helper(left_node->right,right_node->left);
}

bool is_symetric(Node* root){
    return root==NULL && helper(root->left,root->right);

}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7); 

    cout<<is_symetric(root);

    return 0;
}