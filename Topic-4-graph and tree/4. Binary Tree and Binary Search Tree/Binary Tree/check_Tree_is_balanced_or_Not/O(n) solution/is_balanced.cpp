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

// we run function of height with some additional logic

int is_balanced(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh=is_balanced(root->left);
    int rh=is_balanced(root->right);
   

    if(lh==-1 || rh==-1) return -1;
    

    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh);

}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(5);
    root->left->left->left->left=new Node(6);
    root->left->left->left->left->left=new Node(7);

    if(is_balanced(root)==-1) cout<<"false";
    else 
        cout<<"true";

    return 0;
   
}