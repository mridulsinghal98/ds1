#include<stdio.h>
struct queue
{
  int order;
  int qty;
  int phno;
  char name[50];
  char address[50];
}q[5];
int front= -1, rear= -1;
int isfull()
{
  if(rear==4)
  return 1;
  else
  return 0;
}
int isempty()
{
  if(front==rear)
  return 1;
  else 
  return 0;
}
void dispatch()
{
  int ans;
  ans=isempty();
  if(ans==1)
   printf(" There are no orders to dispatch. \n");
  else
  {
   front ++;
   printf(" Your Order Number %d is dispatched. \n", front+1);
  }
}
void accept()
{
 	int ans;
 	ans=isfull();
 	if(ans==0)
 	{
 	     rear++;
 		 printf(" Please Enter the Details: \n");
  		 printf(" Enter the Name: \n ");
   		 scanf("%s",q[rear].name);
   		 printf(" Enter the Phone Number :\n");
  		 scanf("%d",&q[rear].phno);
  		 printf(" Enter the quantity: \n");
  		 scanf("%d",&q[rear].qty);
  		 printf(" Enter the Address : \n");
  		 scanf("%s",q[rear].address);
  		 printf(" Your Order Number is :\n %d ",rear+1);
 	  }
 	else
 	 printf(" Sorry. We cannot accept any more orders. \n");
}
void pending()
{
    int i,ans;
    ans=isempty();
    if(ans==1)
    printf(" No Pending Orders. \n ");
    else
    {
    	printf(" The pending order numbers are : \n");
    	for(i=(front+1);i<=rear;i++)
    	  {
      		printf(" Name: %s \n" , q[i].name);
      		printf(" Phone Number : %d \n", q[i].phno);
      		printf(" Address : %s \n", q[i].address);
      		printf(" Order No. : %d \n", i+1);
      		printf(" Quantity : %d \n", q[i].qty);
    	  }
    }
}


int main()
{
  int ch,c;
  do{
  printf(" Enter from the given choice : \n 1. Place Order. \n 2. Dispatch order. \n 3. Display Pending Order. \n 4. Exit. \n ");
 scanf("%d",&ch);

 switch(ch)
 {
  case 1:
  {
    accept();
    break;
   }
  case 2:
   {
     dispatch();
     break;
    }
  case 3:
   {
     pending();
     break;
    }
  case 4:
  {
    printf(" Happy to serve you ! \n Have a Nice Day! \n");
    break;
   }
  default:
   printf(" Please Enter a valid choice. \n ");
 }
 printf("\n Do You Want to continue? \n Enter 1 for YES \n Enter 0 for NO\n ");
 scanf("%d",&c);
 if(c==0)
 printf(" Thankyou. \n");
}while(c==1);
}

