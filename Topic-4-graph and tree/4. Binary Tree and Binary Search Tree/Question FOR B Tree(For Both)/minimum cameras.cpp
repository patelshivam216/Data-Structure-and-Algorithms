/*

You are given the root of a binary tree. We install cameras on the
tree nodes where each camera at a node can monitor its parent, itself, 
and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

-1 : for requring cameras
0 : if node have camera then return 0
1 : if node is covered then return 1

Thought Process
1) we are going to do postorder travarsal 
2) at leaf node , it needs camera so it return -1 because its batter that
it's parent have camera so that it can get more benifit
3) if any parent find out that its any child need camera then camera count +=1
and then return 0 because that root already got a camera
4) if any root's both child are covered means both l and r are 1 then
it will be case of leaf node so it return -1 to its parent 

*/
#include<bits/stdc++.h>
using namespace std;
static int camera = 0;
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

int minCameras(Node* root){
    if(root == NULL) return 1; // returnning -1 to its parent because its already visited

    int r = minCameras(root->right);
    int l = minCameras(root->left);
    /*
        Here we see 
    */

    if(l == -1 || r == -1){ // if root's any child need camera then take it and return 0
        camera += 1;
        return 0;
    }

    if(l == 0 || r == 0){ // if root's any child have camera then that root is already covered
        return 1;
    }

    return -1; // at the end if its both child return 1 then root needs camera to cover itself

}


int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    // root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->left->left=new Node(4);
    // root->left->right=new Node(6);
    // root->right->left=new Node(12);
    // root->right->right=new Node(18);
    

    int temp = minCameras(root);
    // Here we check if root needs camera or not if it
    // needs then we add one more to our ans 
    if(temp == -1){
        camera += 1;
    }

    cout<<camera<<endl;
    

    return 0;
}