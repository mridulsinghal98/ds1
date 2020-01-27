
#include<stdio.h>

struct searchsort                                                      //Structure starts here
{
	int numbr;                                                     //Members of structure
	int key;	
}ss;                                                                   //ss declared of type structure and structure ends here

int binarysearch(int bin[],int low,int high,int key1);                    //Finction to search an element in the given array using binary search
void linearsearch(int arra1[],int len,int key1);                          //Function to search an element in the given array using linear search
void bubblesort_(int srt[],int mx,int dum,int key__);                     //Function to sort the given array using Bubble Sort
void dissortarr(int arrr[],int len);                                      //Function to display the sorted array
void selectionsort(int ar[],int length);                                  //Function to sort the given array using selection sort
void swap(int *fir,int *sec);                                             //Function to swap two variables
void insertionsort(int ir[],int length);                                  //Function to sort the given array using insertion sort



int main()                                                                  //Main Function Starts here
{
	A:                                                                    //A is a label here
	printf("\nEnter the number of elements in the array : ");             
	scanf("%d",&ss.numbr);                                                //Taking the number of elements present in the array from the user
	int arra[ss.numbr];	
	printf("\nEnter the elements of the array -->\n\n\n");                
	for(int i=0;i<ss.numbr;i++)                                           
	{
		printf("Enter the %d element : ",i+1);
		scanf("%d",&arra[i]);
	}
	printf("\n1.linear search\n2.binary search(sorted data)\n3.bubble sort\n4.selection sort\n5.insertion sort\n6.Exit \nEnter the Choice : ");
	int choice,c;
	scanf("%d",&choice);
	switch(choice)
	{
	case 1 : printf("Enter the value to be searched : ");                      //Case for Linear Search
		 scanf("%d",&ss.key);
		 linearsearch(arra,ss.numbr,ss.key);
	         break;

	case 2 : printf("Enter the value to be searched : ");                      //Case for Binary Search
		 scanf("%d",&ss.key);
		 bubblesort_(arra,ss.numbr,0,ss.key);
		 break;

	case 3 : bubblesort_(arra,ss.numbr,1,0);                                 //Case for bubble sort
	         break;

	case 4 : selectionsort(arra,ss.numbr);                                  //Case for selection sort
	         break;

	case 5 : insertionsort(arra,ss.numbr);                                   //Case for insertion sort
	         break;

	case 6 : break;                                                           //Case for exit

	default :printf("Sorry !,Choice you entered doesn't exist");                 //If the user entered undesired value
	}
	printf("\nDo you want to continue (0=Yes/1=No) : ");scanf("%d",&c);          //Asling the user if he wants to continue
	if(c==0)
	{
		goto A;                     //Goto is a jump statement or control transfer statement , It transfers the control to the Label A
	}
	return 0;
}                                                                         //Main Function Ends here

int binarysearch(int bin[],int low,int high,int key1)                            //Function Defination of Binary Search Function
	{
		if(low<=high)
		{
			int mid=(low+high)/2;
			if(bin[mid] == key1)
			{return mid;}
			else if(key1<bin[mid])
			{
				return binarysearch(bin,low,(mid-1),key1);
			}
			else
			{
				return binarysearch(bin,mid+1,high,key1);
			}
		}
		return -1;
	}

	void linearsearch(int arra1[],int len,int key1)                        //Function defination of Linear Search Function
	{
		int index,bool=1;
			for(index=0;index<len;index++)
			{
				if(arra1[index]==key1)
				{
					printf("\nThe value has been found on %d.\n",index+1);
					bool=0;
				}
			}
			if(bool)
			{
				printf("\nThere is no element in the array\n");
			}
	}

	void bubblesort_(int srt[],int mx,int dum,int key__)                        //Function defination of Bubble Sort Function
	{
		int check=1;
		while(check)
		{check=0;
			for(int i=0;i<mx-1;i++)
			{
				if(srt[i]>srt[i+1])
				{

					int temp=srt[i+1];
					srt[i+1]=srt[i];
					srt[i]=temp;
					check=1;
				}
			}
		}
		if(dum)
		{
		dissortarr(srt,mx);
		}
		else
		{
			dissortarr(srt,mx);
			int c=binarysearch(srt,0,mx,key__);
			if(c!= -1)
			{
				printf("\nThe element has index %d\n",c+1);
			}
			else
			{
				printf("\nThe element is not present in the array\n");
				}
		}
	}
	void dissortarr(int arrr[],int len)                                     //Function Defination of Display the Sorted array function
	{
		printf("\nThe sorted array is : [ ");
		for(int i=0;i<len;i++)
		{
			printf("%d ",arrr[i]);
		}
		printf("]\n");
	}


	void selectionsort(int ar[],int length)                                //Function Defination of Selection Sort Function
	{
		int i,j,min_index;
		for(i=0;i<length-1;i++)
		{
			min_index=i;
			for(j=i+1;j<length;j++)
			{
				if(ar[j] < ar[min_index])
				min_index=j;
			}
			swap(&ar[min_index],&ar[i]);
		}
		printf("\nThe array is : [ ");
		for(int k=0;k<length;k++)
		printf("%d ",ar[k]);

		printf("]\n");
	}

	void swap(int *fir,int *sec)                                              //Function Defination of Swap Function
	{
		int temp = *fir;
		*fir = *sec;
		*sec=temp;
	}
	void insertionsort(int ir[],int length)                                   //Function Defination of Insertion Sort Function
	{
		int i,j,key;
		for(i=1;i<length;i++)
		{
			key=ir[i];
			j=i-1;


			while(j>=0 && ir[j]>key)
			{
				ir[j+1] = ir[j];
				j=j-1;
			}
			ir[j+1] = key;
		}
		printf("\nThe array is : [ ");
		for(int k=0;k<length;k++)
		printf("%d ",ir[k]);

		printf(" ]\n");
	}

