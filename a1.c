
#include<stdio.h>
int length(char *str);	
void strcopy(char *str,char *str1 );                                    //Function to copy the strings
void strcomp(char str[30],char str1[30]);                               //Function to compare two strings
void strcon(char *str,char *str1);                                      //Function to concatenate two strings
void strreverse(char str[30],char str1[30]);                            //Function to reverse a string
void palindrome(char str[30]);                                          //Fucntion to check whether the string is palindrome or not
void delete(char str[30]);                                              //Function to delete the contents of the strings
void substring(char str[30],char str1[30]);                             //Function to check whether the string is substring of the given string
int main()
{
	int m=0;
	int len;
	char str[30],str1[30],str2[30];
while(m<9)
{
	printf("Enter the choice u want to perform.....\n");
	printf("1.Length\n2.Copy\n3.Compare\n4.Concatenate\n5.Reverse\n6.Palindrome\n7.Substring\n8.Delete\n9.Exit\n");
	scanf("%d",&m);					//for knowing the choice of user what he/she  wants to perform  
	switch(m)
	{
	
	case 1:printf("Enter the string\n");
			scanf("\n%[^\n]%*c", str);
			len=length(str);				//calculate length of string 
			printf("Length of string is %d\n",len);		//print length of string 
			break;
	case 2:printf("Enter the string\n");
			scanf("%s",str);
			strcopy(str1,str2);				//copy string str data to str1
			printf("Second string is %s\n",str2);
			
			break;
	case 3:printf("Enter the string 1\n");
			scanf("\n%[^\n]%*c", str);
			printf("Enter the string 2\n");
			scanf("\n%[^\n]%*c", str1);
			strcomp(str,str1);				//compare str with str1
			break;
	case 4:printf("Enter the string 1\n");
			scanf("\n%[^\n]%*c", str);
			printf("Enter the string 2\n");
			scanf("\n%[^\n]%*c", str1);
			strcon(str,str1);				// concatenate the data of str and str1 to str 
			break;
	case 5:printf("Enter the string \n");
			scanf("\n%[^\n]%*c", str);
			strreverse(str,str1);				//reverse the data of str and store it in str1 
			break;
	case 6:printf("Enter the string \n");
			scanf("\n%[^\n]%*c", str);
			palindrome(str);				//check whether string is palindrome or not 
			break;
	case 7:printf("Enter the string 1\n");
			scanf("\n%[^\n]%*c", str);
			printf("Enter the string 2\n");
			scanf("\n%[^\n]%*c", str1);
			substring(str,str1);				//checks whether str1 is substring of str 
			break;
	case 8:delete(str);						//for deleting the string 
			printf("Respected string has been deleted\n");	
			break;
	case 9:printf("EXIT\n");					//exit from the loop
			break;
	default:printf("Please enter valid input\n");
		break;



	}
}
return 0;
}

int length(char *str)	
{
	int count=0;
	int i;
	char *ptr=str;				//initialising of pointer variable ptr 		
	for(i=0;*ptr!='\0';i++)
	{
		count++;		//increases count value until it reaches the end of string			
		ptr++;
	}
	return count;
}
void strcopy(char *str,char *str1 )
{	int i;
	int len; 
	char *ptr=str,*ptr1=str1;	//initialising of pointer variable ptr and ptr1
	
	
	for(i=0;*ptr!='\0';i++)
	{
		*ptr1=*ptr;
		ptr++;
		ptr1++;
		
	}
	*ptr1='\0';
	
}

void strcomp(char str[30],char str1[30])
{	int flag=0;
	int len1;
	int len2;
	len1=length(str);
	len2=length(str1);
	if(len1==len2)		//for equal string length must be equal
	{
		for(int i=0;i<len1;i++)
		{
			if(str[i]==str1[i])	//if each char is equal flag will be equal to length of string 
			{
				flag++;
			}
		}
	}
	else
	{
		printf("String are not equal\n");
	}
	if(flag==len1)
	{
		printf("Strings are equal\n");
	}
	else
	{
		printf("String are not equal\n");
	}
 
}
void strcon(char *str,char *str1)
{	int len;
	int i;
	char *ptr=str,*ptr1=str1;
	for(i=0;*ptr!='\0';i++)
	{
		ptr++;			//to take it to end of string str 
	}
	
	for(i=0;*ptr1!='\0';i++)
	{
		*ptr=*ptr1;		//copying str1 to str after str data 
		ptr1++;
		ptr++;
	
	}
	printf("After Concatenating to string 1 %s\n",str);
}
void strreverse(char str[30],char str1[30])		//defination of function strreverse
{	int i;
	int len;
	len=length(str);
	for(i=0;str[i]!='\0';i++)
	{
		str1[len-i-1]=str[i];
	}
	str1[i]='\0';
	printf("After Reversing string is %s\n",str1);		//printing reverse of string str
}
void palindrome(char str[30])			//defination of palindrome function 
	{	int i;
		int len;
			len=length(str);
		for(i=0;i<len;i++)
		{
			if(str[len-1-i]==str[i])	//if last and first are same and so on then it is palindrome
			{
				printf("It is Palindrome\n");
				break;
			}
			else
			{
				printf("it is not Palindrome\n");
				break;
			}
		}
	}
void delete(char str[30])			//defination of delete function 
		{
			str[0]='\0';
		}
void substring(char str[30],char str1[30])	//defination of substring function 
{	int len1;
	int len2;
	len1=length(str);			//calculate length of string str
	len2=length(str1);			//calculate length of string str1
	int flag=0;
	int i=0;
	int j=0,k=0;
	int count=0;
	
	while(i<len1)
	{	int k=0;
		if(str[i]==str1[k])
		{	flag++;
			for(j=1;j<len2;j++)
			{	
				if(str[i+j]==str1[k+j])
				{
					flag++;
				}
				else
				{
					flag=0;
				}
			}
		}
		else
		{
			flag=0;
		}
								
		if(flag==len2)
		{
			count++;		//it will show the no. of occurance 
			flag=0;
		}
		else
		{
			flag=0;
		}		
				
		i++;			
	}
	
	printf("no of occurances are %d\n",count);	//print the no. of occurance 
}
