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
void vertical_Traversal(Node* root,map<int,map<int,multiset<int>>> &mp){
    if(root==NULL){
        return;
    }

    queue< pair<Node*,pair<int,int> > > q;
    q.push({root,{0,0}});

    while(!q.empty()){

        int size=q.size();

        for(int i=0;i<size;i++){

            auto p=q.front();
            q.pop();
            auto node = p.first;
            int x=p.second.first;
            int y=p.second.second;
            mp[x][y].insert(node->data);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});

            

        }
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

    map<int,map<int,multiset<int>>> mp;
    vertical_Traversal(root,mp);

    for(auto v1 : mp){
        for(auto v2 : v1.second){
            for(auto v3 : v2.second){
                cout<<v3<<" ";
            }
        }
    }
    

    return 0;
}