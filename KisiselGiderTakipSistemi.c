#include <stdio.h>

struct Harcama{
	char aciklama[60];
	char kategori[50];
	float fiyat;
	char tarih[20]; //Burda char dememiz sayisal olarak tarihi alsak da string olarak tarihi yazdýracagýz
	
};

int main(){
	
	while(1){
		int sayi;
		printf("\n1.Yeni Harcama Ekle");
	    printf("\n2.Harcamalari Listele");
	    printf("\n3.Toplam Harcama");
	    printf("\n4.Cikis");
	    printf("\nLutfen yapmak istediginiz islemi tusalyin: ");
	    scanf("%d",&sayi);
	    
	    if(sayi>4 || sayi<1){
	    	printf("Hatali tuslama yaptiniz");
	    	return 1;
		}
		
	    switch(sayi){
	    	
	    	case 1:{
	    		struct Harcama girdi;
	    		printf("\nNe Adiniz(Aciklama): ");
	    		scanf("%s",girdi.aciklama);
	    		printf("\nAldiginizin kategorisi: ");
	    		scanf("%s",girdi.kategori);
	    		printf("\nAldiginiziz fiyati: ");
	    		scanf("%f",&girdi.fiyat);
	    		printf("\nAldiginiz tarihi giriniz: ");
	    		scanf("%s",girdi.tarih);
	    		FILE *dosya;
				dosya = fopen("butce.txt",  "a");
				fprintf(dosya, "%s %s %.2f %s\n", girdi.aciklama,girdi.kategori,girdi.fiyat,girdi.tarih);
				fclose(dosya);
				printf("-----Kayit Basarili-----");
				break;
			}
			
			case 2:{
				printf("------HARCAMA LISTESI------\n");
				FILE *dosya;
				char a;
				dosya = fopen("butce.txt",  "r");
				if(dosya == NULL){
					printf("Dosya bulunmamaktadir.");
					break;
				}
				else{
				while((a = fgetc(dosya)) != EOF){
					printf("%c", a);
				}
				printf("**************************");
				fclose(dosya);
				break;
			}
		  }
			
		    case 3:{
		    	char aciklama[60];
	            char kategori[50];
	            float fiyat;
	            char tarih[20];
	            float geneltoplam=0.0;
		    	printf("-----TOPLAM HARCAMA-----");
		    	FILE *dosya;
		    	dosya = fopen("butce.txt", "r");
		    	if(dosya == NULL){
					printf("Dosya bulunmamaktadir.");
				}
				else{
					while(fscanf(dosya, "%s %s %f %s",aciklama,kategori,&fiyat,tarih) != EOF){
						geneltoplam += fiyat;
					}
					printf("\n-----------------");
					printf("\nTOPLAM HARCAMA: %.2f TL",geneltoplam);
					printf("\n-----------------\n");
					
					fclose(dosya);
				}
				
				break;
			}
	
			case 4:
				printf("Cikis Yapiliyor......");
				return 0;
		}
	}
}
