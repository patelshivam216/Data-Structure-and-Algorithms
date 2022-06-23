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



void Printinorder(Node* root){
    if(root==NULL)
        return;
    Printinorder(root->left);
    cout<<root->data<<" ";
    Printinorder(root->right);
}

Node* Tree(vector<int> inorder,int is,int ie,vector<int> postorder,int ps,int pe,unordered_map<int,int> mp){

    if(is>ie || ps>pe)
        return NULL;
    
    Node* root = new Node(postorder[pe]);
   
    int inroot=mp[postorder[pe]];
    int numsleft=inroot-is;// how many numbers are at left side of root

    root->left = Tree(inorder,is,inroot-1,postorder,ps,ps+numsleft-1,mp);
    root->right = Tree(inorder,inroot+1,ie,postorder,ps+numsleft,pe-1,mp);

    

    return root;



}
int main(){
    vector<int> inorder={4,2,5,1,6,3,7};
    vector<int> postorder={4,5,2,6,7,3,1};

    
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    
    Node* root = Tree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    
    Printinorder(root);


    return 0;
}