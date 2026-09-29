#include <stdio.h>

int main() {
    int sayi;
    int gecici;
    long ters_sayi=0;
    printf("Bir sayı giriniz: ");
    if (scanf("%d", &sayi)!=1) {
        printf("Lütfen geçerli bir sayı giriniz!!\n");
        return 1;
    }
   if (sayi<0) {
       printf("Negatif sayıların polindrom olmasından bahsedilmez.");
       return 0;
   }
    gecici = sayi;
    while (gecici>0){
        int kalan = gecici %10;
        ters_sayi = ters_sayi *10+ kalan;
        gecici = gecici /10;
    }
    if(ters_sayi==sayi) {
        printf("Girdiğiniz sayı (%d) bir polindrom sayıdır.", sayi);
    }
    else {
        printf("Girdiğiniz sayı (%d) bir polindrom sayı değildir.", sayi);
    }


    return 0;
}