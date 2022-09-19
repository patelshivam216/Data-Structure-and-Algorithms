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

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
}

void Flatten(Node* &root){
    if(root==NULL || (root->left == NULL and root->right == NULL)) return; // leaf Node and Null are flatten already

    if(root->left != NULL){
        // root's left is flatten now 
        Flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right) t = t->right;
        t->right = temp;

    }
    Flatten(root->right);

}

void flattenorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    flattenorder(root->right);
}


int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);
    
    preorder(root);
    cout<<endl;
    Flatten(root);
    flattenorder(root);

    

    return 0;
}

/*

--> first see if left is there then flatten it first
--> then save root->right to temp and assign root->left to root->right
--> then find out last node in these newly atteched subtree 
--> after find out attech that right subtree 
--> and after call again for right subtree 

*/