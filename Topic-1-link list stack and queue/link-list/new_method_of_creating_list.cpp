#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data ;
    Node* next;

    Node(int value){

        data=value;
        next=NULL;
    }

};


void CreatList(Node* root){
    
    auto temp=root;
    int v;
    cin>>v;
    if(root==NULL){
    
        root=new Node(v);
    }else{

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new Node(v);

    }

}


void printList(Node* root){

    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

int main(){

    Node* root;
    root=NULL;
    root=new Node(1);
    root->next=new Node(2);
    root->next->next=new Node(3);
    for(int i=0;i<3;i++){
        CreatList(root);
    }
    printList(root);

    return 0;
}