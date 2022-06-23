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

bool is_leaf(Node* node){

    if(node->left==NULL && node->right==NULL)
        return true;
    else 
        return false;

}
void add_left_boundary(Node* root,vector<int> &ans){

    auto node = root->left;
    while(node){
        if(!is_leaf(node))
            ans.push_back(node->data);
        if(node->left) node=node->left;
        else node=node->right;
    }

}
void add_leaf_boundary(Node* root,vector<int> &ans){
    
    if(is_leaf(root)){
        ans.push_back(root->data);
        return ;
    }

    add_leaf_boundary(root->left,ans);
    add_leaf_boundary(root->right,ans);


}
void add_right_boundary(Node* root,vector<int> &ans){

    auto node=root->right;
    vector<int> ds;
    while(node){
        if(!is_leaf(node)) ds.push_back(node->data);
        if(node->right) node=node->right;
        else
            node=node->left;
    }
    for(int i=ds.size()-1;i>=0;i--){
        ans.push_back(ds[i]);
    }


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

    if(!is_leaf(root))
        ans.push_back(root->data);

    add_left_boundary(root,ans);
    add_leaf_boundary(root,ans);
    add_right_boundary(root,ans);

    for(auto v : ans){
        cout<<v<<" ";
    }

    return 0;
}