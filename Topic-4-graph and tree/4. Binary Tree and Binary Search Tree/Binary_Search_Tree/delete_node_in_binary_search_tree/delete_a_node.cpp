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

Node* findright(Node* root){
    if(root->right == NULL){
        return root;
    }
    return findright(root->right);
}

Node* helper(Node* root){

    if(root->left==NULL)
        return root->right;
    if(root->right==NULL)
        return root->left;

    Node* rightchild=root->right;
    Node* lastright = findright(root->left);
    lastright->right=rightchild;
    return root->left;



}

Node* delete_node(Node* root,int key){
    if(root==NULL)
        return NULL;
    
    if(root->data==key){
        return helper(root);
    }

    Node* temp=root;

    while(root != NULL){

        if(key < root->data){
            if(root->left != NULL and root->left->data==key){
                root->left=helper(root->left);
                break;
            }
            else
                root=root->left;
        }else{
            if(root->right != NULL and root->right->data==key){
                root->right=helper(root->right);
                break;
            }else
                root=root->right;
        }

    }
}
void preorder(Node* root){
    if(root==NULL){
        return ;
    }

    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
    root=delete_node(root,10);
    preorder(root);
    


    

    return 0;
}