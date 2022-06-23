
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
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

void sub_sum(Node* root){

    if(root==NULL)
        return ;

    m[root->data]=root->data;

    sub_sum(root->left);
    sub_sum(root->right);

   

    if(root->left)
        m[root->data]+=m[root->left->data];
    if(root->right)
        m[root->data]+=m[root->right->data];

    

   
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);
    root->right->right->right=new Node(30);
    

    sub_sum(root);
    for(auto v : m){
        cout<<v.first<<" "<<v.second<<endl;
    }


    

    return 0;
}