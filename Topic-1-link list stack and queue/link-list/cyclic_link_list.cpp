#include <bits/stdc++.h>
using namespace std;
int len=0;
class node
{


public:
    int data;
    node* next;





};
void insertend(node** headref,int data)
{

    len++;// only write here because insertend will also call from insertbeg so
    node* newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    if(*headref==NULL)
    {

        *headref=newnode;
        newnode->next=*headref;


    }
    else
    {
        node* temp=*headref;
        while(temp->next != *headref)
        {
            temp=temp->next;


        }

        temp->next=newnode;
        newnode->next=*headref;


    }






}
void xprint(node* headref)
{
    /*

    in main()... xprint(head);
    assume &head=2000; head=3000;
    and also head's datatype is node*

    so in Xprint receive node* TYPE VARIABLE so
    it have to be same datatype in both side


    */
    node* temp;
    temp=headref;
    if(temp->next == headref && len>0)
    {

        cout<<headref->data<<endl;

    }
    else if(len>0)
    {


        while(temp->next != headref)
        {
            cout<<temp->data<<" ";

            temp=temp->next;


        }
        cout<<temp->data<<" ";


    }
    if(len>0)
    cout<<"\n List Length = "<<len;
    return;
}
void insertbeg(node ** headref,int data)
{
    cout<<endl<<"data inserted at begining..."<<endl;
    insertend(headref,data);
    /*

    node ** headref;
    headref=&head;
    and in insertend() we pass &head so here we pass headref

    */
    node* temp=*headref;
    while(temp->next != *headref)
    {
        temp=temp->next;

    }
    *headref=temp;



    return;
}

void deletenode(node** headref)
{
    cout<<"\nassume link list started with 0th index\n\n";
    cout<<"\nEnter which node you want to delete :"<<endl;
    int p;
    cin>>p;

    node* temp;
    temp=*headref;
     if(p==0)
     {


             while(temp->next != *headref)
             {
                 temp=temp->next;
             }



             temp->next=(*headref)->next;
             free((*headref));
             *headref=temp->next;
             len--;




     }
     else
     {

         while(--p)
         {
            temp=temp->next;
         }
         node* temp2;//just because delete / free to node
         temp2=temp->next;
         temp->next=temp->next->next;
         free(temp2);
         len--;

     }

    return;
}
void insertat(node** headref)
{
    cout<<"\n\n Enter data you want to insert :\n";
    int data;
    cin>>data;
    cout<<"\n\n Enter position :\n";
    int p;
    cin>>p;
    /*
    headref=&head

    */
    node* temp=*headref;
    if(p==0)
    {
        insertbeg(headref,data);
        return;

    }
    else
    {

        if(temp->next->next == *headref)
        {
            insertend(headref,data);
            return;
        }

        while(--p)
        {
            temp=temp->next;
        }
        node* newnode=new node;
        newnode->data=data;
        newnode->next=temp->next;
        temp->next=newnode;
        len++;
        return;

    }




    return;
}
int main()
{
        node* head;
        head=NULL;
        insertend(&head,25);
        insertend(&head,30);
        insertend(&head,35);
        xprint(head);
        insertbeg(&head,20);
        xprint(head);
        insertat(&head);
        xprint(head);
        xprint(head);
        deletenode(&head);
        xprint(head);


    return 0;
}
