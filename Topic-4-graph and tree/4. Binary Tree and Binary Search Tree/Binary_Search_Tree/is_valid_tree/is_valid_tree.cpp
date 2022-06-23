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

bool is_valid(Node* root){
    if(root==NULL)
        return true;
    
    bool ans=true;

    if(root->left){
        if(root->left->data < root->data)
            ans &=is_valid(root->left);
        else{
            return false;
        }
    }

    if(root->right){
        if(root->right->data > root->data){
            ans &=is_valid(root->right);
        }
        else{
            return false;
        }
    }

    return ans;
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);

    cout<<is_valid( root);
    


    

    return 0;
}