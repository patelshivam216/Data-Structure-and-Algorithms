#include<bits/stdc++.h>
using namespace std;

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    
    while(q.size()>0){
        Node* node = q.front();
        q.pop();
        
        ans.push_back(node->data);
        
        while(node){
            if(node->right) ans.push_back(node->right->data);
            if(node->left) q.push(node->left);
            node = node->right;
        }
    }
    
    return ans;
    
}