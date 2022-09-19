#include<bits/stdc++.h>
using namespace std;
void convert(Node* root,Node* &head , Node* &prev){
    if(root == NULL) return;
    
    convert(root->left,head,prev);
    
    if(prev == NULL){
        head = root;
        prev = head;
    }else{
        prev->right = root;
        root->left = prev;
        prev = root;
    }
    
    convert(root->right,head,prev);
    
}
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node* head = NULL;
        Node* prev = NULL;
        convert(root,head,prev);
        return head;
    }
};