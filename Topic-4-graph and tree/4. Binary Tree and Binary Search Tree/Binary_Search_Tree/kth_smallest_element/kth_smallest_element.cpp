#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
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
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);

    int k;
    cin>>k;
    inorder(root);
    cout<<ans[k-1];


    return 0;
}