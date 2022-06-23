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

Node* search(Node* root,int value){
    while(root != NULL && root->data != value){
        if(value > root->data) root=root->right;
        if(value < root->data) root=root->left;
    }

    return root;
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);


    Node* node = search(root,18);

    // Node* node = search(root,7);

    cout<<node->data<<endl;


    

    return 0;
}