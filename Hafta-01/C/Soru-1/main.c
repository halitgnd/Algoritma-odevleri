#include <stdio.h>

int main() {
  int i;
  int sayi_dizisi[10];
  for (i=0; i<10; i++) {
    printf("Bir sayı giriniz: ");
    if(scanf("%d", &sayi_dizisi[i]) != 1){
      printf("Geçersiz sayı girdiniz.\n");
      return 1;
    }
  }
  for (i=0; i<10; i++) {
    printf("Dizinin %d.terimi= %d\n",i,sayi_dizisi[i]);
  }
  return 0;
}

