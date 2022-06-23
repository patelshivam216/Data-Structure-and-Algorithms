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

bool find_path(Node* root,int x ,vector<int> &path){

    if(root==NULL)
        return false;
    
    path.push_back(root->data);
    
    if(x==root->data)
        return true;

    if(find_path(root->left,x,path))
        return true;

    if(find_path(root->right,x,path))
        return true;


    path.pop_back();
    return false;

}

void find_LCA(int x,int y,Node* root){
    vector<int> xpath;
    vector<int> ypath;

    find_path(root,x,xpath);
    find_path(root,y,ypath);

    int ln = min(xpath.size(),ypath.size());
    int LCA=INT_MIN;
    for(int i=0;i<ln;i++){
        if(xpath[i]==ypath[i])
            LCA=xpath[i];

    }
    cout<<LCA;


}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->right=new Node(6);
    root->left->right->left=new Node(7);

    find_LCA(4,7,root);

   

    return 0;
}