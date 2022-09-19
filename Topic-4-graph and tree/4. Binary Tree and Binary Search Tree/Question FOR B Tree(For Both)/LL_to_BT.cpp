#include<bits/stdc++.h>
using namespace std;
#define p pair
class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data = data;
        next = NULL;
    }
};
class TreeNode{
public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

pair<ListNode* , ListNode*> findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = head;
    while(fast->next and fast->next->next){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;

    }

    return {prev,slow};
}

TreeNode* createTree(ListNode* head){

    if(head == NULL) return NULL;

    auto pair = findMid(head);
    ListNode* mid = p.second;
    ListNode* prev = p.first;
    
    TreeNode* root = new TreeNode(mid->data);
    
    if(prev == mid) return root;
    else
        prev->next = NULL;
        
    root->left = createTree(head);
    root->right = createTree(mid->next);

    return root;

}

void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}
void preorder(TreeNode* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int n;
    cin>>n;
    ListNode* head = NULL;
    ListNode* temp = head;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        if(head == NULL){
            head = new ListNode(value);
            temp = head;
        }else {
            temp->next = new ListNode(value);
            temp = temp->next;
        }
    }
    temp->next = NULL;

    cout<<"List : \n";
    temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    // calling function
    TreeNode* root = createTree(head);

    cout<<"inorder :\n";

    inorder(root);

    cout<<endl;

    cout<<"preorder :\n";

    preorder(root);

    return 0;



}

/*


7
1 2 3 4 5 6 7 

*/