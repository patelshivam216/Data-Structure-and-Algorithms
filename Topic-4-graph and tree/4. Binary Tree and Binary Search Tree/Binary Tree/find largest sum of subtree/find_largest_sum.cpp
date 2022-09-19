#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
vi store;
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

// print all k sum path

void helper(Node* root){
	if(root == NULL) return;


	helper(root->left);
	helper(root->right);

	int tot = 0;
	if(root->right) tot += root->right->data;
	if(root->left) tot += root->left->data;

	root->data += tot;


}

void preorder(Node* root){
	if(root==NULL) return ;

	store.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}

int main(){


	Node* root=new Node(1);
    root->left=new Node(-2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(-6);
	root->right->right = new Node(2);
	
    helper(root);
    preorder(root);
    int maxi = -1e9;
   	for(auto value : store){
   		maxi = max(maxi , value);
   	}

   	cout<<maxi<<endl;

    return 0;
}
