#include<stdio.h>

struct student
{
	int roll;
	char fname[100];
	char lname[100];
	char dob[30];
	char division[10];
	char batch[10];
}s1;

void accept(struct student s[],int max)
{
	printf("\n\n|---------------------------------------|");
	for(int i=0;i<max;i++)
	{
		printf("\n| Enter student %d details. ",i+1);
		printf("\n| Roll Number : ");
		scanf("%d",&s[i].roll);		
		printf("| First Name : ");
		scanf("%s",&s[i].fname);
		printf("| Last Name : ");
		scanf("%s",&s[i].lname);
		printf("| Date Of Birth (dd/mm/yyyy) : ");
		scanf("%s",&s[i].dob);
		printf("| Division : ");
		scanf("%s",&s[i].division);
		printf("| Batch : ");
		scanf("%s",&s[i].batch); 
	printf("|---------------------------------------|");
	}
	printf("\n");
}

void display(struct student s[],int max)
{
	printf("\n|-------------------------------------------------------------------------------------|");
	printf("\n|Roll Number    First Name\tLast Name\tDate of Birth\tDivision\tBatch |");
	printf("\n|-------------------------------------------------------------------------------------|");
	for(int i=0;i<max;i++)
	{
		printf("\n|%11d\t%9s\t%9s\t%13s\t%8s\t%5s |",s[i].roll,s[i].fname,s[i].lname,s[i].dob,s[i].division,s[i].batch);
	}
	printf("\n|-------------------------------------------------------------------------------------|\n");
}

void linearsearch(struct student s[],int element,int max)
{
	int temp=0;
	printf("|-------------------------------------------------------------------------------------|");
	printf("\n| Search Student Data With Linear Search Method                                       |");
	printf("\n|-------------------------------------------------------------------------------------|");
	display(s,max);
	for(int i=0;i<max;i++)
	{
		if(s[i].roll==element)
		{
			printf("\n| Student with roll number %d is found on index %d of student data.",element,i);
			temp=1;
		}
	}
	if(temp==0)
	{
		printf("| No Student with such roll number exist                                              |");
	}
	printf("\n|-------------------------------------------------------------------------------------|");
}

void bubblesort(struct student s[],int max)
{
	for(int k=0;k<max;k++)
	{
		for(int i=0;i<max-1;i++)
		{
			if(s[i].roll>s[i+1].roll)
			{
				s1=s[i];
				s[i]=s[i+1];
				s[i+1]=s1;
			}
		}
	}
	display(s,max);
}

void binarysearch(struct student s[],int element,int low,int high,int max)
{
	int mid;
	bubblesort(s,max);
	mid = (low + high)/2;
	
	if(element==s[mid].roll)
	{
		printf("Element %d found at index %d.",element,mid);
	}
	else if(element>s[mid].roll)
	{
		binarysearch(s,element,mid+1,high,max);
	}
	else if(element<s[mid].roll)
	{
		binarysearch(s,element,0,mid-1,max);
	}
	else
	{
		printf("Something went wrong !!");
	}
}


int main()
{
	int num,choice,c,roll;	
	printf("Enter the number of students you want to add the data : ");
	scanf("%d",&num);
	struct student s1[num];
	accept(s1,num);
	A:
	printf("\n\n");
	printf("\n|------------------------------------------------------------------|");
	printf("\n|----------------------------- Menu -------------------------------|");
	printf("\n|------------------------------------------------------------------|");
	printf("\n|1. Search Student Data (Linear Search)                            |");
	printf("\n|2. Search Student Data (Binary Search)                            |");
	printf("\n|3. Sort Student Data (Bubble Sort)                                |");
	printf("\n|4. Sort Student Data (Selection Sort)                             |");
	printf("\n|5. Sort Student Data (Insertion Sort)                             |");
	printf("\n|------------------------------------------------------------------|");
	printf("\n| Enter Choice : ");
	scanf("%d",&choice);
	printf("|------------------------------------------------------------------|");
	
	switch(choice)
	{
		case 1 : printf("\n| Enter the Student Roll Number : ");
			 scanf("%d",&roll);
			 linearsearch(s1,roll,num);
			 break;

		case 2 : printf("\n| Enter the Student Roll Number : ");
			 scanf("%d",&roll);
			 binarysearch(s1,roll,0,num-1,num);
			 break;

		case 3 : bubblesort(s1,num);
			 //display(s1,num);
			 break;

		case 4 : break;

		case 5 : break;

		default : printf("Sorry you enetered the wrong choice ");
	}
	printf("\n\nDo you want to continue (0=Yes/1=No) : ");
	scanf("%d",&c);
	if(c==0)
	{
		goto A;
	}
	return 0;
}
