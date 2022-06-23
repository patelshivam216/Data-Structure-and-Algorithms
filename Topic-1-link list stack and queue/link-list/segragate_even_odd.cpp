#include<bits/stdc++.h>
using namespace std;
class Node{

public:
	int data;
	Node* next;
	Node(int v){
		data=v;
		next=NULL;
	}
};

void printlist(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

Node* change_node(Node* head,Node* pre1,Node* pre2,Node* temp1,Node* temp2){

	if(pre1==NULL){

		pre2->next=temp2->next;
		head=temp2;
		head->next=temp1->next;
		temp1->next=pre2->next;
		pre2->next=temp1;


	}else{

		pre1->next=temp1->next;
		pre2->next=temp2->next;

		temp2->next=pre1->next;
		pre1->next=temp2;

		temp1->next=pre2->next;
		pre2->next=temp1;




	}

	return head;

}

int main(){


	Node* head=new Node(17);
	head->next=new Node(15);
	head->next->next=new Node(8);
	head->next->next->next=new Node(9);
	head->next->next->next->next=new Node(2);
	head->next->next->next->next->next=new Node(4);
	head->next->next->next->next->next->next=new Node(6);


	printlist(head);

	Node* pre1=NULL;
	Node* temp1=head;
	Node* temp2=head->next->next;
	Node* pre2=head->next;

	cout<<pre1->data<<" "<<temp1->data<<" "<<pre2->data<<" "<<temp2->data<<endl;

	// head=change_node(head,pre1,pre2,temp1,temp2);

	printlist(head);
	
	

	return 0;

}