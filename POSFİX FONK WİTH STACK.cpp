#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	char post[100];
	stack *next;
	stack *pre;
};
stack *first = (stack*)malloc(sizeof(stack));
stack *temp=first;

void push(char c[])
{
	int array_size=strlen(c);
	for(int  i = 0 ; i < array_size ; i++)
	{
		if(i==0)
		{
			temp->post[0]=c[i];
			temp->next=NULL;
			temp->pre=NULL;
		}
		else
		{
			temp->next = (stack*)malloc(sizeof(stack));
			temp->next->pre=temp;
			temp=temp->next;
			temp->post[0]=c[i];
			temp->next=NULL;
		}
	}
	
	temp=first;
	
	while(temp!=NULL){
		temp->post[1]=NULL;
		temp->post[2]=NULL;
		temp=temp->next;
	}
}

char pop(stack *temp)
{
	
}

int main()
{
	char posfix[100];
	gets(posfix);
	push(posfix);
	
	temp=first;
	
	
	
}
