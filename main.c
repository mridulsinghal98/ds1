
#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void create(struct node *head);
void display(struct node *head);
int length(struct node *head);
void insert(struct node *head,int pos);
void delete(struct node *head,int pos);
void reverse(struct node *head);
void sort(struct node *head);
void merge(struct node *head1,struct node *head2);



int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node*));
    head->data=9999;
    head->next=NULL;
    
    struct node *head2;
    head2=(struct node*)malloc(sizeof(struct node*));
    head2->data=9999;
    head2->next=NULL;
   


    int choice;
    do {
        printf("\nSINGLY LINKED LIST MENU DRIVEN PROGRAM.\n1.Create and Display a list.\n2.Find lenght of the singly linked list.\n3.Insert a node in the list.\n4.Delete a node from the list.\n5.Reverse the list.\n6.Bubble sort the list.\n7.Merge two lists.\n8.EXIT PROGRAM\n");
        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                create(head);
                display(head);
                break;
            
            case 2:
                create(head);
                int l =length(head);
                printf("\nLength of the singly linked list is %d \n",l);
                break;
                
            case 3:
                create(head);
                int pos;
                printf("\nEnter the position where you want to enter node: ");
                scanf("%d",&pos);
                insert(head,pos);
                printf("\nSingly linked list after insertion of element.\n");
                display(head);
                break;
                
            case 4:
                create(head);
                int pos2;
                printf("\nEnter the position where you want to delete the node");
                scanf("%d",&pos2);
                delete(head,pos2);
                printf("\nSingly linked list after deletion of element.\n");
                display(head);
                break;
                
            case 5:
                create(head);
                printf("\nReverse of the singly linked list:");
                reverse(head);
                display(head);
                break;
                
            case 6:
                create(head);
                printf("\nSorted singly linked list.");
                sort(head);
                display(head);
                break;
                
            case 7:
                printf("\nEnter nodes of the first list.");
                create(head);
                printf("\nEnter nodes of the second list.");
                create(head2);
                merge(head,head2);
                    break;
            case 8:
                printf("\nTHANK YOU.BYE BYE TATA.DO VISIT AGAIN:)\n");
                    break;

                
            default:
                printf("\nPlease enter a valid choice.\nTRY AGAIN NOW.\n");
                break;
        }
        
    } while (choice!=8);

  
return 0;

}


void create(struct node *head){
struct node *temp=head;
int ch=1,x;

printf("\nEnter your choice:\n1.Enter new node.\n2.Exit.\n");
 scanf("%d",&ch);
do{
 struct node *newnode;
 newnode=(struct node*)malloc(sizeof(struct node*));
 printf("\nEnter data of the node: ");
 scanf("%d",&x);
 newnode->data=x;
 newnode->next=NULL;
 temp->next=newnode;
 temp=newnode;
 
printf("\nEnter your choice:\n1.Enter new node.\n2.Exit.\n");
 scanf("%d",&ch);
}while(ch==1);
}


void display(struct node *head)
{
struct node *temp;
temp=head->next;
while(temp!=NULL)
{
printf("\nData of the node is:");
printf("%d",temp->data);
temp=temp->next;
}
printf("\n");
}

int length(struct node *head)
{
int count=0;
struct node *temp;
temp=head->next;
while(temp!=NULL)
{
temp=temp->next;
count++;
}

return count;
}

void insert(struct node *head,int pos)
{ int i=1;
int k=length(head);
if(pos>k+1)
    printf("\nPostion entered it not present in the linked list.\nINVALID.");
else
{    int m;
    struct node *curr;
    curr=head;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    while(curr!=NULL && i<pos)
    {
        i++;
        curr=curr->next;
    }
    newnode->next=curr->next;
    curr->next=newnode;
    printf("\nEnter data at %dth positon",pos);
    scanf("%d",&m);
    newnode->data=m;
}

}


void delete(struct node *head,int pos)
{
     struct node *prev=head;
    int i=0,k=length(prev);
    
    if(pos>k)
        printf("\nNode can't be deleted!!\n");
    else
    {
        while(prev!=NULL && i<pos-1)
        {
            prev=prev->next;
            i++;
        }
        struct node *temp=prev->next;
        prev->next=temp->next;
    }
        printf("The node deleted successfully!!\n");

}

void reverse(struct node *head)
{
    struct node* prev=NULL;
    struct node* curr=head->next;
    struct node* next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=prev;
}

void sort(struct node *head)
{
    int k;
    k=length(head);
    struct node* prev;
    struct node* curr;
    struct node* temp;
   for(int i=0;i<k-1;i++)
    {
        prev=head;
        curr=head->next;
        for(int j=0;j<k-i-1;j++)
        {
            temp=curr->next;
            if(curr->data>temp->data)
            {
                prev->next=temp;
                curr->next=temp->next;
                temp->next=curr;
                prev=temp;
            }
            else
            {
                prev=curr;
                curr=curr->next;
                
            }
        }
    }
}

void merge(struct node *head1,struct node *head2)
{   int flag;
    struct node* curr1;
    struct node* curr2;
    struct node* temp;
    curr1=head1->next;
    curr2=head2->next;
    
    if(curr1->data<curr2->data)
    {
        temp=head1;
        flag=1;
    }
    else
    {
        temp=head2;
        flag=0;
    }
    
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data<curr2->data)
        {
            temp->next=curr1;
            temp=curr1;
            curr1=curr1->next;
        }
        else
        {
            temp->next=curr2;
            temp=curr2;
            curr2=curr2->next;
        }
    }
    if(curr1==NULL)
        temp->next=curr2;
    if(curr2==NULL)
        temp->next=curr1;
    if(flag==1)
        display(head1);
    else
        display(head2);
}

