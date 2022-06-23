#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }

};
// Here i cant compair with luv's tree and graph because 
// there we have given data(value array) in distingish array
// and here we have node with data also with right and left links  
void bfs(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*> q;
    vector<vector<int>> ans; 
    vector<int> lev;
    q.push(root);
    
    while(!q.empty()){
       int size=q.size();

       for(int i=0;i<size;i++){
           auto node = q.front();
           q.pop();
           if(node->left) q.push(node->left);
           if(node->right) q.push(node->right);
           lev.push_back(node->data);
       }

       ans.push_back(lev);
       lev.clear();

    }

    for(auto v : ans){
        for(auto value : v)
            cout<<value<<" ";
        cout<<endl;
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
    
    bfs(root);

    return 0;
}