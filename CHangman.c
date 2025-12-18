#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct COPADAM{
	char gizlidizi[30];
	char gorunendizi[30];
};

int main(){
	
	struct COPADAM bulmaca;
	int a,uzunluk,can=5;
	char harf;
	printf("BULDURACAK KISI YAZSIN(KELIME NE OLACAK): ");
	scanf("%s",bulmaca.gizlidizi);
	//Bu adým ekran temizlememize yarar 2. oyuncu ekran gormesin diye ekran temizlememzie ise yarýyor
	system("cls"); //clear screen anlamýnda
	
	uzunluk = strlen(bulmaca.gizlidizi); //uzunlugu strlen komutu ile buluyoruz
	
	 for(a=0;a<uzunluk;a++){ //oyuncalara kelimenin uzunlugunu gostereck sekilde yýldýz koyduk
	 	bulmaca.gorunendizi[a] = '*';
	 }
	 
	 bulmaca.gorunendizi[uzunluk] = '\0';
	 
	 printf("Oyun Basliyorrr\n");
	 printf("\nDenem Hakkýnýz: %d",can);
	 printf("Kelime: %s\n", bulmaca.gorunendizi);
	 
	 while(1){
	 	int bildimi = 0;//Hak tanýmak icin atadýgýmýz bir degisken eger asagýdaki for dongusunden cýktýgýnda bilmez ise basta atadýgýmýz 0 olacagý icin canýmýzdan 1 eksiltecek ve 0 olana kadar azalýrsa oyunu bitirecek
	 	printf("\nHarf Tahmini Ediniz: ");
	 	scanf(" %c", &harf);
	 	for(a=0;a<uzunluk;a++){
	 		if(bulmaca.gizlidizi[a] == harf){
	 			bulmaca.gorunendizi[a] = harf;
	 			bildimi = 1;
			 }
			 
		 }
		 
		 if(bildimi == 0){
		 	can--;
		 }
		 
		 if(can == 0){
		 	printf("\nMALESEF KAYBETTÝNÝZ KELÝME: %s",bulmaca.gizlidizi);
		 	break;
		 }
		 
		 
		 printf("\nSon Hal: %s", bulmaca.gorunendizi);
	 	
	 	
	   //Burada string.h kutuphasnesindeki strcmp komutuna ihityac duyacagýz strcmp komutu bize iki kelimenin karsýlasýtrmasýný yapar ornegin strcmp(kelime1, kelime2) iki kelime birbirinin aynýsý ise cevap 0 degil ise 1 olur
	   if(strcmp(bulmaca.gizlidizi, bulmaca.gorunendizi) == 0){
	   	printf("\n\n**********************");
	   	printf("\nTEBRIKLER BULDUNUZ KELIME: %s", bulmaca.gizlidizi);
	   	printf("\n**********************");
	   	break;
	   }
	   
	 } 
	 
}
