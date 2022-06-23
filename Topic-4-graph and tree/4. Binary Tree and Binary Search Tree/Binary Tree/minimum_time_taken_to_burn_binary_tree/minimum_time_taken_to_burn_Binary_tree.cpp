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
void makeparent(Node* root,unordered_map<Node*,Node*> &pp){
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        auto node=q.front();
        q.pop();

        if(node->left){
            q.push(node->left);
            pp[node->left]=node;
        }

        if(node->right){
            q.push(node->right);
            pp[node->right]=node;
        }
    }
}

int min_time(Node* root,unordered_map<Node*,Node*> pp){
    if(root==NULL)
        return 0;
    
    unordered_map<Node*,bool> vis;
    queue<Node*> q;
    q.push(root);
   
    vis[root]=true;
    int time=0,min_t;
    int total_nodes=pp.size()+1;

    while(!q.empty()){
        int size=q.size();

        for(int i=0;i<size;i++){
            // we have to move 3 sizdes 1.left 2.right 3.upward 
            auto node=q.front();
            q.pop();
            

            // left move iff it is not visited
            if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;
            }
            // right movement
            if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
            }
            //upward iff 
            if(pp[node] && !vis[pp[node]]){
                q.push(pp[node]);
                vis[pp[node]]=true;
            }
           
        }

        if(total_nodes==vis.size()){
            min_t=time;
            
        }
        
        time++;

    }

    return min_t;

}


int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    unordered_map<Node*,Node*> pp;//parent pointer
    makeparent(root,pp);
    cout<<min_time(root->left,pp);

    return 0;
}