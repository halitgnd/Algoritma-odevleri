#include <stdio.h>

static void BubbleSort(int arr[],int n){
    int temp=0;
    int swapped=0;
    for(int i=0; i<n-1 ;i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}
 static void PrintArray(int arr[],int size) {
    printf("Liste: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int fiyatlar[5]={10,20,40,50,30};
    int n=sizeof(fiyatlar)/sizeof(fiyatlar[0]);
    PrintArray(fiyatlar, n);
    BubbleSort(fiyatlar, n);
    printf("Sıralanmış ");
    PrintArray(fiyatlar, n);
    return 0;
}
