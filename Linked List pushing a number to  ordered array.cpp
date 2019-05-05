#include <stdio.h>
#include <stdlib.h>


struct number{
	int num;
	number *next;
	number *pre;
	
	
	
	
};



int main(){
	number *baslangic=(number*)malloc(sizeof(number));
	number *dur=(number*)malloc(sizeof(number));
	number *temp = baslangic;
	int arr[10] = {20,40,80,250,500,1000,2000,5000,8000,10000};
	int sayi;
	int i=0;
	int array[11];

	
	
	
	for(i=0;i<10;i++){
		if(i == 0){
			temp->num = arr[i];
			temp->next = NULL;
			temp->pre = NULL;
			
		}
		else{
			temp->next = (number*)malloc(sizeof(number));
			temp->next->pre = temp;
			temp = temp->next;
			temp->num = arr[i];
			temp->next = NULL;
		}
	}
	
	
	while (temp != NULL){
		printf("%d\n",temp->num);
		temp= temp->pre;
	}
	
	
	
	
	temp = baslangic;

	printf("sayiyi giriniz");
	
	scanf("%d",&sayi);
	
	printf("girdiginiz sayi :%d  \n",sayi);

	
	while(temp != NULL){
		
		
		if(temp->num<sayi){
			temp= temp->next;
			
		}
		
		else{
		
			dur=temp;
			break;
		}
	}

	

	

	temp = baslangic;
	i=0;
	while (temp->next != NULL){
		
		if(temp == dur){
			array[i] = sayi;
			i++;
		}
		array[i] = temp->num;
		temp= temp->next;
		i++;
		
		
		
	}
	array[i]= temp->num;
	if(temp->num < sayi){
		array[i+1] = sayi;
	}
	
	for(i=0;i<11;i++){
		printf("array %d\n",array[i]);
	}
	
	
	
	temp->next = (number*)malloc(sizeof(number));
	temp = temp->next;
	temp->next = NULL;

	
	
	
	temp = baslangic;
	
	
	for(i=0;i<11;i++){
		temp->num = array[i];
		temp = temp->next;
		
	}
	
	temp = baslangic;
	
	while (temp != NULL){
		printf("%d \n",temp->num);
		temp= temp->next;
	}
	


	
	
	
	
		
	
    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0 ;
}
