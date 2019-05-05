#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	char infix[100];
	list *next;
	list *pre;
};
list *baslangic=(list*)malloc(sizeof(list));
list *temp=baslangic;


int main(){
	
	
	char postfix[100];
	char c[30],d,a;
	
	gets(postfix);
	int k=strlen(postfix);
	list *silici1,*silici2;
	int j;
	for(int i=0;i<k;i++){
		if(i==0){
			temp->infix[0]=postfix[i];
			temp->pre=NULL;
			temp->next=NULL;

		}
		else{
			temp->next=(list*)malloc(sizeof(list));
			temp->next->pre=temp;
			temp=temp->next;
			temp->infix[0]=postfix[i];
			temp->next=NULL;
		}
	}
	temp=baslangic;
	//printf("basarili\n");
	while(temp!=NULL){
		temp->infix[1]=NULL;
		temp->infix[2]=NULL;
		temp=temp->next;
	}
	temp=baslangic;
	


	while(temp!=NULL){
        if(temp->infix[0] == '*'||temp->infix[0] == '+'||temp->infix[0] == '-'||temp->infix[0] == '/'){

			c[0]=temp->infix[0];
        	strcpy(temp->infix,"(");
        	

			strcat(temp->infix,temp->pre->infix);

			
			//printf("temp %s\n",temp->infix);
        	
        	k=strlen(temp->infix);
        	temp->infix[k]=c[0];
            

			strcat(temp->infix,temp->pre->pre->infix);


			
			
        	strcat(temp->infix,")");
    		//printf("basarili2\n");
	    	    	//NULL A (C+B) - NULL
			
			
			strcpy(&d,temp->infix);
	    	
			
			
			if(temp->next == NULL){
				temp=temp->pre->pre;
				temp->next=NULL;
			}
			else{
				silici1=temp->next;
	    		temp=temp->pre;
	    		temp=temp->pre;
	    		temp->next=silici1;
	    		silici1->pre=temp;
	    		
			}
	    	strcpy(temp->infix,&d);
    
				

		}
		else{
			temp=temp->next;
		}
	}
	temp=baslangic;
	
	printf("%s",temp->infix);
	
	

	
	
	
}
