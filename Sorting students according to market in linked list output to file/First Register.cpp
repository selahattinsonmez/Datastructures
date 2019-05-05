#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	FILE *y;
	char name[20];
	char surname[20];
	char file[20];
	int num;
	int point;
	
	
	list *next;
	list *pre;
};
struct dosya{
	char dosyaisim[20];
	char isim[20];
	char soyisim[20];
	int numara;
	int puan;
};

/*void sirala(struct dosya dosyalar[],int arr[],int x){


	int i,j;
	int degis;
	char degistiren[20];
	char rty[10]="as";


	for(i=0;i<x;i++){
		for(j=1;j<x-i;j++){
			if(arr[j]<arr[j-1]){
				degis = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = degis;
				

				
				strcpy(degistiren,dosyalar[j].dosyaisim);
				strcpy(dosyalar[j].dosyaisim,dosyalar[j-1].dosyaisim);
				strcpy(dosyalar[j-1].dosyaisim,degistiren);
				

			}

		}

	}
	

}*/




int main(){
	list *baslangic = (list*)malloc(sizeof(list));
	list *temp = baslangic;
	
	int i,sayi,j,k,sayii,tut,islem=0;

	


	char dosyaismi;
	FILE *z;
	FILE *p  = fopen("dosyaisimleri.txt","w");

	printf("kac ogrenci bilgisi gireceksiniz");
	scanf("%d",&sayi);
	fprintf(p,"%d\n",sayi);
	tut = sayi;
    fprintf(p,"%d\n",islem);
	struct dosya dosyalar[sayi];
	
	int array[sayi];

	for(i=0;i<sayi;i++){
		if(i==0){
			temp->next = NULL;
			temp->pre=NULL;
		}
		else{
			temp->next = (list*)malloc(sizeof(list));
			temp->next->pre = temp;
			temp = temp->next;
			temp->next = NULL;
		}

	}
	temp=baslangic;

	while(temp!=NULL){
		printf("dosyaismi gir\n");
		scanf("%s",&temp->file);
		printf("isim,soyisim,numarasini ve puanini gir\n");
		scanf("%s %s %d %d",&temp->name,&temp->surname,&temp->num,&temp->point);
		temp=temp->next;
	}
	

	
	
	temp=baslangic;

	while(temp!=NULL){
	

		z=fopen(temp->file,"w");
		

	    temp->y = z;
		fprintf(temp->y,"%s %s %d %d",temp->name,temp->surname,temp->num,temp->point);
		
		temp=temp->next;


	}
	
	
	

	temp=baslangic;

    while(temp!=NULL){
	    fprintf(p,"%s\n",temp->file);
	    temp=temp->next;
        
  
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*list *baslangic = (list*)malloc(sizeof(list));
	list *temp = baslangic;
	
	int i,sayi,j,k,sayii,tut;

	


	char dosyaismi;
	FILE *z;
	FILE *p  = fopen("dosyaisimleri.txt","w");

	printf("kac sayi olacak");
	scanf("%d",&sayi);
	fprintf(p,"%d\n",sayi);
	tut = sayi;

	struct dosya dosyalar[sayi];
	
	int array[sayi];

	for(i=0;i<sayi;i++){
		if(i==0){
			temp->next = NULL;
			temp->pre=NULL;
		}
		else{
			temp->next = (list*)malloc(sizeof(list));
			temp->next->pre = temp;
			temp = temp->next;
			temp->next = NULL;
		}

	}
	temp=baslangic;
	i=0;
	while(temp!=NULL){
		printf("dosyaismi gir");
		scanf("%s",&dosyalar[i].dosyaisim);
		
		printf("sayiyi gir");
		scanf("%d",&array[i]);
		i++;
		temp=temp->next;
	}
	

	
	
	temp=baslangic;
	i=0;
	while(temp!=NULL){
	
		strcpy(&dosyaismi,dosyalar[i].dosyaisim);
		z=fopen(&dosyaismi,"w");

	
		fprintf(z,"%d",array[i]);
		temp->y = z;
		temp=temp->next;
		
		i++;

	}
	
	
	

	temp=baslangic;
    i=0;
    while(temp!=NULL){
	    fprintf(p,"%s\n",dosyalar[i].dosyaisim);
	    temp=temp->next;
        
        i++;
	}
	*/
	
	
	
	
	
	
	
	
	
	return 0;
}
