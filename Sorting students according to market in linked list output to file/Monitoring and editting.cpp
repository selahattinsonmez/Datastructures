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
list *baslangic = (list*)malloc(sizeof(list));
struct dosya{
	char dosyaisim[20];
	char isim[20];
	char soyisim[20];
	int numara;
	int puan;
};
struct isim{
	char asd[20];
	int numa;
};
struct isim isimler[100];

struct dosya dosyalar[100];


void sirala(struct dosya dosyalar[],int x,struct isim isimler[]){


	int i,j,k,t,b,n,q,o;
	int degis;
	char a;
	char say[20]="0123456789";
	char rty[3]="a";
	char degistiren[20];
	char degistirenn[20];
	


	for(i=0;i<x;i++){
		for(j=1;j<x-i;j++){
			if(dosyalar[j].puan>dosyalar[j-1].puan){
				degis = dosyalar[j].puan;
				dosyalar[j].puan = dosyalar[j-1].puan;
				dosyalar[j-1].puan = degis;
				
				strcpy(degistirenn,dosyalar[j].dosyaisim);
				strcpy(dosyalar[j].dosyaisim,dosyalar[j-1].dosyaisim);
				strcpy(dosyalar[j-1].dosyaisim,degistirenn);
				
				
				
				strcpy(degistirenn,dosyalar[j].isim);
				strcpy(dosyalar[j].isim,dosyalar[j-1].isim);
				strcpy(dosyalar[j-1].isim,degistirenn);
				
				
				strcpy(degistirenn,dosyalar[j].soyisim);
				strcpy(dosyalar[j].soyisim,dosyalar[j-1].soyisim);
				strcpy(dosyalar[j-1].soyisim,degistirenn);
				
				degis=dosyalar[j].numara;
				dosyalar[j].numara=dosyalar[j-1].numara;
				dosyalar[j-1].numara=degis;
		
				

			}

		}

		
	}
	for(i=0;i<x;i++){
	    strcpy(isimler[i].asd,dosyalar[i].dosyaisim);
	}
	
	
	for(i=1;i<x+1;i++){
		for(o=0;o<20;o++){
        	degistiren[o]=NULL;
		}
		if(i<10){
		    degistiren[0]= say[i];
		    k = strlen(dosyalar[i-1].dosyaisim);

		    for(q=1,j=0;q<k+1;q++,j++){
			    degistiren[q]=dosyalar[i-1].dosyaisim[j];
		    }
		    strcpy(dosyalar[i-1].dosyaisim,degistiren);
	    }
	    else{
	    	b = i % 10;
	    	n = i /10;
			degistiren[0]=say [n];
			degistiren[1]=say[b];
			k = strlen(dosyalar[i-1].dosyaisim);
		    for(q=2,j=0;q<k+2;q++,j++){
			    degistiren[q]=dosyalar[i-1].dosyaisim[j];
		    }
		    strcpy(dosyalar[i-1].dosyaisim,degistiren);			
	    	
	    	
		}
		

	    
	}
	
	
	

}
int main(){
	
	list *temp = baslangic;
	
	int i,sayi,j,tut,istek,adet=0,degisen,yeni,k,dadet,sadet=0,sil[20],sayac[i],t,adettut=0,islem,islemm=1;
	list *silici= (list*)malloc(sizeof(list));

	char dosyaismi[20];

	FILE *z;
	FILE *p = fopen("dosyaisimleri.txt","r");

	fscanf(p,"%d",&sayi);
    fscanf(p,"%d",&islem);
	tut = sayi;

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
	i=0;
	temp=baslangic;
	if(islem==0){
	
	    
    
	while(temp!=NULL){
		fscanf(p,"%s",&temp->file);
		z = fopen(temp->file,"r");
		temp->y = z;
		fscanf(temp->y,"%s %s %d %d",&temp->name,&temp->surname,&temp->num,&temp->point);
		//printf("%s\n",temp->file);
	    fclose(z);
		remove(temp->file);
		strcpy(dosyalar[i].dosyaisim,temp->file);
		strcpy(dosyalar[i].isim,temp->name);
		strcpy(dosyalar[i].soyisim,temp->surname);
		dosyalar[i].numara=temp->num;
		dosyalar[i].puan=temp->point;
		temp = temp->next;
        i++;
	}

	}
	else{
	    while(temp!=NULL){
	    	fscanf(p,"%s",&dosyaismi);
	    	z=fopen(dosyaismi,"r");
	    	temp->y=z;
			fscanf(temp->y,"%s %s %d %d",&temp->name,&temp->surname,&temp->num,&temp->point);
	        fclose(z);
		    remove(dosyaismi);
		    strcpy(dosyalar[i].isim,temp->name);
		    strcpy(dosyalar[i].soyisim,temp->surname);
		    dosyalar[i].numara=temp->num;
		    dosyalar[i].puan=temp->point;
		    temp = temp->next;
            i++;
		}
		temp=baslangic;
		i=0;
		while(temp!=NULL){
			fscanf(p,"%s",&temp->file);
			strcpy(dosyalar[i].dosyaisim,temp->file);
			temp=temp->next;
			i++;
		}
	    
		
	}
	
	temp=baslangic;
	while(temp!=NULL){
		printf("%s %s %s %d %d\n",temp->file,temp->name,temp->surname,temp->num,temp->point);
		temp=temp->next;
	}

	
	
	temp=baslangic;
	while(temp->next!=NULL){
		temp=temp->next;
		
	}
	

	

	
	
    printf("yeni ogrenci eklemek istiyorsaniz 1'e istemiyorsaniz 0'a basin\n");
	scanf("%d",&istek);
	while(istek!=0 && istek!=1){
		printf("yanlis girdiniz\nlutfen yeni ogrenci eklemek istiyorsaniz 1'e istemiyorsaniz 0'a' basin\n");
		scanf("%d",&istek);
	}
	
	if(istek == 1){
		printf("kac adet ogrenci ekleyeceksiniz\n");
		scanf("%d",&adet);
		adettut=adet;
		for(i=0;i<adet;i++){
		    temp->next=NULL;			
			temp->next=(list*)malloc(sizeof(list));
			temp=temp->next;
			printf("dosya ismini giriniz\n");
			scanf("%s",&temp->file);
			printf("isim,soyisim,numara ve puani giriniz\n");
			scanf("%s %s %d %d",&temp->name,&temp->surname,&temp->num,&temp->point);
			strcpy(dosyalar[tut+i].dosyaisim,temp->file);
		    strcpy(dosyalar[tut+i].isim,temp->name);
		    strcpy(dosyalar[tut+i].soyisim,temp->surname);
		    dosyalar[tut+i].numara=temp->num;
		    dosyalar[tut+i].puan=temp->point;


			
		}
		
	}
	temp->next=NULL;
	
	printf("herhangi bir ogrencinin puanini degistirmek istiyorsaniz 1'e istemiyorsaniz 0'a basin\n");
	scanf("%d",&istek);
	while(istek!=0 && istek!=1){
		printf("yanlis girdiniz\nlutfen istiyorsaniz 1'e istemiyorsaniz 0'a' basin\n");
		scanf("%d",&istek);
	}
	if(istek==1){
	
	    printf("kac adet degisiklik yapacaksiniz");
	    scanf("%d",&dadet);
	
	}
	
	for(i=0;i<dadet;i++){
		printf("degistirmek %d. istediðiniz kisinin numarasini girin",i+1);
		scanf("%d",&degisen);
		do{
			for(k=0;k<tut+adettut;k++){
				if(dosyalar[k].numara == degisen){
					j=1;
					break;
				}
                
			}
			if(j!=1){
			printf("boyle bir numara yok lutfen dogru giriniz");
            scanf("%d",&degisen);
            }
		}while(j==0);
		
		
	    printf("yeni puani giriniz");
	    scanf("%d",&yeni);
		temp=baslangic;
		j=0;
		while(degisen != temp->num){
			temp=temp->next;
			j++;
		}
		temp->point=yeni;
		dosyalar[j].puan=yeni;
	}
	

	
	temp=baslangic;
	printf("ogrenci silme islemi yapmak istiyorsaniz 1e istemiyorsaniz 0a basin");
	scanf("%d",&istek);
	if(istek == 1){
		printf("kac ogrenci silmek istersiniz");
		scanf("%d",&sadet);
		for(i=0;i<sadet;i++){

			printf("silmek istediðiniz kisinin numarasini giriniz");
			scanf("%d",&sil[i]);
			j=0;
			do{
				temp=baslangic;
                while(temp!=NULL){
				    
					if(sil[i] == temp->num){
					    j=1;
					    
						break;
				    }
				    else{
					temp=temp->next;
					}

				}
				if(j!=1){
				    printf("boyle bir numara yok lutfen dogru giriniz");
				    scanf("%d",&sil[i]);

				}
				if(j==1){
					break;
				}

			}while(j==0);
		}

		
	}

	for(i=0;i<sadet;i++){
			
		temp=baslangic;	   
				
		if(baslangic->num==sil[i]){
			baslangic=baslangic->next;
			baslangic->pre=NULL;
		}
		else{

				temp=baslangic;
				silici=baslangic->next;
				while(silici!=NULL){
					if(silici->num==sil[i]){
					    temp->next = silici->next;
					    temp->next->pre=temp;
					    delete silici;
					    break;
					}
				    else{
					silici=silici->next;
				    temp=temp->next;
					}
				}
		
		}	
           
				
	
	}


	i=0;
	temp=baslangic;
	while(temp!=NULL){
		strcpy(dosyalar[i].dosyaisim,temp->file);
		strcpy(dosyalar[i].isim,temp->name);
		strcpy(dosyalar[i].soyisim,temp->surname);
		dosyalar[i].numara=temp->num;
		dosyalar[i].puan=temp->point;
		temp=temp->next;
		i++;
	}	
	
	sirala(dosyalar,tut+adet-sadet,isimler);
	temp=baslangic;
	i=0;
	while(temp!=NULL){
		strcpy(temp->file,dosyalar[i].dosyaisim);
		strcpy(temp->name,dosyalar[i].isim);
		strcpy(temp->surname,dosyalar[i].soyisim);
		temp->num=dosyalar[i].numara;
		temp->point=dosyalar[i].puan;
		temp=temp->next;
		i++;
	}
	

	p = fopen("dosyaisimleri.txt","w");
	fprintf(p,"%d\n",tut+adet-sadet);
	fprintf(p,"%d\n",islemm);
	
	
	temp=baslangic;
	while(temp!=NULL){
		    
	fprintf(p,"%s\n",temp->file);
	temp=temp->next;
	}
    
    for(i=0;i<tut+adet-sadet;i++){
    	fprintf(p,"%s\n",isimler[i].asd);
	}
	
	temp=baslangic;
	while(temp!=NULL){
		
		z = fopen(temp->file,"w");
		temp->y=z;
		fprintf(temp->y,"%s %s %d %d\n",temp->name,temp->surname,temp->num,temp->point);
		temp=temp->next;
	}
	return 0;
}
