#include <stdio.h>

int main() {
    int sayi;
    int notlar[6]={65,80,45,90,70,55};
    printf("Araycağınız bir notu giriniz: ");
    scanf("%d",&sayi);
    for (int i=0;i<6;i++) {
        if (sayi==notlar[i]) {
            printf("aradığınız notun '%d' sırası %d\n",sayi,i+1);
            return 0;
        }
    }
    printf("Aradığınız not '%d' bulunamadı!\n",sayi);

    return 0;
}
