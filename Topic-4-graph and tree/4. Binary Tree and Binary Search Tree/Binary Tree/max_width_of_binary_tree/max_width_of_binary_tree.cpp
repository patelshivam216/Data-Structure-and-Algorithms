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
// 0.do level traversal with...
// 1.we'll do new numbering 
// 2.with knowing that anything not gonna overflow
// 3.for i th node its left child is i*2+1 and right child is i*2+2 for 0 base numbering 
// 4.to prevent overflow we minus k which is lowest number in pervious level

void Find_width(Node* root){
    if(root==NULL)
        return;

    queue<pair<Node*,int>> q;
    q.push({root,0});

    //first and last number 
    int first,last,ans=INT_MIN;

    while(!q.empty()){
        int mn=q.front().second;
        int size=q.size();
        
        for(int i=0;i<size;i++){

            Node* node=q.front().first;
            int cur_id = q.front().second-mn;
            q.pop();

            // take out first and last from every iterration
            if(i==0) {
                first=cur_id;
            }
            if(i==size-1){
                last=cur_id;
            }

            if(node->left) q.push({node->left,cur_id*2LL+1});
            if(node->right) q.push({node->right,cur_id*2LL+2});



        }

        ans=max(ans,last-first+1);

    }

    cout<<ans;

}



int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    Find_width(root);

    return 0;
}