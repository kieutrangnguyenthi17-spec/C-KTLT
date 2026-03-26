#include<stdio.h>
int main(){
    int a[5]={1,2,3,4,5,}, n=5;
    int *a_pr = a;
    printf("Mang (a): [");
    for (int i=0;i<n;i++){
        printf(" %d", *(a+i)); // printf("%d", *(a_ptr+1));
    }
    printf("]");
}