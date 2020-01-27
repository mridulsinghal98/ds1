
#include<stdio.h>
#include"stk.h"
#include"strstk.h"

int isp(char ch);
int icp(char ch1);

int main(){
	char infix[20];
	char postfix[20];
	char c;
	int k=0;

	printf("\n\t Enter an Infix Expression : ");
	scanf("%s",infix);

	for(int i = 0; infix[i] != '\0'; i++){
		if(infix[i]>= 'A' && infix[i]<='Z'){
			postfix[k]=infix[i];
			k++;
		}
		else if(infix[i] == '('){
			push('(');
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^'){
			while(top >= 0 && isp(stack[top]) >= icp(infix[i])){
				postfix[k]=pop();
				k++;
			}
			push(infix[i]);
		}
		else if(infix[i]==')'){
			while((c=pop())!='('){
				postfix[k]=c;
				k++;
			}
		}
		else
		{
			postfix[k]=infix[i];
			k++;#ifndef STK_H_
#define STK_H_

char stack[20];
int top = -1;

int stkemp(){
	if(top == -1){
		return (1);
	}
	else
		return (0);
}

int stkfull(){
	if(top == 19)
		return (1);
	else
		return (0);
}

void push(char ele){
	if(stkfull() == 0){
		top++;
		stack[top]=ele;
	}
}

char pop(){
	char temp;
	if(stkemp() == 0){
		temp = stack[top];
		top--;
	}
		return (temp);
}


#endif /* STK_H_ */
		}
	}
		while(top >= 0){
			postfix[k]=pop();
			k++;
		}
		printf("\n\t Postfix is  %s \n",postfix);

	return (0);
}

int isp(char ch){
	if(ch == '+' || ch == '-' )
		return  (1);
	if(ch == '*' || ch == '/' || ch == '%')
		return (2);
	if(ch == '^' )
		return (3);
	if(ch == '(')
		return (0);

	return (-1);
}

int icp(char ch){
	if(ch == '+' || ch == '-' )
		return  (1);
	if(ch == '*' || ch == '/' || ch == '%')
		return (2);
	if(ch == '^' )
		return (4);
	if(ch == '(')
		return (5);

	return (-1);
}


#ifndef STK_H_
#define STK_H_

char stack[20];
int top = -1;

int stkemp(){
	if(top == -1){
		return (1);
	}
	else
		return (0);
}

int stkfull(){
	if(top == 19)
		return (1);
	else
		return (0);
}

void push(char ele){
	if(stkfull() == 0){
		top++;
		stack[top]=ele;
	}
}

char pop(){
	char temp;
	if(stkemp() == 0){
		temp = stack[top];
		top--;
	}
		return (temp);
}


#endif /* STK_H_ */

