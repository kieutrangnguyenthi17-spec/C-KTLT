#include<stdio.h>
int main(){
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    int a[n];
    printf("Nhap mang:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                printf("%d",a[k]);
            }
                    printf("\n");
        }
    }
    return 0;
}