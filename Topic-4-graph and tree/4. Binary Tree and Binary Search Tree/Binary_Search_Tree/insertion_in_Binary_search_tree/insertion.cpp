
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

void insertion(Node* root,int key){

    while(true){

        if(key > root->data ){
           
           if(root->right != NULL){
               
               root=root->right;

           }else{

                root->right = new Node(key);
                break;
           }

        }else{
            if(root->left != NULL)
                root=root->left;
            else{
                root->left=new Node(key);
                break;
            }
        }
    }
}

void inorder(Node* root){
    
    if(root==NULL) return;
    
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);

    inorder(root);
    cout<<endl;
    insertion(root,7);
    inorder(root);
    


    

    return 0;
}