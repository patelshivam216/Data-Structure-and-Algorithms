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

void inorder(Node* root){
    if(root==NULL) return ;

    cout<<root->data<<" ";
  
    inorder(root->left);
    inorder(root->right);
}

void childrean_sum_property(Node* root){

    if(root==NULL){
        return;
    }

    int child =0;
    // i take sum of two childs 
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    //now compair with root

    if(child>=root->data){
        root->data=child;
    }else{
        // increase left
        if(root->left) root->left->data=root->data;
        // increase right 
        if(root->right) root->right->data=root->data;

    }

    childrean_sum_property(root->left);
    childrean_sum_property(root->right);

    // now increase sum of root 
    int t=0;
    if(root->left) t+=root->left->data;
    if(root->right) t+=root->right->data;
    if(root->left or root->right) root->data=t;






}
int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    inorder(root);

    childrean_sum_property(root);
    cout<<endl<<"after appling property "<<endl;
    inorder(root);

    return 0;
} 