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

int findceil(Node* root,int key){

    int ceil=-1;
    
   while(root){
       
       if(root->data==key){
           ceil=root->data;
           return ceil;
       }

       if(key>root->data){
           root=root->right;
       }
       else{
           ceil=root->data;
           root=root->left;
       }
   }

    return ceil;
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);


    int value = findceil(root,7);

    // Node* node = search(root,7);

    cout<<value<<endl;


    

    return 0;
}