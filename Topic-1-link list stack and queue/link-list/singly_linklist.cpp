#include<iostream>
using namespace std;

class node
{

public:
    int data;
    node* next;
};
void insert(node ** headref,int data)
{
    // headref=&head
    //*headref=null
    if(*headref==NULL)
    {
        //"link is empty.."
        node *newnode= new node;// newnode= 3000;
        newnode-> data=data;
        // '->' this operator only when base operand have pointer data type (in this case newnode)
        newnode->next=NULL;
        //*headref=Null;
        //*headref=3000;
        *headref=newnode;
        return ;




    }
    else
    {

        node* temp;
        temp=*headref;// temp=3000;
        while(temp->next!=NULL)
        {
            temp=temp->next;


        }

        node* newnode=new node;
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        return ;

    }


}
void printList(node *headref )
		{
			int i=0;


  		  while (headref != NULL)// when only one element is their in linklist then
            // headref->next!=NULL condition will be false
   			 {
        			cout<<" "<<headref->data;
       				headref = headref->next;
				i++;
    			}


		  cout<<"\n";
		  cout<<"\nLength of LinkList is "<<i<<"\n";



		}
void insertat(node** headref)
{



    node* newnode=new node;
    cout<<"Assume link-list starts with position 0 \n\n"<<"Enter data"<<endl;
    int data;
    cin>>data;
    cout<<"in which position"<<endl;
    int position;
    cin>>position;
    newnode->data=data;
    node*temp;
    temp=*headref;
    if(position==0)
    {
      newnode->next=temp;
      *headref=newnode;


    }
    else
    {
        while(--position)
        {

            temp=temp->next;


        }
        newnode->next=temp->next;
        temp->next=newnode;



    }
    return;

}
void deletenode(node** headref)
{
    cout<<"Enter position"<<endl;
    int position;
    cin>>position;
    node* temp;
    temp=*headref;
    node* temp2;

    if(position==0)
    {
        *headref=(*headref)->next;
        free(temp);



    }
    else
    {
        while(--position)
        {

            temp=temp->next;


        }
        temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);




    }




}
int main()
{
    node* head;
    head=NULL;

    //assume &head=2000 and head=null
    insert(&head,5);// pass address of head
    //assume &head=2000 and head=3000
    insert(&head,10);
    insert(&head,15);
    insert(&head,20);
    insert(&head,25);
    printList(head );
    insertat(&head);
    printList(head );
    deletenode(&head);
    printList(head );



}
