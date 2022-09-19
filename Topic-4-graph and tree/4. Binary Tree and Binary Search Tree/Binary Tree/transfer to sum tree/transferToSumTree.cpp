
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


int fun(Node* root){
    if(root==NULL) return 0;
    
    
    int child = 0;
    
    if(root->left)  child += root->left->data;
    if(root->right) child += root->right->data;
    
    root->data = child;
    
    fun(root->left);
    fun(root->right);
    
    int tot = 0;
    if(root->right) tot += root->right->data;
    if(root->left) tot += root->left->data;
    
    root->data += tot;
    
    
}

void preorder(Node* root){
	if(root == NULL) return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


int main(){

	Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preorder(root);
	fun(root);
	cout<<endl;
	preorder(root);


    return 0;
}
