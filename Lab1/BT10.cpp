#include<stdio.h>
#include <stdlib.h>

int tong(int **a, int n){
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        t+=a[i][j];
    }
  }
    return t;
}
    
int tich(int **a, int n)
{
    int th=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        th*=a[i][j];}
    }
        return th;
}
int main()
{
    int n, **a;
    printf("Nhap n: ");
    scanf("%d",&n);
    a=(int**)malloc(n*sizeof(int*));
        for(int i=0;i<n;i++){
            *(a+i)=(int*)malloc(n*sizeof(int));
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Nhap phan tu cua mang a[%d][%d]=",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("mang vua nhap: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nTong mang = %d\n ",tong(a,n));
    printf("\nTich mang = %d\n ",tich(a,n));

    for(int i=0;i<n;i++){
        free(a[i]);
    }
    free(a);
    return 0;
}



