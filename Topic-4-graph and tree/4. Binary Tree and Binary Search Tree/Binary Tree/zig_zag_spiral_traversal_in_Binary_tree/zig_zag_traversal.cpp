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

void zig_zag(Node* root){
    bool flag=0;
    if(root==NULL) return ;

    queue<Node*> q;
    vector<vector<int>> ans;
    vector<int> ds;

    q.push(root);

    while(!q.empty()){

        int size=q.size();

        for(int i=0;i<size;i++){
            auto node=q.front();
            q.pop();
            ds.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
      
        if(flag==0)
            ans.push_back(ds);
        else{
            reverse(ds.begin(),ds.end());
            ans.push_back(ds);
        }    
            
        flag=!flag;
        ds.clear();
    }

    for(auto v : ans){
        for(auto val : v){
            cout<<val<<" "; 
        }
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

    zig_zag(root);

    return 0;
}