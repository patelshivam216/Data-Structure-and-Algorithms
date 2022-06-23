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

void find_LCA(Node* root,int v1,int v2){

 
    while(root->data != v1 and root->data != v2){

        if(v1<root->data and v2 < root->data){
            cout<<"sdslll";
            root=root->left;
        }
        else if ( v1>root->data and v2> root->data){
            cout<<"sdsrrr";
            root=root->right;
        }else{
            break;
        }
        
    }

    cout<<root->data;

    
}


int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->left->left=new Node(3);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);
    
    find_LCA(root,3,6);


    

    return 0;
}