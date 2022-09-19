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

int start = 0;

bool isdigit(char ch){
	ch = ch - '0';
	if(ch>=0 and ch<=9) return true;
	else return false ;
}

Node* FormationOfTree(string s){

	if(start >= s.size()){
		return NULL;
	}

	bool negative = false ;
	if(s[start] == '-'){
		negative = true;
		start++;
	}

	int num = 0;
	while(start < s.size() and isdigit(s[start])){
		num = num*10 + s[start]-'0';
		start++;
	}

	if(negative){
		num = -1*num;
	}

	Node* root = new Node(num);

	if(start >= s.size()){
		return root;
	}

	// Now wondaring about its left subtree

	if(start<s.size() and s[start]=='('){
		start++;
		root->left = FormationOfTree(s);
	}

	// After finishing left when find closing bracket return 

	if(start<s.size() and s[start] == ')'){
		start++;
		return root;
	}

	// Now goes to right when left is explored

	if(start<s.size() and s[start] == '('){
		start++;
		root->right = FormationOfTree(s);
	}

	if(start<s.size() and s[start] == ')'){
		start++;
		return root;
	}

	return root;


}

void preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";

	preorder(root->left);
	preorder(root->right);
}


int main(){

	string s = "-434(2(3)(1))(6(5))";

	Node* root = FormationOfTree(s);

	preorder(root);

    return 0;
}
