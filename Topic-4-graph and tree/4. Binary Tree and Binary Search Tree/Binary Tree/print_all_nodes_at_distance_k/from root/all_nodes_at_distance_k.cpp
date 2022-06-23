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

void find_nodes(Node* root,int dist,vector<int> &ans,int k=0){
    if(root==NULL)
        return;

    if(k==dist)
        ans.push_back(root->data);
    
    find_nodes(root->left,dist,ans,k+1);
    find_nodes(root->right,dist,ans,k+1);

    k--;
}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<int> ans;
    int dist;
    cin>>dist;
    find_nodes(root,dist,ans);

    for(auto v : ans){
        cout<<v<<" ";
    }


    return 0;
}