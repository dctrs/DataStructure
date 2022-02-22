#include<stdio.h> 
#include<string.h> 

int main(){
	
	int sayi1[100],sayi2[100],toplam[101],a[100000],b[100000],ans[2000]={0},Result[100];
	char s1[100],s2[100];
	int l1,l2,input,i,j,tmp,carry,k,sub,diff;	
	
	printf("Toplama islemi icin 1\nCikarma islemi icin 2\nCarpma islemi icin  3 giriniz: ");
	scanf("%d", &input);	
	if(input==1||input==2||input==3){
		
		printf("1. sayiyi girin: "); 
		scanf("%s", &s1); 
		printf("2. sayiyi girin: "); 
		scanf("%s", &s2); 	
		
		// char dizisinden int dizisine donusturma
		for (l1 = 0; s1[l1] != '\0'; l1++){
			sayi1[l1] = s1[l1] - '0';
		}		
		for (l2 = 0; s2[l2] != '\0'; l2++){
			sayi2[l2] = s2[l2] - '0'; 
		}
				
		
		// toplama
		if(input ==1){
			//sayilari ekrana yazdirma
			printf("Sayi 1: ");
			for (l1 = 0; s1[l1] != '\0'; l1++){
				printf("%c ",s1[l1]);
			}	
			printf("\nSayi 2: ");	
			//bosluklari hesaplama
			diff=l1-l2;
			if(diff>0){
				for(int a=0;a<diff*2;a++){
					printf(" ");	
				}
			}		
			for (l2 = 0; s2[l2] != '\0'; l2++){
				printf("%c ",s2[l2]);
			}	
			printf("\n");
			
			carry = 0,k = 0; 
			i = l1 - 1; 
			j = l2 - 1;
			for (; i >= 0 && j >= 0; i--, j--, k++) {
				toplam[k] = (sayi1[i] + sayi2[j] + carry) % 10;
				carry = (sayi1[i] + sayi2[j] + carry) / 10; 
			}
			if(l1 > l2){ 
				while (i >= 0){ 
					toplam[k++] = (sayi1[i] + carry) % 10; 
					carry = (sayi1[i--] + carry) / 10; 
				}
			}
			else if (l1 < l2){ 
				while (j >= 0) { 
					toplam[k++] = (sayi2[j] + carry) % 10; 
					carry = (sayi2[j--] + carry) / 10; 
				} 
			}
			else{ 
				if(carry > 0){
					toplam[k++] = carry; 
				}
			}
			printf("Sonuc : "); 
			for (k--; k >= 0; k--){
				printf("%d ", toplam[k]); 
			}			
		}
		//cikarma
		else if(input==2){
			
			//sayilari ekrana yazdirma
			printf("Sayi 1: ");
			for (l1 = 0; s1[l1] != '\0'; l1++){
				printf("%c ",s1[l1]);
			}	
			printf("\nSayi 2: ");	
			//bosluklari hesaplama
			diff=l1-l2;
			if(diff>0){
				for(int a=0;a<diff*2;a++){
					printf(" ");	
				}
			}		
			for (l2 = 0; s2[l2] != '\0'; l2++){
				printf("%c ",s2[l2]);
			}	
			printf("\n");
			
			carry=0, k=0;					
			for(int i = l2 - 1; i >= 0; i--,k++){
				sub=sayi1[i+diff]-(sayi2[i])-carry;
				if(sub<0){
					sub=sub+10;
					carry=1;
				}
				else{
					carry=0;
				}
				Result[k]=sub;		
			}
			for (int i = l1 - l2 - 1; i >= 0; i--) {
		        if (sayi1[i] == 0 && carry > 0) {
		        	sayi1[i]=9;    
					continue;
		        }
		        sub = (sayi1[i]- carry);
				if (i > 0 || sub > 0){
		            Result[k]=sub;
		            k++;          
		        }
		        carry = 0;
		    }
			printf("Sonuc : ");
			if(k<l1){
				diff=l1-k;
			for(int a=0;a<diff*2;a++){
				printf(" ");	
				}
			}
			for(int i=k-1;0<=i;i--){
				printf("%d ",Result[i]);		
			}		
		}
		//carpma
		else if(input==3){
			for(i = l1-1,j=0;i>=0;i--,j++){
	        	a[j] = s1[i]-'0';
	    	}
		    for(i = l2-1,j=0;i>=0;i--,j++){
		        b[j] = s2[i]-'0';
		    }
		    for(i = 0;i < l2;i++){
		        for(j = 0;j < l1;j++){
		            ans[i+j] += b[i]*a[j];
		        }
		    }
		    for(i = 0;i < l1+l2;i++){
		        tmp = ans[i]/10;
		        ans[i] = ans[i]%10;
		        ans[i+1] = ans[i+1] + tmp;
		    }
		    for(i = l1+l2; i>= 0;i--){
		        if(ans[i] > 0)
		            break;
		    }
		    //sayilari ekrana yazdirma
			printf("Sayi 1: ");
			int dif2=i-l1+1;
		    if(dif2>0){
				for(int a=0;a<dif2*2;a++){
					printf(" ");	
				}
			}
			for (l1 = 0; s1[l1] != '\0'; l1++){
				printf("%c ",s1[l1]);
			}	
			printf("\nSayi 2: ");	
			//bosluklari hesaplama
			int dif3=i-l2+1;
			if(dif3>0){
				for(int a=0;a<dif3*2;a++){
					printf(" ");	
				}
			}		
			for (l2 = 0; s2[l2] != '\0'; l2++){
				printf("%c ",s2[l2]);
			}	
			printf("\n");
		    printf("Sonuc : ");
		    for(;i >= 0;i--){
		        printf("%d ",ans[i]);
		    }	    	
		}
	}
	else{
		printf("Hatali giris");
		return 0;
	}		
}
