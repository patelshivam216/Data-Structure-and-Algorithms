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

void right_view(Node* root,vector<int> &right,int lev=0){
    if(root==NULL)
        return;

    if(lev==right.size())
        right.push_back(root->data);
    right_view(root->right,right,lev+1);
    right_view(root->left,right,lev+1);

}
void left_view(Node* root,vector<int> &left,int lev=0){
    if(root==NULL)
        return;

    if(lev==left.size())
        left.push_back(root->data);
    left_view(root->left,left,lev+1);
    left_view(root->right,left,lev+1);

}
int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    vector<int> left;
    vector<int> right;

    right_view(root,right);
    for(auto v : right){
        cout<<v<<" ";
    }
    cout<<endl;

    left_view(root,left);
    for(auto v : left){
        cout<<v<<" ";
    }
    return 0;
}