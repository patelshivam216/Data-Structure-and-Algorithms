
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

int find_floor(Node* root,int key){

    int floor=-1;

    while(root){
        
        if(root->data==key){
            floor=root->data;
            return floor;

        }

        if(root->data < key){
            floor=root->data;
            root=root->right;
        }else{
            root=root->left;
        }

    }

    return floor;

}
int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(16);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    root->right->left=new Node(12);
    root->right->right=new Node(18);

    int ans = find_floor(root,7);
    

    cout<<ans<<endl;
    

    return 0;
}