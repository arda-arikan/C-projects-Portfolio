#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int tahminim1,tahminim;
	srand(time(NULL));
	int rastgelesayi = rand() % 100 + 1;
	printf("Sayi tahmin ediniz(1-100 arasinda): ");
	scanf("%d",&tahminim1);
	if(tahminim1<1 || tahminim1>100){
	printf("Arilikta bir sayi giriniz.");
	return 0;
   }
	while(1){
		printf("\nTahminde bulunun: ");
		scanf("%d",&tahminim);
		if(tahminim>rastgelesayi){
		printf("\nSayinizi kucultun.");	
		}
		else if(tahminim == rastgelesayi){
		printf("\nTEBRIKLER SAYINIZ %d DI",rastgelesayi);
		return 0;
		}
		else{
		printf("\nSayinizi buyutun");
		}
	}
}
