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

int left_height(Node* root){
    int h=0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}

int right_height(Node* root){
    int h=0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}

int count_nodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh=left_height(root);
    int rh=right_height(root);
    if(lh==rh){
        return pow(2,lh)-1;
    }

    return 1 + count_nodes(root->left) + count_nodes(root->right);

}
int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    int count=count_nodes(root);
    cout<<count;
    

    return 0;
}