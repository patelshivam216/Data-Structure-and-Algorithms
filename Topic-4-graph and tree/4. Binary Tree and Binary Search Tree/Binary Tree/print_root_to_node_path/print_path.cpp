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

bool find_path(Node* root,vector<int> &path,int x){

    if(root==NULL)
        return false;

    path.push_back(root->data);

    if(root->data==x){
        return true;
    }

    if(find_path(root->left,path,x))
        return true;
    if(find_path(root->right,path,x))
        return true;
    
    path.pop_back();
    return false;
    
    




}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    int element;
    cin>>element;
    vector<int> path;
    find_path(root,path,element);

    for(auto v : path)
        cout<<v<<" ";

    return 0;
}