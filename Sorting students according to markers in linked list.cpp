#include <stdio.h>
#define MAX 50



struct ogrenci{
	char isim[50];
	char soyisim[50];
	int num;
};





int main(){
	int x;
	int i;
	int j;
	int k;
	int temp;
	
	char tempp[50];
	char temppp[50];
	char tempppp[50];
	char temppppp[50];
	printf("kac ogrenci");
	scanf("%d",&x);
	
	if (x<1){
		printf("0 olmaz");
		return 0;
	}
	struct ogrenci ogrenciler[50];
	
	int arr[50];
	

	
	
	
	
	
	
	
	
	FILE *u = fopen("u.txt","w");
	if (u == NULL){
		printf("dosya olusturulamady");
	}
	else{
		printf("dosya olusturuldu \n");
	}

	
	for(i=0;i<x;i++){
        scanf("%s %s %d",&ogrenciler[i].isim,&ogrenciler[i].soyisim,&ogrenciler[i].num);
		
	}
	for(i=0;i<x;i++){
		arr [i] = ogrenciler[i].num;
	}
	
	
   

	
	for(i=0;i<x;i++){

	    for(j=1;j<x-i;j++){
		
	        if(arr[j-1] > arr[j]){
			
	        	temp = arr[j];
	        	arr[j] =arr[j-1];
	        	arr[j-1] = temp;
	        	
	        	for(k=0;k<50;k++){
	        		tempp[k] = ogrenciler[j].isim[k];
	        		temppp[k] = ogrenciler[j-1].isim[k];
	        		tempppp[k] = ogrenciler[j].soyisim[k];
	        		temppppp[k] = ogrenciler[j-1].soyisim[k];
	        		
	        		
				}
				
				for(k=0;k<50;k++){
	        		ogrenciler[j].isim[k] = NULL;
	        		ogrenciler[j-1].isim[k] = NULL;
	        		ogrenciler[j].soyisim[k] = NULL;
	        		ogrenciler[j-1].soyisim[k] = NULL;
	        		
	        		
				}
				for(k=0;k<50;k++){
	        		ogrenciler[j].isim[k] = temppp[k];
	        		ogrenciler[j-1].isim[k] = tempp [k];
	        		ogrenciler[j].soyisim[k]= temppppp[k];
	        		ogrenciler[j-1].soyisim[k] = tempppp[k];
	        		
	        		
				}
				
	        	
	        	
	        	 
			}
	        	
            }
	   
	   
	   
	    }
	
	for(i=0;i<x;i++){
		ogrenciler[i].num = arr[i];
	}
	       	
	  	
	
	


	
	for(i=0;i<x;i++){
		fprintf(u,"%s \t %s \t %d \n",ogrenciler[i].isim,ogrenciler[i].soyisim,ogrenciler[i].num);
		
	}
	
	
	

	
	
	
	
	
	
	


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

