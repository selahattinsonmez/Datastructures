#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	int num;
	char name[20];
	list *next;
	list *pre;
};



list *baslangic =(list*)malloc(sizeof(list));
/*
void sirala(list *temp,int x){
	int sayi;
	char isim[20];

	list array[x];
	int i,j;
	for(i=0;i<x;i++){
		array[i].num = temp->num;
		strcpy(array[i].name,temp->name);
		temp = temp->next;
	}
	
	
	list degis;
	for(i=0;i<x;i++){
		for(j=1;j<x-i;j++){
			if(array[j-1].num > array[j].num){
				degis = array[j];
				array[j] = array[j-1];
				array[j-1] = degis;
				
				
				
			}
		}
	}
	
	temp = baslangic;
	for(i=0;i<x;i++){
		temp->num=array[i].num;
		strcpy(temp->name,array[i].name);
		temp=temp->next;
	}
}




*/














int main(){
	
	list *temp = baslangic;
	list *silici = (list*)malloc(sizeof(list));
	
	int x,i,j,q,k,degistiren,istek,adet,y;
	int sil[10];
	list tutan[50];
	
	FILE *a = fopen("a.txt","w");

	printf("kac ogrenci");
	scanf("%d",&x);
	
	for(i=0;i<x;i++){
		if(i == 0){
			scanf("%s  %d",&temp->name,&temp->num);
			temp->next = NULL;
			temp->pre = NULL;
	
			
		}
		else{
			temp->next = (list*)malloc(sizeof(list));
			temp->next->pre = temp;
			temp = temp->next;
			scanf("%s  %d",&temp->name,&temp->num);
			temp->next = NULL;
			
			
			
			
		}
	}
	


	
	printf("ekleme yapmak istiyorsanýz 1 e istemiyorsanýz 0 a basýn");
	scanf("%d",&istek);
	
	if(istek == 1){
		
			
	
	
	    //eklenecek ogrenciler
	    printf("kac ogrenci eklemek istersiniz");
	    scanf("%d",&q);
	    list ekle[q];
	    list ekledegis;
	    
	    printf("ogrencileri girin");

	    for(i=0;i<q;i++){
		    scanf("%s %d",&ekle[i].name,&ekle[i].num);
	    }
	    



	    //linked listi tutan struct arrayine eþitleme----
	    temp = baslangic;
	    
	    i=0;
	    while(temp != NULL){
		    tutan[i].num=temp->num;
		    strcpy(tutan[i].name,temp->name);
		    i++;
	    	temp=temp->next;
		
	    }

	    //eklenecek olan ogrencileri struct arrayinin devamýna eþitleme
	    
		
	    k=0;
	    for(i=x;i<x+q;i++,k++){
		    tutan[i].num = ekle[k].num;
		    strcpy(tutan[i].name,ekle[k].name);
		    
    	}
	    
	    


	    //tutaný sýralama


	    for(i=0;i<x+q;i++){
		    for(j=1;j<x+q-i;j++){
		    	if(tutan[j-1].num> tutan[j].num){
				    ekledegis.num=tutan[j].num;
				    tutan[j].num=tutan[j-1].num;
				    tutan[j-1].num=ekledegis.num;
				
			    	strcpy(ekledegis.name,tutan[j].name);
			    	strcpy(tutan[j].name,tutan[j-1].name);
			    	strcpy(tutan[j-1].name,ekledegis.name);
			    }
		    }
    	}
    		//structý linked liste eþitleme
	    temp = baslangic;
	    while(temp->next !=NULL){
	        temp=temp->next;
        }
	    for(i=0;i<q;i++){
	        temp->next = (list*)malloc(sizeof(list));
	        temp = temp->next;
	        temp->next = NULL;
        }    

    }
    
    else{
    	//linked listi tutan struct arrayine eþitleme----
	    temp = baslangic;
	    list ekledegis;
	    i=0;
	    while(temp != NULL){
		    tutan[i].num=temp->num;
		    strcpy(tutan[i].name,temp->name);
		    i++;
	    	temp=temp->next;
		
	    }
	    
	    for(i=0;i<x;i++){
		    for(j=1;j<x+-i;j++){
		    	if(tutan[j-1].num> tutan[j].num){
				    ekledegis.num=tutan[j].num;
				    tutan[j].num=tutan[j-1].num;
				    tutan[j-1].num=ekledegis.num;
				
			    	strcpy(ekledegis.name,tutan[j].name);
			    	strcpy(tutan[j].name,tutan[j-1].name);
			    	strcpy(tutan[j-1].name,ekledegis.name);
			    }
		    }
    	}
	    
	    
	}

    



    temp = baslangic;
    i=0;
   	while(temp != NULL){
	    temp->num = tutan[i].num;
 	    strcpy(temp->name,tutan[i].name);
	    temp=temp->next;
	    i++;
    }
    
    	
	

	
	
	
	
	

    //silme
    printf("silme yapmak istiyorsanýz 1 e istemiyorsanýz 0 a basýn");
	scanf("%d",&istek);

	if(istek == 1){
	
		printf("kaç tane sileceksin");
		scanf("%d",&adet);
		for(y=0;y<adet;y++){
				
	
	        printf("silmek istediginiz %d. kisinin numunu gir",y+1);
	        scanf("%d",&sil[y]);
	        j=0;
	        do{
	            temp=baslangic;
		        for(i=0;i<x+q;i++){

			
			        if(temp->num == sil[y]){
			    	    j=1;
			    	    break;
			        }
			        else{
				        temp=temp->next;
			        }
			
	        	}
		
		        if(j!=1){
			        printf("lutfen dogru gir");
			        scanf("%d",&sil[y]);
		        }
		
	        }while(j==0);

			for(k=0;k<adet;k++){
			
			    if(baslangic->num == sil[y]){
		        baslangic->next->pre = baslangic;
		        baslangic = baslangic->next;
		        baslangic->pre=NULL;
		    }
	        else{
		        temp=baslangic;
		        silici=baslangic->next;
		        while(silici != NULL){
			
			        if(silici->num == sil[y]){
				        temp->next = silici->next;
				        temp->next->pre=temp;
				        delete silici;
				        break;
			        }
			        silici= silici->next;
			        temp=temp->next;
			    }
		
	        }
	    }

	       
	
	
		}

	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	temp = baslangic;
	while(temp!=NULL){
		fprintf(a,"%s\t%d\n",temp->name,temp->num);
		printf("%s\t%d\n",temp->name,temp->num);
		temp= temp->next;
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
	
}
	
	
	

	
	

