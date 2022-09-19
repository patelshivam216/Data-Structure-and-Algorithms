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

unordered_map<Node*,int> dp;



int maxsum(Node* root){

    if(root == NULL) return 0;

    if(dp.find(root) != dp.end()) return dp[root];

    // peak

    int inc = root->data;
    if(root->left != NULL){
        inc += maxsum(root->left->right);
        inc += maxsum(root->left->left);
    }

    if(root->right){
        inc += maxsum(root->right->right);
        inc += maxsum(root->right->left);
    }

    // Not peak

    int exc = maxsum(root->right) + maxsum(root->left);

    return dp[root] =  max(exc,inc);


}

int main(){

    Node* root=new Node(1);
    root->left=new Node(3);
    root->right=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);
    

    cout<<maxsum(root);
    

    return 0;
}

