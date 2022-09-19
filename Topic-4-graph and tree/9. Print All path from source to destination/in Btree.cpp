
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
vi  path;
int k ;
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

// print all k sum path

void helper(Node* root){
    if(root == NULL) return;
    path.push_back(root->data);

    helper(root->left);
    helper(root->right);

    int sum = 0;
    for(int i = path.size()-1;i>=0;i--){
        sum += path[i];
        if(sum == k){
            for(int m = i;m<path.size();m++){
                cout<<path[m]<<" ";
            }
            cout<<endl;
        }
    }

    path.pop_back();


}

int main(){

    cin>>k;

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->left=new Node(5);
    
    
    helper(root);

    return 0;
}


/*
    
         1
       /   \
      2     2
     / \   /
    3   4 5

*/