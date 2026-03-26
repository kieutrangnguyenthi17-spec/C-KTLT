#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, tmp;
    printf("Nhap do dai mang: ");
    scanf("%d", &n);
    //
    int* a = (int*) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    // Nhap gia tri
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    // Xuat gia tri
    printf("The input array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(a+i)>*(a+j)){
                tmp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=tmp;

            }
        }
    }
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");

    // Giải phóng bộ nhớ
    free(a);

    return 0;
}
