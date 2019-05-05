#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bTree{
	int info;
	struct bTree *left;
	struct bTree *right;
	
}BTREE;
BTREE *temp;
BTREE *tempp;

BTREE *root=NULL;
void insert(BTREE *treeRoot,BTREE *newNode,int a){
	
	if(treeRoot == NULL){
		root=newNode;
	}
	else{
		if(newNode->info<treeRoot->info){
			if(treeRoot->left==NULL){
				
				treeRoot->left=newNode;
				
			}
			else{
				
				insert(treeRoot->left,newNode,a);
				
				
			}
		}
		else{
			if(treeRoot->right==NULL){
				
				treeRoot->right=newNode;
				
			}
			else{
			
				insert(treeRoot->right,newNode,a);
					
				}
			
			
		}
	}

}

BTREE *createNode(int i){
	BTREE *newNode;
	newNode = (BTREE*)malloc(sizeof(BTREE));
	if(newNode==NULL){
		return NULL;
	}
	newNode->info=i;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
int yukseklik(BTREE *temp ){
	int count1=0,count2=0;
	if(temp==NULL){
		return 5;
	}
	else{
		count1=yukseklik(temp->right);
		count2=yukseklik(temp->left);
		if(count1>count2){
			
			return count1+1;
		}
		else{
		
			return count2+1;
		}

	}

}
int goster(BTREE *a){
	if(a==NULL){
		return 0;
	}
	
	
	goster(a->left);
	printf("%d",a->info);
	goster(a->right);
	
	return 0;
	
}
/*                 6
               2    8
			  1 4     10
			   3 5       12
			               13
			                 14
			                 */
int main(){
	int array[]={6,2,1,8,4,3,5,10,12,13,14};
	int count,b;
	
	for(int i=0;i<11;i++){

		temp=createNode(array[i]);
		insert(root,temp,b);


	}
	temp=root;
	count =yukseklik(temp);

	printf("%d\n",count);
	temp=root;
	goster(temp);
	
	
	
}
