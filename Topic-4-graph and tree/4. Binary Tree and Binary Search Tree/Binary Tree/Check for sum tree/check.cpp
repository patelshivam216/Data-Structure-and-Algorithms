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


bool isleaf(Node* root){
    return true ? root->left == NULL and root->right == NULL : false;
}
bool fun(Node* root){
    if(root==NULL || isleaf(root)) return true;
    
       
    if(!fun(root->left)){
        return false;
    }
    if(!fun(root->right)){
        return false;
    }

    int child = 0;
    if(root->right) child += root->right->data;
    if(root->left) child += root->left->data;


    if(root->data != child) return false;

    root->data += child;

    return true;
}


int main(){

	Node* root=new Node(3);
    root->left=new Node(1);
    root->right=new Node(2);
    
	cout<<fun(root)<<endl;
	cout<<endl;
	


    return 0;
}
