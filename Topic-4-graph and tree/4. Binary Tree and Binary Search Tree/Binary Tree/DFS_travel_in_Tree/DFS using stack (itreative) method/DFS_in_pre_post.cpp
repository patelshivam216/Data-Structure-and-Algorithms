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

void preorder(Node* root){
    if(root==NULL) return ;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        cout<<node->data<<" ";
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);

    }

}
void inorder(Node* root){

    if(root==NULL)
        return;
    //here  no need to push root first in stack

    stack<Node*> st;
    Node* node=root;
    while(1){

        if(node!=NULL){
            st.push(node);
            node=node->left;
        }else{
           
            if(st.size()==0){
                break;
            }

            cout<<st.top()->data<<" ";
            node=st.top();
            st.pop();
            node=node->right;

        }

        
    }


}
void postorder(Node* root){
    if(root==NULL)
        return;

    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(!st1.empty()){
        auto node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);

    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }

}
int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"Inorder ";
    inorder(root);
    cout<<endl<<"preorder ";
    preorder(root);
    cout<<endl<<"postorder ";
    postorder(root);
    return 0;
}