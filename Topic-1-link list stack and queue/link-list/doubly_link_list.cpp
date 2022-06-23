#include<iostream>
using namespace std;

//class
class node{

public:
    int data;
    node* next;
    node* pre;

};
void insertend(node** headref,int data)
{
    node* newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    newnode->pre=NULL;

    if(*headref==NULL)
    {

        *headref=newnode;
        //cout<<(*headref)<<" "<<newnode<<" "<<(*headref)->next<<(*headref)->data<<(*headref)->pre<<endl;
        // same-same-0-5-0


        return;

    }

    else
    {

        node* temp;
        temp=*headref;
        while(temp->next !=NULL)
        {
            temp=temp->next;

        }

        newnode->pre=temp;
        temp->next=newnode;
        return;
    }



}
void xprint(node* headref)
{
    node* temp;
    int len=0;
    temp=headref;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        len++;
        temp=temp->next;

    }

    cout<<endl<<"List length = "<< len<<endl;

}

void insertbeg(node** headref,int data)
{
    node* newnode=new node ;
    newnode->data=data;
    newnode->next=NULL;
    newnode->pre=NULL;

    if(*headref==NULL)
    {

        *headref=newnode;
        return;

    }
    else
    {
        (*headref)->pre=newnode;
        newnode->next=*headref;
        *headref=newnode;


    }

    return;
}

void insertat(node** headref)
{
    node* newnode=new node;
    newnode->next=NULL;
    newnode->pre=NULL;
    cout<<endl<<"Enter data for insertion :"<<endl;
    int data;
    cin>>data;
    newnode->data=data;
    cout<<endl<<"assume link started with oth index"<<endl;
    cout<<endl<<"Enter position for insertion:"<<endl;
    int p;
    cin>>p;
    node* temp;
    temp=*headref;
    if(p==0)
    {
        newnode->next=temp;
        temp->pre=newnode;
        *headref=newnode;
        return;


    }
    else
    {


        while(--p)
        {
            temp=temp->next;

        }
        if(temp->next != NULL)
        {


        newnode->pre=temp;
        newnode->next=temp->next;
        temp->next->pre=newnode;
        temp->next=newnode;

        }
        else
        {
            free(newnode);
            insertend(headref,data);// function call from another fuction...
        }

        return;
    }




    return;
}
void deletenode(node** headref)
{

    cout<<endl<<"Enter position for delete :\n";
    int p;
    cin>>p;
    if(p==0)
    {


        (*headref)=(*headref)->next;
        node*temp;
        temp=(*headref)->pre;
        free(temp);
        (*headref)->pre=NULL;

    }
    else
    {
        node* temp=*headref;
        while(--p)
        {

            temp=temp->next;

        }
        if(temp->next->next != NULL)
        {


        temp->next=temp->next->next;
        free(temp->next->pre);
        temp->next->pre=temp;

        }

        else
        {
            free(temp->next);
            temp->next=NULL;
        }


    }
    return;
}

int main()
{
    node* head;
    head=NULL;
    insertbeg(&head,1);
    insertend(&head,5);
    insertend(&head,10);
    insertend(&head,15);
    insertbeg(&head,2);

    xprint(head);
    insertat(&head);

    xprint(head);

    deletenode(&head);

    xprint(head);
    return 0;
}
