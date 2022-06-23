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

// 1.makesure i have parent pointer 
// 2.keep going 1 distance upward left right
// 3.distance is eq to k then return ans 
// 4.here i choose target node as root->left default
void makeparent(Node* root,unordered_map<Node*,Node*> &pp){
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        auto node=q.front();
        q.pop();

        if(node->left){
            pp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            pp[node->right]=node; 
            q.push(node->right);
        }
    }
}

find_nodes(Node* target,int k,unordered_map<Node*,Node*> pp){

    queue<Node*> q;
    unordered_map<Node*,bool> vis;
    q.push(target);
    vis[target]=true;
    int dis=0;

    while(!q.empty()){
        int size=q.size();
        
        if(dis==k)
            break;

        for(int i=0;i<size;i++){
            auto node=q.front();
            q.pop();
            // now we move left iff its unvisited 

            if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;
            }

            // move to right iff right node is unviisited 

            if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
            }

            // move upward iff it is not visited 

            if(pp[node] && !vis[pp[node]]){
                q.push(pp[node]);
                vis[pp[node]]=true;
            }
        }
        
        dis++;
    }

    while(!q.empty()){
        cout<<q.front()->data;
        q.pop();
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

    //hash map for parent pointer
    unordered_map<Node*,Node*> pp;//parent pointer 
    makeparent(root,pp);

    //hast map for maintein visited array
    
    int k;
    cout<<"Enter target distance "<<endl;
    cin>>k;

    find_nodes(root->left,k,pp);



    return 0;
}